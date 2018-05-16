//
// Created by charles on 5/13/18.
//

#include "MainMenu.h"
#include <chrono>
#include <thread>

MainMenu::MenuResult MainMenu::show(sf::RenderWindow &window)
{
    sf::Texture texture;

    if (!texture.loadFromFile("images/Mainmenu.png"))
    {
        return Nothing;
    }

    sf::Sprite sprite(texture);

    MenuItem playButton;
    playButton.action = Play;
    //TODO: Add button positioning and size

    MenuItem instructionsButton;
    instructionsButton.action = Instructions;
    //TODO: Add button positioning and size

    MenuItem exitButton;
    exitButton.action = Exit;
    //TODO: Add button positioning and size

    menuItems.push_back(playButton);
    menuItems.push_back(exitButton);
    menuItems.push_back(instructionsButton);

    window.draw(sprite);
    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    return getMenuResponse(&window);
}

MainMenu::MenuResult MainMenu::handleClick(sf::Vector2i mousePos)
{
    std::list<MenuItem>::iterator it;

    for (it = menuItems.begin(); it != menuItems.end() ; ++it)
    {
        if ((*it).button.isButtonClicked(mousePos))
        {
            return (*it).action;
        }
    }

    return Nothing;
}

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow *window)
{
    sf::Event menuEvent;

    while (true)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            //if(ServiceLocator::getAudio()->isSongPlaying())
            //  ServiceLocator::getAudio()->stopAllSounds();

            return handleClick(sf::Mouse::getPosition(*window));

        }
        while (window->pollEvent(menuEvent))
        {
            if (menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}