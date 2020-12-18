#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <glad/glad.h>

#include "glfuncs.h"

emacs_value Fgl_load(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                     void* data)
{
    gladLoadGL();

    return Qnil;
}

emacs_value Fgl_clear_color(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                            void* data)
{
    double r = extract_double(env, args[0]);
    double g = extract_double(env, args[1]);
    double b = extract_double(env, args[2]);
    double alpha = extract_double(env, args[4]);

    glClearColor(r, g, b, alpha);

    return Qnil;
}

emacs_value Fgl_clear(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                      void* data)
{
    int mask = extract_integer(env, args[0]);

    glClear(mask);

    return Qnil;
}

emacs_value Fgl_matrix_mode(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                            void* data)
{
    int mode = extract_integer(env, args[0]);

    glMatrixMode(mode);

    return Qnil;
}

emacs_value Fgl_load_identity(emacs_env* env, ptrdiff_t nargs,
                              emacs_value args[], void* data)
{
    glLoadIdentity();

    return Qnil;
}

emacs_value Fgl_begin(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                      void* data)
{
    int mode = extract_integer(env, args[0]);

    glBegin(mode);

    return Qnil;
}

emacs_value Fgl_end(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                    void* data)
{
    glEnd();

    return Qnil;
}

emacs_value Fgl_color_3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                         void* data)
{
    double r = extract_double(env, args[0]);
    double g = extract_double(env, args[1]);
    double b = extract_double(env, args[2]);

    glColor3f(r, g, b);

    return Qnil;
}

emacs_value Fgl_vertex_3f(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                          void* data)
{
    double x = extract_double(env, args[0]);
    double y = extract_double(env, args[1]);
    double z = extract_double(env, args[2]);

    glVertex3f(x, y, z);

    return Qnil;
}

void glfuncs_init(emacs_env* env)
{
    /* GL constants. */
    defconsti(env, "GL-COLOR-BUFFER-BIT", GL_COLOR_BUFFER_BIT,
              "GL_COLOR_BUFFER_BIT");
    defconsti(env, "GL-DEPTH-BUFFER-BIT", GL_DEPTH_BUFFER_BIT,
              "GL_DEPTH_BUFFER_BIT");

    defconsti(env, "GL-MODELVIEW", GL_MODELVIEW, "GL_MODELVIEW");
    defconsti(env, "GL-PROJECTION", GL_PROJECTION, "GL_PROJECTION");

    defconsti(env, "GL-TRIANGLES", GL_TRIANGLES, "GL_TRIANGLES");
    defconsti(env, "GL-QUADS", GL_QUADS, "GL_QUADS");

    /* GL functions */
    DEFUN("gl-load", Fgl_load, 0, 0,
          "(gl-load).\n"
          "Load OpenGL function pointers.",
          NULL);

    DEFUN("gl-clear-color", Fgl_clear_color, 4, 4,
          "(gl-clear-color r g b alpha).\n"
          "glClearColor.",
          NULL);

    DEFUN("gl-clear", Fgl_clear, 1, 1,
          "(gl-clear mask).\n"
          "glClear.",
          NULL);

    DEFUN("gl-matrix-mode", Fgl_matrix_mode, 1, 1,
          "(gl-matrix-mode mode).\n"
          "glMatrixMode.",
          NULL);

    DEFUN("gl-load-identity", Fgl_load_identity, 0, 0,
          "(gl-load-identity).\n"
          "glLoadIdentity.",
          NULL);

    DEFUN("gl-begin", Fgl_begin, 1, 1,
          "(gl-begin mode).\n"
          "glBegin.",
          NULL);

    DEFUN("gl-end", Fgl_end, 0, 0,
          "(gl-end).\n"
          "glEnd.",
          NULL);

    DEFUN("gl-color-3f", Fgl_color_3f, 3, 3,
          "(gl-color-3f r g b).\n"
          "glColor3f.",
          NULL);

    DEFUN("gl-vertex-3f", Fgl_vertex_3f, 3, 3,
          "(gl-vertex-3f x y z).\n"
          "glVertex3f.",
          NULL);
}
