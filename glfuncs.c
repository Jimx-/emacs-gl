#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <glad/glad.h>

emacs_value Fgl_load(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                     void* data)
{
    gladLoadGL();

    return Qnil;
}

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
/* #include "inc/glfuncs_3_2.inc" */
/* #include "inc/glfuncs_3_3.inc" */

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
    /* #include "inc/glfuncs_defun_3_2.inc" */
    /* #include "inc/glfuncs_defun_3_3.inc" */
}
