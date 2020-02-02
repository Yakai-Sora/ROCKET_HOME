//
// Created by Yuno on 01/02/2020.
//

#include "Camera.hpp"

Camera::Camera(TilesMap &map): map(map)
{
    sf::View view;
    view.setSize(sf::Vector2f(1920/3, 1080/3));
    this->time_spent = 0;
    this->view = view;
}

void Camera::moveAnimations(sf::Clock &clock)
{
    this->map.character.change_orientation();
    if (clock.getElapsedTime().asSeconds() > 0.2f) {
        this->map.character.move_rect();
        clock.restart();
    }
}

bool Camera::load()
{
    sf::Vector2f pos = map.character.getPos();
    Stuff *tmp = this->map.character.getStuff();

    this->view.setCenter(sf::Vector2f(pos.x + 10, pos.y + 10));
    pos = view.getCenter();
    for (int idx = 0; idx < 4; ++idx) {
        tmp->_items[idx]->setPosition(sf::Vector2f(pos.x - 280, pos.y + (70 * (idx - 2))));
        tmp->_ressources[idx]->setPosition(sf::Vector2f(pos.x + 280, pos.y + (70 * (idx - 2))));
    }
}

int Camera::runScene(sf::RenderWindow &window)
{
    bool Running = true;
    sf::Clock clock;
    sf::Clock c2;
    sf::Event event;

    this->map.load();
    this->load();

    sf::Music music;
    if (!music.openFromFile("assets/music_story.ogg"))
        return -1;
    music.setLoop(true);
    music.play();

    while (Running) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed || \
            event.key.code == sf::Keyboard::Escape) {
                window.close();
                return (-1);
            }
            map.character.getEvents(event, map.getSprites());
        }

        this->time_spent = (static_cast<int>(c2.getElapsedTime().asSeconds() / 10) % 24);
        this->moveAnimations(clock);
        map.character.move(map.get_collides());
        window.setView(view);
        this->load();
        window.clear(sf::Color::White);
        window.draw(*this);
        window.display();
    }
    return (-1);
}