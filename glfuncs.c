#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <glad/glad.h>
#include <stdlib.h>

#include "inc/glfuncs_1_0.inc"
#include "inc/glfuncs_1_1.inc"
#include "inc/glfuncs_1_2.inc"
#include "inc/glfuncs_1_3.inc"
#include "inc/glfuncs_1_4.inc"
#include "inc/glfuncs_1_5.inc"
#include "inc/glfuncs_2_0.inc"
#include "inc/glfuncs_2_1.inc"
#include "inc/glfuncs_3_0.inc"
/* #include "inc/glfuncs_3_1.inc" */
#include "inc/glfuncs_3_2.inc"
#include "inc/glfuncs_3_3.inc"

emacs_value Fgl_load(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                     void* data)
{
    gladLoadGL();

    return Qnil;
}

emacs_value Fgl_shader_source(emacs_env* env, ptrdiff_t nargs,
                              emacs_value args[], void* data)
{
    GLuint shader = extract_integer(env, args[0]);
    GLsizei count = extract_integer(env, args[1]);
    int i;

    const GLchar** sources = calloc(count, sizeof(GLchar*));

    for (i = 0; i < count; i++)
        sources[i] =
            copy_string_contents(env, env->vec_get(env, args[2], i), NULL);

    glShaderSource(shader, count, sources, NULL);

    for (i = 0; i < count; i++)
        free((void*)sources[i]);

    free(sources);

    return Qnil;
}

emacs_value Fgl_get_shaderiv(emacs_env* env, ptrdiff_t nargs,
                             emacs_value args[], void* data)
{
    GLuint shader = extract_integer(env, args[0]);
    GLenum pname = extract_integer(env, args[1]);
    GLint* params;
    int i, count;

    switch (pname) {
    case GL_COMPILE_STATUS:
        count = 1;
        break;
    default:
        count = 1;
        break;
    }

    params = calloc(count, sizeof(GLint));

    glGetShaderiv(shader, pname, params);

    for (i = 0; i < count; i++)
        env->vec_set(env, args[2], i, env->make_integer(env, params[i]));

    free(params);
    return Qnil;
}

emacs_value Fgl_get_programiv(emacs_env* env, ptrdiff_t nargs,
                              emacs_value args[], void* data)
{
    GLuint program = extract_integer(env, args[0]);
    GLenum pname = extract_integer(env, args[1]);
    GLint* params;
    int i, count;

    switch (pname) {
    case GL_LINK_STATUS:
        count = 1;
        break;
    default:
        count = 1;
        break;
    }

    params = calloc(count, sizeof(GLint));

    glGetProgramiv(program, pname, params);

    for (i = 0; i < count; i++)
        env->vec_set(env, args[2], i, env->make_integer(env, params[i]));

    free(params);
    return Qnil;
}

emacs_value Fgl_buffer_data(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                            void* data)
{
    GLenum target = extract_integer(env, args[0]);
    GLsizeiptr size = extract_integer(env, args[1]);
    GLenum usage = extract_integer(env, args[3]);
    GLfloat* buf;
    int i, count = env->vec_size(env, args[2]);

    buf = calloc(count, sizeof(GLfloat));

    for (i = 0; i < count; i++) {
        buf[i] = extract_double(env, env->vec_get(env, args[2], i));
    }

    glBufferData(target, count * sizeof(GLfloat), buf, usage);

    free(buf);
    return Qnil;
}

emacs_value Fgl_vertex_attrib_pointer(emacs_env* env, ptrdiff_t nargs,
                                      emacs_value args[], void* data)
{
    GLuint index = extract_integer(env, args[0]);
    GLint size = extract_integer(env, args[1]);
    GLenum type = extract_integer(env, args[2]);
    GLboolean normalized = extract_integer(env, args[3]);
    GLsizei stride = extract_integer(env, args[4]);
    const void* pointer = (const void*)(uintptr_t)extract_integer(env, args[5]);

    glVertexAttribPointer(index, size, type, normalized, stride, pointer);

    return Qnil;
}

void glfuncs_init(emacs_env* env)
{
    DEFUN("gl-load", Fgl_load, 0, 0,
          "(gl-load).\n"
          "Load OpenGL function pointers.",
          NULL);

#include "inc/glfuncs_defun_1_0.inc"
#include "inc/glfuncs_defun_1_1.inc"
#include "inc/glfuncs_defun_1_2.inc"
#include "inc/glfuncs_defun_1_3.inc"
#include "inc/glfuncs_defun_1_4.inc"
#include "inc/glfuncs_defun_1_5.inc"
#include "inc/glfuncs_defun_2_0.inc"
#include "inc/glfuncs_defun_2_1.inc"
#include "inc/glfuncs_defun_3_0.inc"
/* #include "inc/glfuncs_defun_3_1.inc" */
#include "inc/glfuncs_defun_3_2.inc"
#include "inc/glfuncs_defun_3_3.inc"
}
