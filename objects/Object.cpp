/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(ObjectType id, const std::string &texturePath)
{
    this->_id= id;
    this->_position = sf::Vector2f(0, 0);
    if (texturePath.empty())
        return;
    this->_texture.loadFromFile(texturePath);
    this->_sprite.setTexture(_texture);
}

Object::~Object() {}


sf::Sprite &Object::takeSprite(void)
{
    return (this->_sprite);
}

// Setters
void Object::setPosition(const sf::Vector2f &pos)
{
    this->_position = pos;
    this->_sprite.setPosition(pos);
}

void Object::setId(Object::ObjectType id)
{
    this->_id = id;
}

void Object::setSpriteTexture(const std::string &path)
{
    this->_texture.loadFromFile(path);
    this->_sprite.setTexture(_texture);
}

void Object::setSpriteTexture(const sf::Texture &texture)
{
    this->_texture = sf::Texture(texture);
    this->_sprite.setTexture(_texture);
}

// Getters
const sf::Vector2f &Object::getPosition(void) const
{
    return (this->_position);
}

const Object::ObjectType &Object::getId(void) const
{
    return (this->_id);
}

const sf::Sprite &Object::getSprite() const
{
    return (this->_sprite);
}

const sf::FloatRect Object::getBounds(void) const
{
    return (_sprite.getGlobalBounds());
}