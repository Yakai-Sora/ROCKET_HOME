/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IGraphics
*/

#ifndef IGRAPHICS_HPP_
#define IGRAPHICS_HPP_

#include "../global.hpp"

class IGraphics {
	public:
		virtual ~IGraphics();

	protected:
	private:
        sf::Sprite _sprite;
        sf::Texture _texture;
};

#endif /* !IGRAPHICS_HPP_ */