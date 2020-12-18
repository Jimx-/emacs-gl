#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <glad/glad.h>

void glenums_init(emacs_env* env)
{
    #include "inc/glenums_1_0.inc"
}
