/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Items
*/

#include "Items.hpp"

Items::Items(uint type) :
Object::Object(ITEMS)
{
    this->_available = false;
    switch (type) {
        case AXE:
            this->setSpriteTexture("./assets/axe.png");
            this->_type = AXE; break;
        case PICKAXE:
            this->setSpriteTexture("./assets/pickaxe.png");
            this->_type = PICKAXE; break;
        case TORCH:
            this->setSpriteTexture("./assets/torch.png");
            this->_type = TORCH; break;
        case GENERATOR:
            this->setSpriteTexture("./assets/generator.png");
            this->_type = GENERATOR; break;
    }
    this->_sprite.setScale(0.4, 0.4);
}

Items::~Items() {}

bool Items::getAvaible() const
{
    return (this->_available);
}

void Items::setAvaible(const bool &state)
{
    this->_available = state;
}

Items::itemType Items::getType() const
{
    return (this->_type);
}