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


def generate_int_param(val):
    return f'extract_integer(env, {val})'


def generate_double_param(val):
    return f'extract_double(env, {val})'


PARAM_INITIALIZERS = dict(
    GLint=generate_int_param,
    GLuint=generate_int_param,
    GLsizei=generate_int_param,
    GLshort=generate_int_param,
    GLushort=generate_int_param,
    GLboolean=generate_int_param,
    GLbyte=generate_int_param,
    GLubyte=generate_int_param,
    GLbitfield=generate_int_param,
    GLenum=generate_int_param,
    GLfloat=generate_double_param,
    GLdouble=generate_double_param,
)


def build_int_param(val):
    return f'env->make_integer(env, {val})'


def build_float_param(val):
    return f'env->make_float(env, {val})'


VALUE_BUILDERS = dict(
    GLint=build_int_param,
    GLuint=build_int_param,
    GLsizei=build_int_param,
    GLshort=build_int_param,
    GLushort=build_int_param,
    GLboolean=build_int_param,
    GLbyte=build_int_param,
    GLubyte=build_int_param,
    GLbitfield=build_int_param,
    GLenum=build_int_param,
    GLfloat=build_float_param,
    GLdouble=build_float_param,
)


def generate_array(val, name, type, length, initializer, builder):
    idx = f'_{name}_idx'
    init = f'\t{type}* {name} = ({type}*) calloc({length}, sizeof({type}));\n'
    init += '\t{\n'
    init += f'\t\tint {idx};\n'
    init += f'\t\tfor ({idx} = 0; {idx} < {length}; {idx}++)\n'
    ref = f'env->vec_get(env, {val}, {idx})'
    init += f'\t\t\t{name}[{idx}] = {initializer(ref)};\n'
    init += '\t}\n'

    fini = '\t{\n'
    fini += f'\t\tint {idx};\n'
    fini += f'\t\tfor ({idx} = 0; {idx} < {length}; {idx}++)\n'
    ref = f'{name}[{idx}]'
    fini += f'\t\t\tenv->vec_set(env, {val}, {idx}, {builder(ref)});\n'
    fini += '\t}\n'
    fini += f'\tfree({name});\n'

    return init, fini


def generate_func(name, command):
    func_name = command_name(name)

    code = f'emacs_value F{func_name}(emacs_env* env, ptrdiff_t nargs, emacs_value args[], void* data)\n'
    code += '{\n'

    params = []
    dtors = []
    for i, param in enumerate(command.iter(tag='param')):
        length = param.attrib.get('len')

        ptype = param.findall('ptype')[0].text
        pname = param.findall('name')[0].text

        initializer = PARAM_INITIALIZERS.get(ptype)
        if initializer is None:
            print(f'Unsupported type: {ptype}')
            raise NotImplementedError
        builder = VALUE_BUILDERS.get(ptype)

        if length is None:
            code += f'\t{ptype} {pname} = '
            code += initializer(f'args[{i}]')
            code += ';\n'
        else:
            if length.count('COMPSIZE') > 0: raise NotImplementedError
            init, fini = generate_array(f'args[{i}]', pname, ptype, length,
                                        initializer, builder)
            code += init
            dtors.append(fini)

        params.append(pname)

    arg_list = ', '.join(params)
    code += f'\t{name}({arg_list});\n'

    code += ''.join(dtors)

    code += '\treturn Qnil;\n'
    code += '}\n\n'

    return code, params


def generate_funcs(feature, commands, version):
    with open(f'inc/glfuncs_{version}.inc', 'w') as fout:
        with open(f'inc/glfuncs_defun_{version}.inc', 'w') as fout_defun:
            for require in feature.iter(tag='require'):
                for elem in require.iter(tag='command'):
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
