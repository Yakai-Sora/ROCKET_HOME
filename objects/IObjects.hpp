/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IObjects
*/

#ifndef IOBJECTS_HPP_
#define IOBJECTS_HPP_

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class IObjects {
	public:
		enum ObjectType {
            RESSOURCE,
            ITEMS,
			STUFF,
			BUTTON,
			DEFAULT
        };
		virtual const ObjectType &getId(void) const = 0;
		virtual const sf::Vector2f &getPosition(void) const = 0;
		virtual ~IObjects() {};
	protected:
	private:
};

#endif /* !IOBJECTS_HPP_ */
