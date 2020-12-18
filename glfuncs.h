#ifndef _GLFUNCS_H
#define _GLFUNCS_H

#include "emacs-module-helpers.h"

emacs_value Fgl_clear_color(emacs_env* env, ptrdiff_t nargs, emacs_value args[],
                            void* data);

void glfuncs_init(emacs_env* env);

#endif
