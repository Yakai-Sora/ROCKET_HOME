/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IGui
*/

#ifndef IGUI_HPP_
#define IGUI_HPP_

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class IGui {
	public:
		enum GuiType {
			STUFF,
			MENU,
			BARRE,
			CRAFT
		};
		const virtual GuiType &getType(void) = 0;
		const virtual sf::Vector2f &getPosition(void) const = 0;
		virtual ~IGui() {};
    protected:
    private:
};

#endif /* !IGUI_HPP_ */
