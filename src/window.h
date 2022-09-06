
#include <GLFW/glfw3.h>
#include <string>


class Window {

    private:
        int height, width;
        std::string name;
        static void framebuffer_resize(GLFWwindow* window, int width, int height);

    public:
        static Window window;
        GLFWwindow* glWindow;

        Window();
        ~Window();
        void loop();
        //Window get();

};
