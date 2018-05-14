//
// Created by charles on 5/13/18.
//

#ifndef PROJECT_PYROS_MAINMENU_H
#define PROJECT_PYROS_MAINMENU_H

#include "Button.h"
#include <list>

class MainMenu
{
public:
    enum MenuResult {Nothing, Exit, Play, Instructions};

    struct MenuItem
    {
        Button button;
        MenuResult action;
    };

    MenuResult show(sf::RenderWindow &window);

private:

    MenuResult getMenuResponse(sf::RenderWindow *window);
    MenuResult handleClick(sf::Vector2i mousePos);
    std::list<MenuItem> menuItems;
};


#endif //PROJECT_PYROS_MAINMENU_H
