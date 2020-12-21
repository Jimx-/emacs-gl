#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <glad/glad.h>

int plugin_is_GPL_compatible;

extern void glenums_init(emacs_env* env);
extern void glfuncs_init(emacs_env* env);

extern void gl_helper_texture_init(emacs_env* env);
extern void gl_helper_gui_init(emacs_env* env);

int emacs_module_init(struct emacs_runtime* ert)
{
    emacs_env* env = ert->get_environment(ert);

    Qt = env->make_global_ref(env, env->intern(env, "t"));
    Qnil = env->make_global_ref(env, env->intern(env, "nil"));

    glenums_init(env);
    glfuncs_init(env);

    gl_helper_texture_init(env);
    gl_helper_gui_init(env);

    provide(env, "gl-module");
    return 0;
}
