/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Craft
*/

#include "Craft.hpp"

Craft::Craft()
{
    _craftMenu.setSpriteTexture("./assets/craft.png");
    _craftBar.setSpriteTexture("./assets/bar.png");
}

bool Craft::craftIt(Stuff &stuff, Items::itemType type)
{
    itemRecipe toCraft;

    for (auto it = itemR.begin(); it != itemR.end(); ++it) {
        if (it->result == type) {
            toCraft = (*it);
            break;
        } else if (it = itemR.end() - 1)
            return (false);
    }
    Ressources *ress1 = static_cast<Ressources *>(stuff._ressources[toCraft.type1]);
    Ressources *ress2 = static_cast<Ressources *>(stuff._ressources[toCraft.type2]);
    Items *itemTmp = static_cast<Items *>(stuff._items[toCraft.result]);

    if (toCraft.nb1 > (ress1)->getNumber() \
    or toCraft.nb2 > (ress2)->getNumber())
        return (false);
    ress1->setNumber(ress1->getNumber() - toCraft.nb1);
    ress2->setNumber(ress2->getNumber() - toCraft.nb2);
    (itemTmp)->setAvaible(true);
    return (true);
}

Craft::~Craft() {}