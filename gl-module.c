#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <glad/glad.h>

int plugin_is_GPL_compatible;

void glenums_init(emacs_env* env);
void glfuncs_init(emacs_env* env);

int emacs_module_init(struct emacs_runtime* ert)
{
    emacs_env* env = ert->get_environment(ert);

    Qt = env->make_global_ref(env, env->intern(env, "t"));
    Qnil = env->make_global_ref(env, env->intern(env, "nil"));

    glenums_init(env);
    glfuncs_init(env);

    provide(env, "gl-module");
    return 0;
}
