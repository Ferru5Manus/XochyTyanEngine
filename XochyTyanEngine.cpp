#include <iostream>
#include "WindowManager.h"
#include "LinkedList.h"

int main(void)
{

    LinkedList<double>* list = new LinkedList<double>();
    for (int i = 0; i < 10; i++)
    {
        list->add(i);
    }
    list->remove(100);
    list->toString();

    WindowManager WINDOW_MANAGER;
    char name[] = "SomeWindow";
    WINDOW_MANAGER.init(name, 500, 500);

    delete list;

    return 0;
}