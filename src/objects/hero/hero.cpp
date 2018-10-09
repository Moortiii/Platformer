#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "hero.h"
#include "../../settings/config.h"

Hero::Hero(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f gravity)
        : GraphicsObject(window, position, velocity, gravity) {

    if(texture.loadFromFile("sprites/slime-idle-0.png")) {
        sprite.setTexture(texture);
        sprite.setPosition(position);
        size = sf::Vector2f(texture.getSize());
    } else {
        std::cout << "Unable to locate hero texture" << std::endl;
    }

    move_right_key = sf::Keyboard::D;
    move_left_key  = sf::Keyboard::A;
}

void Hero::draw() {
    window.draw(sprite);
}

void Hero::process(float delta) {
    move();

    update_position(delta);

    collide();

    update_sprite();
}

void Hero::move() {
    velocity.x = 0;

    if (sf::Keyboard::isKeyPressed(move_left_key))
        velocity.x = -5;

    if (sf::Keyboard::isKeyPressed(move_right_key))
        velocity.x = 5;
}


void Hero::jump() {
    velocity.y = -15.0f;
}

void Hero::dive() {
    velocity.y = 25.0f;
}

void Hero::collide() {
    if(position.y > Config::height - size.y)
        position.y = Config::height - size.y;
}

void Hero::update_position(float delta) {
    position += velocity * delta;
    velocity += gravity * delta;
}

void Hero::update_sprite() {
    sprite.setPosition(position);
}

void Hero::handle_input(sf::Keyboard::Key key) {
    state = state->handle_input(key, *this);
}




