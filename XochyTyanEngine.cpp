#include <iostream>
#include "WindowManager.h"
#include "LinkedList.h"

int main(void)
{

    LinkedList<string> *list = new LinkedList<string>();
    for (int i = 0; i < 10; i++)
    {
        list->add("Info");
    }
    list->toString(false);
    list->remove(0);
    list->toString(false);

    WindowManager WINDOW_MANAGER;
    char name[] = "SomeWindow";
    WINDOW_MANAGER.init(name, 500, 500);

    delete list;

    return 0;
}