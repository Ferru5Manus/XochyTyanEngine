#include <iostream>
#include "WindowManager.h"

int main(void)
{
    WindowManager WINDOW_MANAGER;
    char name[] = "SomeWindow";
    WINDOW_MANAGER.init(name, 500, 500);

    char ch;
    std::cout << "Enter q for exit\n";
    std::cin >> ch;
    if (ch == 'q')
        WINDOW_MANAGER.destroy();
    return 0;
}