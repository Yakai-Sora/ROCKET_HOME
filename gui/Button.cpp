/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(sf::Texture texture, sf::Sprite sprite) : Object(BUTTON)
{
    _texture = texture;
    _sprite = sprite;
}