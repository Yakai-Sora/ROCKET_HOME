//
// Created by Yuno on 31/01/2020.
//

#ifndef GAME_JAM_TILESMAP_HPP
#define GAME_JAM_TILESMAP_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include "../tools/PerlinNoise2d.hpp"
#include "../characters/Character.hpp"


class TilesMap: public sf::Drawable, public sf::Transformable {
    public:
        TilesMap(Character &c);
        enum MapType {
            GRASS,
            FLOWER,
            ITEM,
            MUSHROOM,
            PUDDLE_S,
            PUDDLE_B,
        };

        typedef struct map_text_s {
            MapType type;
            sf::Texture texture;
        } map_text_t;

        bool load();
        void loadTextures();
        std::vector<sf::FloatRect> get_collides();
        std::vector<sf::Sprite> &getSprites(void);
        Character character;

    private:
        std::vector<sf::Sprite> sprite_vector;
        std::vector<sf::Texture> texture_vector;
        std::vector<TilesMap::map_text_t> map_text;
        std::vector<TilesMap::MapType> _map_items;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            states.texture = NULL;

            target.draw(character, states);
            for (int i = 0; i < this->sprite_vector.size(); i++) {
                target.draw(this->sprite_vector[i], states);
                if (this->sprite_vector[i].getPosition().y + \
                this->sprite_vector[i].getGlobalBounds().height \
                < character.getHeight())
                    target.draw(character, states);
            }
        }
};


#endif //GAME_JAM_TILESMAP_HPP
