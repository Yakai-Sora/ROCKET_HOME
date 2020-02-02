/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 01
*/

#include "new.h"
#include "player.h"

int         main(void)
{
    Object  *player = new(Player);
    ((Class *)player)->__dtor__ = NULL;
    delete(player);
    return (0);
}
