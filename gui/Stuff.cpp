/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Stuff
*/

#include "Stuff.hpp"

Stuff::Stuff()
{
    this->_type = STUFF;

    this->_ressources.push_back(new Ressources(Ressources::WOOD));
    this->_ressources.push_back(new Ressources(Ressources::ROCK));
    this->_ressources.push_back(new Ressources(Ressources::STEEL));
    this->_ressources.push_back(new Ressources(Ressources::ENERGY));

    this->_items.push_back(new Items(Items::AXE));
    this->_items.push_back(new Items(Items::PICKAXE));
    this->_items.push_back(new Items(Items::TORCH));
    this->_items.push_back(new Items(Items::GENERATOR));
}

Stuff::~Stuff()
{
    _items.clear();
    _ressources.clear();
}

const IGui::GuiType &Stuff::getType(void)
{
    return (this->_type);
}

const sf::Vector2f &Stuff::getPosition(void) const
{
    return (this->_pos);
}

// const std::vector <Ressources> &Stuff::getRessources() const
// {
//     return(this->_ressources);
// }

// std::vector <Items> &Stuff::getItems()
// {
//     return(this->_items);
// }