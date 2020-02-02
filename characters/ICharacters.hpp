/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** ICharacters
*/

#ifndef ICHARACTERS_HPP_
#define ICHARACTERS_HPP_

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class ICharacters {
	public:
		enum moveDir {
			UP,
			DOWN,
			LEFT,
			RIGHT,
			NONE
		};
		virtual ~ICharacters() {};
		virtual sf::Vector2f getPos() = 0;
		virtual void move(std::vector<sf::FloatRect>) = 0;
	protected:
	private:
};

#endif /* !ICHARACTERS_HPP_ */
