/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Items
*/

#ifndef ITEMS_HPP_
#define ITEMS_HPP_

#include "Object.hpp"

class Items : public Object {
    public:
        enum itemType {
            AXE,
            PICKAXE,
            TORCH,
            GENERATOR
        };
        Items(uint);
        ~Items() final;
        //setters
        void setAvaible(const bool &);
        //getters
        bool getAvaible() const;
        itemType getType() const;
    protected:
        itemType _type;
        bool _available;
    private:
};

#endif /* !ITEMS_HPP_ */
