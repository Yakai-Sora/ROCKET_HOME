/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <iostream>
#include <map>

#include "../objects/Object.hpp"

class Scene : public sf::Drawable, public sf::Transformable {
	public:
		// Run
		virtual int runScene(sf::RenderWindow &window) = 0;
		// Dtor
		virtual ~Scene() {};
};

#endif /* !SCENE_HPP_ */