#include <iostream>
#include "WindowManager.h"
#include "LinkedList.h"

int main(void)
{

    LinkedList<string> list;
    for (int i = 0; i < 10; i++)
    {
        list.add("Info");
    }
    list.toString(false);
    list.remove("Info");
    list.toString(false);

    WindowManager WINDOW_MANAGER;
    char name[] = "SomeWindow";
    WINDOW_MANAGER.init(name, 500, 500);

    list.clear();

    return 0;
}