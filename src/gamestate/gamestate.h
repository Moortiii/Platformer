//
// Created by morten on 09.10.18.
//

class Hero;

#ifndef PLATFORMER_GAMESTATE_H
#define PLATFORMER_GAMESTATE_H

#include <SFML/Window/Keyboard.hpp>
#include "../objects/hero/hero.h"

class GameState {
public:
    virtual void update(float delta, Hero& hero) = 0;
    virtual GameState* handle_input(sf::Keyboard::Key, Hero &hero) = 0;
};


#endif //PLATFORMER_GAMESTATE_H
