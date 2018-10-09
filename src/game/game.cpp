//
// Created by morten on 09.10.18.
//

#include "game.h"
#include "../settings/config.h"

Game::Game() : window(sf::VideoMode(Config::width, Config::height), "Platformer"),
               hero(window, sf::Vector2f(Config::width / 2, Config::height / 2), sf::Vector2f(0, 0), sf::Vector2f(0, 0.5f)) {
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(144);
}

void Game::tick() {
    previous_time = current_time;
    current_time = clock.getElapsedTime().asMilliseconds();
    delta = current_time - previous_time;

    if(delta >= 0.5f)
        delta = 0.5f;
}

void Game::run() {
    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyReleased)
                hero.handle_input(event.key.code);
        }

        window.clear();

        update(delta);
        render();

        window.display();
    }
}

void Game::update(float delta) {
    tick();
    hero.process(delta);
}

void Game::render() {
    hero.draw();
}
