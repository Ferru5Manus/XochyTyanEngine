#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

class WindowManager
{

public:
    void registerEventHandler() {

    }

	void init(char* window_name, int width, int height) {

        if (!glfwInit())
            return;
        main_window = glfwCreateWindow(width, height, window_name, NULL, NULL);
        if (!main_window)
        {
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(main_window);

        while (main_window != NULL && !glfwWindowShouldClose(main_window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(main_window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
	}

    void destroy() {
        main_window = NULL;
    }

    GLFWwindow* getWindow() {
        return main_window;
    }

private:
    GLFWwindow* main_window;

};

