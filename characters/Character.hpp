/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "ICharacters.hpp"
#include "../gui/Stuff.hpp"
#include "../gui/Craft.hpp"
#include <array>
#include <random>

class Character : public ICharacters, public sf::Drawable, public sf::Transformable {
    public:
        Character() {};
        Character(const std::string &textureFile, sf::IntRect rect);
        ~Character();
        void move(std::vector<sf::FloatRect> collides);
        bool isMoving(moveDir direction = NONE);

        // Getters
        sf::Vector2f getPos();
        int getHeight() const;
        sf::Texture &getTexture();
        sf::Sprite &getSprite();
        sf::IntRect &getRect();
        moveDir &getDirection();
        int getStamina(void) const;
        bool isSprinting(void) const;
        Stuff *getStuff(void);

        // Setters
        void setX(int x);
        void setY(int y);
        void setNewTexture(std::string);
        void setDirection(Character::moveDir, bool);
        void setSprint(const bool &);
        void useStamina(float);
        void restoreStamina(float);

        // Craft
        void craftItem(Stuff &, Items::itemType);

        // Events
        void getEvents(sf::Event &, std::vector<sf::Sprite> &);
        void proximaObject(std::vector<sf::Sprite> &);

        // Animations
        void moveAnimation(void);
        void move_rect(void);
        void change_orientation(void);

        // Debug
        void printData(void);

    protected:
    private:
        float _speed;
        float _sprint;
        float _stamina;
        bool _craftOpen;
        sf::IntRect _rectSprite;
        sf::Texture _texture;
        sf::Texture _texture_shadow;
        sf::Sprite _sprite;
        sf::Sprite _shadow;
        std::array<bool, 4> _udlrDir;
        Stuff _stuff;
        Craft _crafter;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            states.texture = NULL;

            target.draw(_shadow, states);
            target.draw(_sprite, states);
            // target.draw(_stuff, states);
        }
};

#endif /* !CHARACTER_HPP_ */