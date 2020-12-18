import re
try:
    import xml.etree.cElementTree as ET
except ImportError:
    import xml.etree.ElementTree as ET


def command_name(name, sep='_'):
    return re.sub(r'(?<!^)(?=[A-Z])', sep, name).lower()


def constant_name(name):
    return name.replace('_', '-')


def generate_enums(feature, version):
    with open(f'inc/glenums_{version}.inc', 'w') as fout:
        for elem in feature.iter(tag='enum'):
            name = elem.attrib['name']
            const_name = constant_name(name)

            fout.write(
                f'defconsti(env, "{const_name}", (GLenum) {name}, "{name}");\n'
            )


def generate_int_param(ptype):
    def inner(idx, name):
        return f'\t{ptype} {name} = extract_integer(env, args[{idx}]);\n'

    return inner


def generate_GLenum_param(idx, name):
    return f'\tGLenum {name} = extract_integer(env, args[{idx}]);\n'


def generate_GLfloat_param(idx, name):
    return f'\tGLfloat {name} = extract_float(env, args[{idx}]);\n'


def generate_double_param(type):
    def inner(idx, name):
        return f'\t{type} {name} = extract_double(env, args[{idx}]);\n'

    return inner


PARAM_GENERATOR = dict(GLint=generate_int_param('GLint'),
                       GLuint=generate_int_param('GLuint'),
                       GLsizei=generate_int_param('GLsizei'),
                       GLshort=generate_int_param('GLshort'),
                       GLushort=generate_int_param('GLushort'),
                       GLboolean=generate_int_param('GLboolean'),
                       GLbyte=generate_int_param('GLbyte'),
                       GLubyte=generate_int_param('GLubyte'),
                       GLbitfield=generate_int_param('GLbitfield'),
                       GLenum=generate_GLenum_param,
                       GLfloat=generate_double_param('GLfloat'),
                       GLdouble=generate_double_param('GLdouble'))


def generate_func(name, command):
    func_name = command_name(name)

    code = f'emacs_value F{func_name}(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)\n'
    code += '{\n'

    params = []
    for i, param in enumerate(command.iter(tag='param')):
        if param.attrib.get('len') is not None: raise NotImplementedError

        ptype = param.findall('ptype')[0].text
        pname = param.findall('name')[0].text

        generator = PARAM_GENERATOR.get(ptype)
        if generator is None:
            print(f'Unsupported type: {ptype}')
            raise NotImplementedError

        code += generator(i, pname)
        params.append(pname)

    arg_list = ', '.join(params)
    code += f'\t{name}({arg_list});\n'
    code += '\treturn Qnil;\n'
    code += '}\n\n'

    return code, params


def generate_funcs(feature, commands, version):
    with open(f'inc/glfuncs_{version}.inc', 'w') as fout:
        with open(f'inc/glfuncs_defun_{version}.inc', 'w') as fout_defun:
            for elem in feature.iter(tag='command'):
                name = elem.attrib['name']

                command = commands[name]
                try:
                    code, params = generate_func(name, command)
                    fout.write(code)

                    emacs_name = command_name(name, '-')
                    param_list = ' '.join(params)
                    defun = f'DEFUN("{emacs_name}", F{command_name(name)}, {len(params)}, {len(params)}, "({emacs_name} {param_list})\\n{name}.", NULL);\n'

                    fout_defun.write(defun)
                except:
                    print(f'Unsupported command: {name}')


if __name__ == '__main__':
    spec = ET.ElementTree(file='gl.xml')
    command_list = spec.findall('commands')[0]

    commands = dict()
    for command in command_list.iter(tag='command'):
        name = command.findall('.//name')[0].text
        commands[name] = command

    versions = {
        '1_0',
        '1_1',
        '1_2',
        '1_3',
        '1_4',
        '1_5',
        '2_0',
        '2_1',
        '3_0',
        '3_1',
        '3_2',
        '3_3',
    }

    for feature in spec.iter(tag='feature'):
        if feature.attrib['api'] != 'gl': continue

        version = feature.attrib['name'][len('GL_VERSION_'):]
        if version not in versions: continue

        generate_enums(feature, version)
        generate_funcs(feature, commands, version)
