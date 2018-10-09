//
// Created by morten on 09.10.18.
//

#ifndef PLATFORMER_GRAPHICSOBJECT_H
#define PLATFORMER_GRAPHICSOBJECT_H


#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class GraphicsObject {
protected:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f gravity;
    sf::RenderWindow &window;

    virtual void process(float delta_time) = 0;

    virtual void draw() = 0;

public:
    const sf::Vector2f &getPosition() const {
        return position;
    }

protected:
    GraphicsObject(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f gravity)
            : window(window) {
        this->position = position;
        this->velocity = velocity;
        this->gravity = gravity;
    }
};


#endif //PLATFORMER_GRAPHICSOBJECT_H
