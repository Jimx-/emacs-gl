#include "emacs-module-helpers.h"
#include "emacs-module.h"
#include <cstdlib>
#include <glad/glad.h>

#include "imgui.h"
#include "imgui_impl_opengl3.h"

emacs_value Qdark;
emacs_value Qclassic;
emacs_value Qpress;
emacs_value Qrelease;

static emacs_value Fgl_helper_ui_init(emacs_env* env, ptrdiff_t nargs,
                                      emacs_value args[],
                                      void* data) EMACS_NOEXCEPT
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

    for (int i = 0; i < IM_ARRAYSIZE(io.KeyMap); i++)
        io.KeyMap[i] = i;

    return Qnil;
}

static emacs_value Fgl_helper_ui_new_frame(emacs_env* env, ptrdiff_t nargs,
                                           emacs_value args[],
                                           void* data) EMACS_NOEXCEPT
{
    float delta = extract_double(env, args[0]);

    ImGuiIO& io = ImGui::GetIO();
    io.DeltaTime = delta;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    return Qnil;
}

static emacs_value Fgl_helper_ui_render(emacs_env* env, ptrdiff_t nargs,
                                        emacs_value args[],
                                        void* data) EMACS_NOEXCEPT
{
    ImGuiIO& io = ImGui::GetIO();

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    memset(io.KeysDown, 0, sizeof(io.KeysDown));

    return Qnil;
}

static emacs_value Fgl_helper_ui_cursor_pos_callback(emacs_env* env,
                                                     ptrdiff_t nargs,
                                                     emacs_value args[],
                                                     void* data) EMACS_NOEXCEPT
{
    ImGuiIO& io = ImGui::GetIO();
    double x = extract_double(env, args[0]);
    double y = extract_double(env, args[1]);

    io.MousePos.x = x;
    io.MousePos.y = y;

    return Qnil;
}

static emacs_value
Fgl_helper_ui_mouse_button_callback(emacs_env* env, ptrdiff_t nargs,
                                    emacs_value args[],
                                    void* data) EMACS_NOEXCEPT
{
    ImGuiIO& io = ImGui::GetIO();
    int button = extract_integer(env, args[0]);
    emacs_value action = args[1];

    if (button > 0) io.MouseDown[button - 1] = env->eq(env, action, Qpress);

    return Qnil;
}

static emacs_value Fgl_helper_ui_send_key(emacs_env* env, ptrdiff_t nargs,
                                          emacs_value args[],
                                          void* data) EMACS_NOEXCEPT
{
    ImGuiIO& io = ImGui::GetIO();
    char* str = copy_string_contents(env, args[0], NULL);
    char key = '\0';

    if (!strcmp(str, "SPC")) {
        key = ' ';
    } else if (!strcmp(str, "<backspace>")) {
        io.KeysDown[ImGuiKey_Backspace] = true;
    } else if (!strcmp(str, "<tab>")) {
        io.KeysDown[ImGuiKey_Tab] = true;
    } else if (!strcmp(str, "<return>")) {
        io.KeysDown[ImGuiKey_Enter] = true;
    } else if (!strcmp(str, "<left>")) {
        io.KeysDown[ImGuiKey_LeftArrow] = true;
    } else if (!strcmp(str, "<right>")) {
        io.KeysDown[ImGuiKey_RightArrow] = true;
    } else if (!strcmp(str, "<up>")) {
        io.KeysDown[ImGuiKey_UpArrow] = true;
    } else if (!strcmp(str, "<down>")) {
        io.KeysDown[ImGuiKey_DownArrow] = true;
    } else if (!strcmp(str, "<delete>")) {
        io.KeysDown[ImGuiKey_Delete] = true;
    } else if (!strcmp(str, "<home>")) {
        io.KeysDown[ImGuiKey_Home] = true;
    } else if (!strcmp(str, "<end>")) {
        io.KeysDown[ImGuiKey_End] = true;
    } else if (!strcmp(str, "<escape>")) {
        io.KeysDown[ImGuiKey_Escape] = true;
    } else {
        key = *str;
    }

    free(str);

    if (key) io.AddInputCharacter(key);

    return Qnil;
}

