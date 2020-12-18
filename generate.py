try:
    import xml.etree.cElementTree as ET
except ImportError:
    import xml.etree.ElementTree as ET


def constant_name(name):
    return name.replace('_', '-')


def generate_enums(spec):
    with open('glenums.inc', 'w') as fout:
        for elem in spec.iter(tag='enum'):
            name = elem.attrib['name']
            const_name = constant_name(name)

            fout.write(f'#if defined({name})\n')
            fout.write(
                f'defconsti(env, "{const_name}", (GLenum) {name}, "{name}");\n'
            )
            fout.write(f'#endif\n')


if __name__ == '__main__':
    spec = ET.ElementTree(file='gl.xml')

    generate_enums(spec)
