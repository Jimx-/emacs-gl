#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <cstdlib>
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static void extract_vecn(emacs_env* env, emacs_value vec, unsigned int n,
                         float* vals)
{
    for (int i = 0; i < n; i++)
        vals[i] = extract_double(env, env->vec_get(env, vec, i));
}

static glm::mat4 extract_mat4(emacs_env* env, emacs_value mat)
{
    float vals[16];

    extract_vecn(env, mat, 16, vals);
    return glm::make_mat4(vals);
}

static emacs_value make_mat4(emacs_env* env, const glm::mat4& mat)
{
    emacs_value vector = env->intern(env, "vector");
    emacs_value array[16];
    const float* ptr = glm::value_ptr(mat);

    for (int i = 0; i < 16; i++) {
        array[i] = env->make_float(env, ptr[i]);
    }

    return env->funcall(env, vector, 16, array);
}

static emacs_value Fglm_translate(emacs_env* env, ptrdiff_t nargs,
                                  emacs_value args[], void* data) EMACS_NOEXCEPT
{
    auto m = extract_mat4(env, args[0]);
    float v[3];
    extract_vecn(env, args[1], 3, v);

    return make_mat4(env, glm::translate(m, glm::make_vec3(v)));
}

static emacs_value Fglm_rotate(emacs_env* env, ptrdiff_t nargs,
                               emacs_value args[], void* data) EMACS_NOEXCEPT
{
    auto m = extract_mat4(env, args[0]);
    float angle = extract_double(env, args[1]);
    float v[3];
    extract_vecn(env, args[2], 3, v);

    return make_mat4(env, glm::rotate(m, angle, glm::make_vec3(v)));
}

static emacs_value Fglm_scale(emacs_env* env, ptrdiff_t nargs,
                              emacs_value args[], void* data) EMACS_NOEXCEPT
{
    auto m = extract_mat4(env, args[0]);
    float v[3];
    extract_vecn(env, args[1], 3, v);

    return make_mat4(env, glm::scale(m, glm::make_vec3(v)));
}

static emacs_value Fglm_look_at(emacs_env* env, ptrdiff_t nargs,
                                emacs_value args[], void* data) EMACS_NOEXCEPT
{
    float eye[3], center[3], up[3];

    extract_vecn(env, args[0], 3, eye);
    extract_vecn(env, args[1], 3, center);
    extract_vecn(env, args[2], 3, up);

    auto mat = glm::lookAt(glm::make_vec3(eye), glm::make_vec3(center),
                           glm::make_vec3(up));

    return make_mat4(env, mat);
}

static emacs_value Fglm_ortho(emacs_env* env, ptrdiff_t nargs,
                              emacs_value args[], void* data) EMACS_NOEXCEPT
{
    float left = extract_double(env, args[0]);
    float right = extract_double(env, args[1]);
    float bottom = extract_double(env, args[2]);
    float top = extract_double(env, args[3]);
    float near = extract_double(env, args[4]);
    float far = extract_double(env, args[5]);

    return make_mat4(env, glm::ortho(left, right, bottom, top, near, far));
}

static emacs_value Fglm_frustum(emacs_env* env, ptrdiff_t nargs,
                                emacs_value args[], void* data) EMACS_NOEXCEPT
{
    float left = extract_double(env, args[0]);
    float right = extract_double(env, args[1]);
    float bottom = extract_double(env, args[2]);
    float top = extract_double(env, args[3]);
    float near = extract_double(env, args[4]);
    float far = extract_double(env, args[5]);

    return make_mat4(env, glm::frustum(left, right, bottom, top, near, far));
}

static emacs_value Fglm_perspective(emacs_env* env, ptrdiff_t nargs,
                                    emacs_value args[],
                                    void* data) EMACS_NOEXCEPT
{
    float fov = extract_double(env, args[0]);
    float aspect = extract_double(env, args[1]);
    float near = extract_double(env, args[2]);
    float far = extract_double(env, args[3]);

    return make_mat4(env, glm::perspective(fov, aspect, near, far));
}

extern "C"
{
    void glm_init(emacs_env* env)
    {
        DEFUN("glm-translate", Fglm_translate, 2, 2,
              "Builds a translation 4 * 4 matrix created from a vector of 3 "
              "components.\n",
              NULL);
        DEFUN("glm-rotate", Fglm_rotate, 3, 3,
              "Builds a rotation 4 * 4 matrix created from an axis vector and "
              "an angle expressed in degrees.\n",
              NULL);
        DEFUN("glm-scale", Fglm_scale, 2, 2,
              "Builds a scale 4 * 4 matrix created from 3 scalars.\n", NULL);
        DEFUN("glm-look-at", Fglm_look_at, 3, 3,
              "Build a look at view matrix.\n", NULL);
        DEFUN("glm-ortho", Fglm_ortho, 6, 6,
              "Creates a matrix for an orthographic parallel viewing volume.\n",
              NULL);
        DEFUN("glm-frustum", Fglm_frustum, 6, 6, "Creates a frustum matrix.\n",
              NULL);
        DEFUN("glm-perspective", Fglm_perspective, 4, 4,
              "Creates a matrix for a symetric perspective-view frustum.\n",
              NULL);
    }
}
