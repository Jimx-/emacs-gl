#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <glad/glad.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb.h>
#include <stb_image.h>

struct texture_data {
    int width, height;
    GLenum target;
    GLuint id;
};

static void texture_finalize(void* object)
{
    struct texture_data* texture = object;
    glDeleteTextures(1, &texture->id);
    free(texture);
}

static emacs_value Fgl_helper_load_texture(emacs_env* env, ptrdiff_t nargs,
                                           emacs_value args[], void* data)
{
    GLuint tex_id;
    GLenum target = GL_TEXTURE_2D;
    int width, height, component;
    unsigned char* image;
    char* filename = copy_string_contents(env, args[0], NULL);
    struct texture_data* texture;

    texture = malloc(sizeof(*texture));
    memset(texture, 0, sizeof(*texture));

    glGenTextures(1, &tex_id);
    glBindTexture(target, tex_id);
    glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    image = stbi_load(filename, &width, &height, &component, 0);
    glTexImage2D(target, 0, GL_RGBA, width, height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, image);
    stbi_image_free(image);

    glBindTexture(target, 0);

    texture->id = tex_id;
    texture->target = target;
    texture->width = width;
    texture->height = height;

    free(filename);

    return env->make_user_ptr(env, texture_finalize, texture);
}

static emacs_value Fgl_helper_bind_texture(emacs_env* env, ptrdiff_t nargs,
                                           emacs_value args[], void* data)
{
    struct texture_data* texture = env->get_user_ptr(env, args[0]);

    glBindTexture(texture->target, texture->id);

    return Qnil;
}

void gl_helper_texture_init(emacs_env* env)
{
    DEFUN("gl-helper-load-texture", Fgl_helper_load_texture, 1,
          emacs_variadic_function, "Load texture from ARG1.", NULL);
    DEFUN("gl-helper-bind-texture", Fgl_helper_bind_texture, 1, 1,
          "Bind texture ARG1 to its target.", NULL);
}
