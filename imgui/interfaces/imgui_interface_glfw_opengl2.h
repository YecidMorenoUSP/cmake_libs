#ifndef IMGUI_INTERFACE_GLFW_OPENGL2
#define IMGUI_INTERFACE_GLFW_OPENGL2

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl2.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#include <GLFW/glfw3.h>
#include <unistd.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void
glfw_error_callback(int error, const char *description);

class ImGUI_Template
{
private:
protected:
    GLFWwindow *window;
    ImVec4 clear_color;

public:
    ImGUI_Template(void);
    ~ImGUI_Template();

    int init(int _width = 800, int _height = 600, ImVec4 _clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f));

    int run();

    virtual int preloop();
    virtual int loop();
    virtual int posloop();
};

#endif