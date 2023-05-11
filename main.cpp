#include "principal.hpp"

int main()
{
    bool control = false;
    Menu *menu = new Menu();
    control = menu->run();
    delete menu;
    menu = nullptr;
    if (control)
        Principal objPrincipal;
    return 0;
}