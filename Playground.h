#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <SFML/Graphics.hpp>
#include "Elements.h"

class Playground
{
public:
	Playground() = delete;
	explicit Playground(sf::RenderWindow& window);
	void update();
	void processEvents();
	void draw();
	void placeElement(const sf::Vector2i position, const int element_type);
private:
	void checkVictory();
	std::vector<std::vector<char>> elements_position = {
		{Elements::TYPE::Free,Elements::TYPE::Free,Elements::TYPE::Free},
		{Elements::TYPE::Free,Elements::TYPE::Free,Elements::TYPE::Free},
		{Elements::TYPE::Free,Elements::TYPE::Free,Elements::TYPE::Free}
	};
	bool player1_turn = true;
	bool game_over = false;

	sf::RenderWindow& window;
	std::vector<std::unique_ptr<Elements>> elements{};
	std::vector<std::unique_ptr<Elements>> buffer{};
};

#endif //PLAYGROUND_H