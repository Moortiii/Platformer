//
// Created by morten on 09.10.18.
//

#ifndef PLATFORMER_HERO_H
#define PLATFORMER_HERO_H

class GameState;

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include "../graphics_object    /GraphicsObject.h"
#include "../../gamestate/gamestate.h"

class Hero : public GraphicsObject {
public:
    Hero(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f gravity);
public:
    void process(float delta) override;

    void draw() override;

    void move();

    void jump();

    void dive();

    void collide();

    void handle_input(sf::Keyboard::Key key);

    void update_position(float delta);

    void update_sprite();

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f size;

    sf::Keyboard::Key move_left_key;
    sf::Keyboard::Key move_right_key;

    GameState* state;
};


#endif //PLATFORMER_HERO_H
