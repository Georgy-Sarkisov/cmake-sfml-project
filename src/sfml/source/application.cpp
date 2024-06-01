#include "application.h"
#include <iostream>

Game& Game::Instance() {
    static Game game(sf::VideoMode(1000, 500), "Subway");
    return game;
}

Game::Game(sf::VideoMode mode, std::string title)
    : m_window(mode, title), m_clock() {
    m_window.setFramerateLimit(60);
    m_window.setKeyRepeatEnabled(false);
    m_button.jump(m_window.getSize());
}

void Game::launch() {
    while (m_window.isOpen()) {
        float deltaTime = m_clock.restart().asSeconds();
        event_handling();
        update(deltaTime);
        render();
    }
}

void Game::event_handling() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::Resized:
            sf::View view;
            view.setSize(m_window.getSize().x, m_window.getSize().y);
            view.setCenter(m_window.getSize().x / 2, m_window.getSize().y / 2);
            m_window.setView(view);
        }
    }
}

void Game::update(float deltaTime) {
    sf::Vector2i pos = sf::Mouse::getPosition(m_window);
    if (m_button.is_position_in({ (float)pos.x, (float)pos.y })) {
        m_button.update(m_window.getSize(), deltaTime);
    }
    else {
        m_button.update(m_window.getSize(), deltaTime);
    }
}

void Game::render() {
    m_window.clear();
    m_button.draw_into(m_window);
    m_window.display();
}