static emacs_value Fgl_helper_ui_begin_window(emacs_env* env, ptrdiff_t nargs,
                                              emacs_value args[],
                                              void* data) EMACS_NOEXCEPT
{
    char* title = copy_string_contents(env, args[0], NULL);
    ImGui::Begin(title);
    ImGui::SetWindowSize(ImVec2(0, 0));
    free(title);
    return Qnil;
}

static emacs_value Fgl_helper_ui_text(emacs_env* env, ptrdiff_t nargs,
                                      emacs_value args[],
                                      void* data) EMACS_NOEXCEPT
{
    char* text = copy_string_contents(env, args[0], NULL);
    ImGui::Text(text);
    free(text);
    return Qnil;
}

static emacs_value Fgl_helper_ui_button(emacs_env* env, ptrdiff_t nargs,
                                        emacs_value args[],
                                        void* data) EMACS_NOEXCEPT
{
    char* text = copy_string_contents(env, args[0], NULL);
    bool clicked = ImGui::Button(text);
    free(text);

    if (clicked) return Qt;
    return Qnil;
}

static emacs_value Fgl_helper_ui_input_text(emacs_env* env, ptrdiff_t nargs,
                                            emacs_value args[],
                                            void* data) EMACS_NOEXCEPT
{
    char buf[4096];
    char* text = copy_string_contents(env, args[0], NULL);
    char* str = copy_string_contents(env, args[1], NULL);

    buf[0] = '\0';
    strncat(buf, str, sizeof(buf) - 1);
    free(str);

    ImGui::InputText(text, buf, sizeof(buf));
    free(text);

    return env->make_string(env, buf, (ptrdiff_t)strlen(buf));
}

static emacs_value Fgl_helper_ui_slider_float(emacs_env* env, ptrdiff_t nargs,
                                              emacs_value args[],
                                              void* data) EMACS_NOEXCEPT
{
    char* text = copy_string_contents(env, args[0], NULL);
    float value = extract_double(env, args[1]);
    float v_min = extract_double(env, args[2]);
    float v_max = extract_double(env, args[3]);

    if (text) {
        ImGui::SliderFloat(text, &value, v_min, v_max);
        free(text);
    }

    return env->make_float(env, value);
}

static emacs_value Fgl_helper_ui_end_window(emacs_env* env, ptrdiff_t nargs,
                                            emacs_value args[],
                                            void* data) EMACS_NOEXCEPT
{
    ImGui::End();
    return Qnil;
}

extern "C"
{
    void gl_helper_gui_init(emacs_env* env)
    {
        Qdark = env->make_global_ref(env, env->intern(env, "dark"));
        Qclassic = env->make_global_ref(env, env->intern(env, "classic"));

        Qpress = env->make_global_ref(env, env->intern(env, "press"));
        Qrelease = env->make_global_ref(env, env->intern(env, "release"));

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
        DEFUN("gl-helper-ui-cursor-pos-callback",
              Fgl_helper_ui_cursor_pos_callback, 2, 2,
              "Process cursor position update event.\n", NULL);
        DEFUN("gl-helper-ui-mouse-button-callback",
              Fgl_helper_ui_mouse_button_callback, 2, 2,
              "Process mouse button event.\n", NULL);
        DEFUN("gl-helper-ui-send-key", Fgl_helper_ui_send_key, 4, 4,
              "Add a key to the GUI input buffer.\n", NULL);

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
        DEFUN("gl-helper-ui-input-text", Fgl_helper_ui_input_text, 2, 2,
              "Display a text input on the current window.\n"
              "The argument ARG1 is the label to display",
              NULL);
        DEFUN("gl-helper-ui-slider-float", Fgl_helper_ui_slider_float, 4, 4,
              "Display a slider on the current window.\n"
              "The argument ARG1 is the label to display",
              NULL);
    }
}
