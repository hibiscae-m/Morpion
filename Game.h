#ifndef GAME_H
#define GAME_H

#include "Cursor.h"
#include "Playground.h"

#include <SFML/Graphics.hpp>
#include <string_view>

class Game
{
public:
	Game();
	void run();
private:
	void updateWindow();

	sf::RenderWindow window;
	
	Playground playground;
};

#endif //GAME_H