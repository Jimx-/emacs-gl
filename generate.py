try:
    import xml.etree.cElementTree as ET
except ImportError:
    import xml.etree.ElementTree as ET


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


if __name__ == '__main__':
    spec = ET.ElementTree(file='gl.xml')
    commands = spec.findall('commands')[0]

    versions = {'1_0'}

    for feature in spec.iter(tag='feature'):
        if feature.attrib['api'] != 'gl': continue

        version = feature.attrib['name'][len('GL_VERSION_'):]
        if version not in versions: continue

        generate_enums(feature, version)
