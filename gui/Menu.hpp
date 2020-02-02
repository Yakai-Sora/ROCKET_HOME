/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Scene.hpp"
#include "Button.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Menu : public Scene {
	public:
		Menu();
        void addObject(Object obj);
        int runScene(sf::RenderWindow &window) final;
		~Menu() final;

	private:
        std::vector<Object> _elem;
	private:
		sf::Music _music;
		sf::SoundBuffer _buffer;
		sf::Sound _sound;
		bool _play_sound;
	private:
		sf::Text _title;
    	sf::Vector2f _pos;
    	sf::Font _font;
		sf::Text _loading;
    	bool _isloading;
	private:
		bool _atl_button;
    	sf::Texture _TbuttonMenu;
    	sf::Sprite _start_button;

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
		{
			states.transform *= getTransform();
			states.texture = NULL;

			for (auto it = _elem.begin(); it != _elem.end(); ++it)
				target.draw(*it);
		}
};

#endif /* !MENU_HPP_ */