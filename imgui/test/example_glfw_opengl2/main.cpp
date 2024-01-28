#include "imgui_interface_glfw_opengl2.h"

class MyApp : public ImGUI_Template
{
private:
    /* data */
public:
    MyApp(){};
    ~MyApp(){};

    virtual int loop()
    {
        ImGui::ShowDemoWindow();
        return 0;
    }
};

int main(int N, char **A)
{

    MyApp myApp;
    myApp.init(500, 500);
    myApp.run();

    return 0;
}