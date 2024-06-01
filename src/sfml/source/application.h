#pragma once
#include "button.h"

class Game {
public:
	static Game& Instance();
	Game& operator = (const Game& game) = delete;
	Game(const Game& game) = delete;
public:
	void launch();
private:
	Game(sf::VideoMode mode, std::string title);
	void event_handling();
	void update(float deltaTime);
	void render();
private:
	sf::RenderWindow m_window;
	Button m_button = { 60, 30 };
	sf::Clock m_clock;
};