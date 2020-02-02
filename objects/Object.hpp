/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "IObjects.hpp"

class Object : public IObjects, \
public sf::Drawable, public sf::Transformable {
    public:
        Object(ObjectType type = DEFAULT, const std::string &path = "");
        // setter
        void setPosition(const sf::Vector2f &);
        void setId(ObjectType);
        void setSpriteTexture(const std::string &);
        void setSpriteTexture(const sf::Texture &);
        sf::Sprite &takeSprite(void);

        // getter
        const sf::Vector2f &getPosition(void) const;
        const ObjectType &getId(void) const;
        const sf::Sprite &getSprite() const;
        const sf::FloatRect getBounds(void) const;
        ~Object() override;

    protected:
        ObjectType _id;
        sf::Texture _texture;
        sf::Vector2f _position;
        sf::Sprite _sprite;

	private:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            states.texture = NULL;

            target.draw(this->_sprite, states);
        }
};

#endif /* !OBJECT_HPP_ */