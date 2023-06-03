#include "Game.h"

#include <SFML/Graphics.hpp>
#include "WindowSettings.h"

Game::Game() :
	window(sf::VideoMode(WindowSettings::getResolution().x, WindowSettings::getResolution().y), WindowSettings::getName().data()),
	playground(window)
{
	window.setKeyRepeatEnabled(false);
}

void Game::run() {
	playground.placeElement({ 0, 0 }, Elements::TYPE::Cursor);
	sf::Clock clock;
	sf::Time time_since_last_update = sf::Time::Zero;
	while (window.isOpen()) {
		time_since_last_update += clock.restart();
		if (time_since_last_update > WindowSettings::getFramerate()) {
			time_since_last_update -= WindowSettings::getFramerate();
			playground.processEvents();
			playground.update();
			updateWindow();
		}
	}
}

void Game::updateWindow() {
	window.clear();
	playground.draw();
	window.display();
}
