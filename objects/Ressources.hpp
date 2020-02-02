/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Ressources
*/

#ifndef RESSOURCES_HPP_
#define RESSOURCES_HPP_

#include "Object.hpp"

class Ressources : public Object {
    public:
        enum ressType {
            WOOD,
            ROCK,
            STEEL,
            ENERGY
        };
        Ressources(uint);
        ~Ressources();
        // getter
        uint getNumber() const;
        ressType getRessType() const;
        // setter 
        void setNumber(int);
        void operator<<(int nbRessources);

	protected:
        ressType _type;
        uint _number;
    private:
};

#endif /* !RESSOURCES_HPP_ */
