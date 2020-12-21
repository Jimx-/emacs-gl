#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <glad/glad.h>
#include <stdlib.h>

#include "imgui.h"
#include "imgui_impl_opengl3.h"

emacs_value Qdark;
emacs_value Qclassic;

extern "C"
{
    static emacs_value Fgl_helper_ui_init(emacs_env* env, ptrdiff_t nargs,
                                          emacs_value args[], void* data)
    {
        float width = extract_double(env, args[0]);
        float height = extract_double(env, args[1]);
        emacs_value style = args[2];

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize.x = width;
        io.DisplaySize.y = height;
        io.BackendPlatformName = "emacs";

        if (env->eq(env, style, Qdark))
            ImGui::StyleColorsDark();
        else
            ImGui::StyleColorsClassic();

        unsigned char* tex_pixels = NULL;
        int tex_w, tex_h;
        io.Fonts->GetTexDataAsRGBA32(&tex_pixels, &tex_w, &tex_h);

        ImGui_ImplOpenGL3_Init("#version 150");

        return Qnil;
    }

    static emacs_value Fgl_helper_ui_new_frame(emacs_env* env, ptrdiff_t nargs,
                                               emacs_value args[], void* data)
    {
        float delta = extract_double(env, args[0]);

        ImGuiIO& io = ImGui::GetIO();
        io.DeltaTime = delta;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        return Qnil;
    }

    static emacs_value Fgl_helper_ui_render(emacs_env* env, ptrdiff_t nargs,
                                            emacs_value args[], void* data)
    {
        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        return Qnil;
    }

    static emacs_value Fgl_helper_ui_begin_window(emacs_env* env,
                                                  ptrdiff_t nargs,
                                                  emacs_value args[],
                                                  void* data)
    {
        char* title = copy_string_contents(env, args[0], NULL);
        ImGui::Begin(title);
        ImGui::SetWindowSize(ImVec2(0, 0));
        free(title);
        return Qnil;
    }

    static emacs_value Fgl_helper_ui_text(emacs_env* env, ptrdiff_t nargs,
                                          emacs_value args[], void* data)
    {
        char* text = copy_string_contents(env, args[0], NULL);
        ImGui::Text(text);
        free(text);
        return Qnil;
    }

    static emacs_value Fgl_helper_ui_button(emacs_env* env, ptrdiff_t nargs,
                                            emacs_value args[], void* data)
    {
        char* text = copy_string_contents(env, args[0], NULL);
        bool clicked = ImGui::Button(text);
        free(text);

        if (clicked) return Qt;
        return Qnil;
    }

    static emacs_value Fgl_helper_ui_end_window(emacs_env* env, ptrdiff_t nargs,
                                                emacs_value args[], void* data)
    {
        ImGui::End();
        return Qnil;
    }

    void gl_helper_gui_init(emacs_env* env)
    {
        Qdark = env->make_global_ref(env, env->intern(env, "dark"));
        Qclassic = env->make_global_ref(env, env->intern(env, "classic"));

        DEFUN("gl-helper-ui-init", Fgl_helper_ui_init, 3, 3,
              "Initialize GUI context.\n"
              "The argument ARG1 is the width of the display area.\n"
              "The argument ARG2 is the height of the display area.\n"
              "The argument ARG3 is the style of GUI.  "
              "It can be 'dark or 'classic.\n",
              NULL);
        DEFUN(
            "gl-helper-ui-new-frame", Fgl_helper_ui_new_frame, 1, 1,
            "Prepare to draw GUI to a new frame.\n"
            "The argument ARG1 is the delta time elapsed since the last frame",
            NULL);
        DEFUN("gl-helper-ui-render", Fgl_helper_ui_render, 0, 0,
              "Render GUI to current frame.\n", NULL);

        DEFUN("gl-helper-ui-begin-window", Fgl_helper_ui_begin_window, 1, 1,
              "Create a new window.\n"
              "The argument ARG1 is the title of the window",
              NULL);
        DEFUN("gl-helper-ui-end-window", Fgl_helper_ui_end_window, 0, 0,
              "Finish the current window.\n", NULL);

        DEFUN("gl-helper-ui-text", Fgl_helper_ui_text, 1, 1,
              "Display text on the current window.\n"
              "The argument ARG1 is the text to display",
              NULL);
        DEFUN("gl-helper-ui-button", Fgl_helper_ui_button, 1, 1,
              "Display a button on the current window.\n"
              "The argument ARG1 is the caption of the button",
              NULL);
    }
}
