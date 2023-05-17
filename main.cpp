#include "principal.hpp"

int main()
{
    bool control = false;
    Menu *menu = new Menu();
    control = menu->run();
    delete menu;
    menu = nullptr;
    if (control)
        Jogo start;
    return 0;
}