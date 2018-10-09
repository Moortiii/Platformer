//
// Created by morten on 09.10.18.
//

#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../objects/hero/hero.h"

class Game {
public:
    void run();

    void update(float delta);

    void render();
    void tick();
    Game();

private:
    sf::RenderWindow window;

    sf::Clock clock;
    float current_time;
    float previous_time;
    float delta;

    Hero hero;
};


#endif //PLATFORMER_GAME_H
