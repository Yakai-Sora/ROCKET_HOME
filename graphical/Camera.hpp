//
// Created by Yuno on 01/02/2020.
//

#ifndef GAME_JAM_CAMERA_HPP
#define GAME_JAM_CAMERA_HPP

#include "../characters/Character.hpp"
#include "../map/TilesMap.hpp"
#include "../gui/Scene.hpp"

class Camera : public Scene {
    public:
        Camera(TilesMap &map);
        void moveAnimations(sf::Clock &clock);
        // Load
        bool load();
        // Run
        int runScene(sf::RenderWindow &window) final;

    public: // VARIABLES
        sf::View view;
        TilesMap &map;
        int time_spent;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(map);
            int hour = time_spent%24;
            if (hour < 12) {
                hour -= 12 - hour;
            } else {
                hour -= 12;
            }
            sf::CircleShape shadow;
            shadow.setPosition(this->view.getCenter());
            shadow.move(-200, -200);
            shadow.setFillColor(sf::Color(0, 0, 0, 0));
            shadow.setOutlineThickness(2000);
            shadow.setOutlineColor(sf::Color(255, 255, 255 , 100));
            shadow.setRadius(200);
            for (int i = 1; i < 8; i++) {
                target.draw(shadow);
                shadow.setRadius(200 - i*20);
                shadow.move(+20, +20);
            }
            for (int idx = 0; idx < 4; ++idx) {
                target.draw(*(map.character.getStuff()->_items[idx]));
                target.draw(*(map.character.getStuff()->_ressources[idx]));
            }
        }
};

#endif //GAME_JAM_CAMERA_HPP