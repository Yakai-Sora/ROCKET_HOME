/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Craft
*/

#ifndef CRAFT_HPP_
#define CRAFT_HPP_

#include "../objects/Object.hpp"
#include "../objects/Ressources.hpp"
#include "../objects/Items.hpp"
#include "../gui/Stuff.hpp"

typedef struct itemRecipe_s {
    Ressources::ressType type1;
    uint nb1;
    Ressources::ressType type2;
    uint nb2;
    Items::itemType result;
} itemRecipe;

typedef struct ressourceRecipe_s {
    Ressources::ressType type1;
    uint nb1;
    Ressources::ressType type2;
    uint nb2;
    Ressources::ressType result;
} ressRecipe;

class Craft {
	public:
		Craft();
        bool craftIt(Stuff &, Items::itemType);
		~Craft();

	protected:
	private:
        Object _craftMenu;
        Object _craftBar;

        // Item Recipe
        const std::array<itemRecipe, 4> itemR {
            itemRecipe {
                Ressources::ressType::WOOD, 2,
                Ressources::ressType::ROCK, 3,
                Items::itemType::AXE
            }, itemRecipe {
                Ressources::ressType::WOOD, 2,
                Ressources::ressType::ROCK, 3,
                Items::itemType::PICKAXE
            }, itemRecipe {
                Ressources::ressType::STEEL, 3,
                Ressources::ressType::ENERGY, 2,
                Items::itemType::TORCH
            }, itemRecipe {
                Ressources::ressType::STEEL, 10,
                Ressources::ressType::WOOD, 15,
                Items::itemType::GENERATOR
            },
        };
        // Ressource Recipe
        const std::array<ressRecipe, 1> ressR {
            ressRecipe {
                Ressources::ressType::WOOD, 1,
                Ressources::ressType::ROCK, 1,
                Ressources::ressType::ENERGY
            },
        };
};

#endif /* !CRAFT_HPP_ */