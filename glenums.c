#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <glad/glad.h>

void glenums_init(emacs_env* env)
{
    #include "inc/glenums_1_0.inc"
    #include "inc/glenums_1_1.inc"
    #include "inc/glenums_1_2.inc"
    #include "inc/glenums_1_3.inc"
    #include "inc/glenums_1_4.inc"
    #include "inc/glenums_1_5.inc"
    #include "inc/glenums_2_0.inc"
    #include "inc/glenums_2_1.inc"
    #include "inc/glenums_3_0.inc"
    #include "inc/glenums_3_1.inc"
    #include "inc/glenums_3_2.inc"
    #include "inc/glenums_3_3.inc"
}
