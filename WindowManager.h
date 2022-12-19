#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;
/*
* Менеджер, отвечающий за создание и изменение окна.
*/
class WindowManager
{

public:

    /*
    * Создаёт instance вашего класса
    */
    WindowManager()
    {
        instance = this;
    }

    ~WindowManager()
    {
        destroy();
    }

    /*
    * @return instance WindowManager
    */
    WindowManager* getInstance()
    {
        return instance;
    }

    void registerEventHandler() {

    }

    /*
    * Инициализирут и открывает окно
    * @param window_name - имя окна
    * @param height - высота окна в пикселях
    * @param width - ширина окна в пикселях
    */
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

    /*
    * Унечтожает окно
    */
    void destroy() {
        main_window = NULL;
        instance = NULL;
    }

    /*
    * Получаете текущее окно
    */
    GLFWwindow* getWindow() {
        return main_window;
    }

private:
    GLFWwindow* main_window;
    WindowManager* instance;

};

