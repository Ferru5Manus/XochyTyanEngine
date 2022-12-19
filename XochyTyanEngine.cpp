#include <iostream>
#include "WindowManager.h"
#include "LinkedList.h"

int main(void)
{
    WindowManager* WINDOW_MANAGER = new WindowManager();
    char name[] = "SomeWindow";
    WINDOW_MANAGER->init(name, 800, 800);
    return 0;
}