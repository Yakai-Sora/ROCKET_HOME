/*
** EPITECH PROJECT, 2020
** Game_Jam
** File description:
** Barre
*/

#ifndef BARRE_HPP_
#define BARRE_HPP_

#include "IGui.hpp"


class Barre : public IGui, public sf::Drawable, sf::Transformable {
    public:
        Barre();
        ~Barre();
        // getters
        // const GuiType &getType(void);
		// const sf::Vector2f &getPosition(void) const;
        // const sf::Sprite &getSprite() const;
        // // setters
        // void updateRect(int);

    protected:
    private:
        GuiType _type;
        sf::Vector2f _pos;
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::RectangleShape rect;
};

#endif /* !BARRE_HPP_ */
