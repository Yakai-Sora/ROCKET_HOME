/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Stuff
*/

#ifndef STUFF_HPP_
#define STUFF_HPP_

#include "IGui.hpp"
#include "../objects/Ressources.hpp"
#include "../objects/Items.hpp"

class Stuff : public IGui, public sf::Drawable, public sf::Transformable {
	public:
		Stuff();
		~Stuff();
        // getters
        const GuiType &getType(void);
		const sf::Vector2f &getPosition(void) const;
        // const std::vector <Ressources> &getRessources(void) const;
        // std::vector <Items> &getItems();

        std::vector<Object *> _ressources;
        std::vector<Object *> _items;

        // setters
    private:
        GuiType _type;
        sf::Vector2f _pos;

	private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            states.texture = NULL;

            std::cout << "Draw stuff" << std::endl;
            for (int idx; idx < 4; ++idx) {
                target.draw(*_items[idx]);
                target.draw(*_ressources[idx]);
            }
        }
};

#endif /* !STUFF_HPP_ */