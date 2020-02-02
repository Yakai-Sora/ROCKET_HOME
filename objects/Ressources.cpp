/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Ressources
*/

#include "Ressources.hpp"

Ressources::Ressources(uint type) :
Object::Object(RESSOURCE)
{
    this->_number = 0;
    switch (type) {
        case WOOD:
            this->setSpriteTexture("./assets/wood.png");
            this->_type = WOOD; break;
        case ROCK:
            this->setSpriteTexture("./assets/cayou.png");
            this->_type = ROCK; break;
        case STEEL:
            this->setSpriteTexture("./assets/steel.png");
            this->_type = STEEL; break;
        case ENERGY:
            this->setSpriteTexture("./assets/energy.png");
            this->_type = ENERGY; break;
    }
    this->_sprite.setScale(0.4, 0.4);
}

Ressources::~Ressources() {}

//getter
uint Ressources::getNumber() const
{
    return(this->_number);
}

Ressources::ressType Ressources::getRessType() const
{
    return(this->_type);
}

//setter
void Ressources::setNumber(int nb)
{
    this->_number = nb;
    if (this->_number < 0)
        this->_number = 0;
}

void Ressources::operator<<(int nbRessources)
{
    if (this->_number <= 99)
        this->_number+= nbRessources;
    else
        std::cout << "Implement sprite logo max ressources" << std::endl;
}