/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** main
*/

#include "characters/Character.hpp"
#include "map/TilesMap.hpp"
#include "graphical/Camera.hpp"
#include "gui/Menu.hpp"
#include <iostream>

void getPollEvent(sf::RenderWindow &window, sf::Event &event, TilesMap &map)
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::EventType::Closed || \
        event.key.code == sf::Keyboard::Escape)
            window.close();
        map.character.getEvents(event, map.getSprites());
    }
}

int main(void)
{
    int actualScene = 0;
    sf::RenderWindow window(sf::VideoMode(1920, 1080, 24), "Objectiv home");
    sf::Event event;
    sf::Clock clock;
    std::vector<Scene *> scn;

    // Create menu scene
    Menu menu;
    scn.push_back(&menu);
    // Create game scene
    Character ET("assets/alien2.png", sf::IntRect(0, 0, 96, 96));
    TilesMap mainMap(ET);
    Camera game(mainMap);
    scn.push_back(&game);

    window.setFramerateLimit(30);
    window.setVerticalSyncEnabled(false);
    while (actualScene >= 0)
        actualScene = scn[actualScene]->runScene(window);
    return (0);
}