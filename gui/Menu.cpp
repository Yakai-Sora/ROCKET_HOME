/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    ///MUSIC///
    if (!this->_music.openFromFile("assets/music.ogg"))
        throw std::runtime_error("Error _loading music file !");
    _music.setLoop(true);

    ///SOUND BUFFER///
    _play_sound = false;
    if (!_buffer.loadFromFile("assets/sound.ogg"))
        throw std::runtime_error("Error _loading sound file!");
    _sound.setBuffer(_buffer);

    ///MENU TITLE///
    _pos = (sf::Vector2f(1920, 1080));
    _font.loadFromFile("assets/pixelem.otf");
    _title.setFont(_font);
    _title.setFillColor(sf::Color::Black);
    _title.setCharacterSize(100);
    _title.setPosition(sf::Vector2f((_pos.x / 2) - 410.5, _pos.y/3));
    _title.setString("ROCKET HOME");

    ///LOADING SCREEN///
    _isloading = false;
    _loading.setFont(_font);
    _loading.setFillColor(sf::Color::Black);
    _loading.setCharacterSize(100);
    _loading.setPosition(sf::Vector2f((_pos.x / 2) - 290, _pos.y/2));
    _loading.setString("LOADING ...");

    ///START BUTTON///
    _atl_button = false;
    _TbuttonMenu.loadFromFile("assets/start_button_alt.png");
    _start_button.setTexture(_TbuttonMenu);
}

void Menu::addObject(Object obj)
{
    this->_elem.push_back(obj);
}

int Menu::runScene(sf::RenderWindow &window)
{
    bool Running = true;
    sf::Event event;

    ///MUSIC///
    _music.play();

    Button start(_TbuttonMenu, _start_button);
    start.setPosition(sf::Vector2f((_pos.x / 2) - (start.getBounds().width / 2), _pos.y/2));

    while (Running) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                window.close();
                return (-1);
            }
            if (event.type == sf::Event::MouseMoved) {
                if (start.getBounds().contains(mousePosF)) {
                    if (_play_sound == false) {
                        _sound.play();
                        _play_sound = true;
                    }
                    start.setSpriteTexture("assets/start_button.png");
                } else if (!start.getBounds().contains(mousePosF)) {
                    _play_sound = false;
                    start.setSpriteTexture("assets/start_button_alt.png");
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (start.getBounds().contains(mousePosF)) {
                    _isloading = true;
                    window.clear(sf::Color::White);
                    window.draw(_loading);
                    window.display();
                    _music.stop();
                    return (1);
                }
            }
        }
        window.clear(sf::Color::White);
        if (_isloading == false) {
            window.draw(_title);
            window.draw(start);
        } else if (_isloading == true) {
            window.draw(_loading);
        }
        window.display();
    }
    return (0);
}

Menu::~Menu() {}