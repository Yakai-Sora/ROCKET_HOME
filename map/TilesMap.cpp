//
// Created by Yuno on 31/01/2020.
//

#include "TilesMap.hpp"

TilesMap::TilesMap(Character &c): character(c)
{
    this->loadTextures();
}

bool compare_sprite_pos(sf::Sprite a, sf::Sprite b)
{
    return a.getPosition().y + a.getGlobalBounds().height < b.getPosition().y + b.getGlobalBounds().height;
}

std::vector<sf::FloatRect> TilesMap::get_collides() {
    std::vector<sf::FloatRect> collides;
    for (int i = 0; i < sprite_vector.size(); i++) {
        collides.push_back(sf::FloatRect(
                sprite_vector[i].getGlobalBounds().left,
                sprite_vector[i].getGlobalBounds().top
                + sprite_vector[i].getGlobalBounds().height / 1.5,
                sprite_vector[i].getGlobalBounds().width,
                1
        ));
    }
    return collides;
}

void TilesMap::loadTextures() {
    std::vector<MapType> types = {FLOWER, GRASS, ITEM, PUDDLE_B, PUDDLE_S};
    std::vector<std::string> file_names = {
            "flower.png",
            "grass.png",
            "item.png",
            "puddle_big.png",
            "puddle_small.png"
    };
    for (int i = 0; i < types.size(); i++) {
        map_text_t tmp_struct;
        sf::Texture tmp_texture;
        if (!tmp_texture.loadFromFile("assets/" + file_names[i])) {
            std::cout << ("assets/" + file_names[i]) << std::endl;
            exit(1);
        }
        tmp_struct.type = types[i];
        tmp_struct.texture = tmp_texture;
        this->map_text.push_back(tmp_struct);
    }
}

sf::Texture find_right_text(TilesMap::MapType type, std::vector<TilesMap::map_text_t> assets_vector) {
    for (int i = 0; i < assets_vector.size(); i++) {
        if (assets_vector[i].type == type)
            return assets_vector[i].texture;
    }
    return assets_vector[0].texture;
}

std::vector<sf::Sprite> &TilesMap::getSprites(void)
{
    return (this->sprite_vector);
}

bool TilesMap::load()
{
    PerlinNoise2d map_generator(3, 15);

    map_generator.generateMap(100);
    std::vector<std::vector<double> > generated_map = map_generator.getMap();
    for (int i = 0; i < generated_map.size(); i++) {
        for (int j = 0; j < generated_map.size(); j++) {
            double p = generated_map[i][j];
            MapType type;
            if (p > 0.93) type = PUDDLE_B;
            else if (p > 0.85) type = MUSHROOM;
            else if (p > 0.80) type = PUDDLE_S;
            else if (p > 0.78) type = GRASS;
            else {
                continue;
            }
            this->texture_vector.push_back(find_right_text(type, this->map_text));
            sf::Sprite tmp;
            tmp.setPosition(sf::Vector2f(i * 30, j * 55));
            tmp.setScale(0.1, 0.1);
            this->sprite_vector.push_back(tmp);
        }
    }
    for (int i = 0; i < texture_vector.size(); i++)
        sprite_vector[i].setTexture(texture_vector[i]);
    std::sort(sprite_vector.begin(), sprite_vector.end(), &compare_sprite_pos);
    return (true);
}