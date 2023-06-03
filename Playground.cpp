#include "Playground.h"
#include "Cursor.h"
#include "Cross.h"
#include "Circle.h"
#include <iostream>

Playground::Playground(sf::RenderWindow& window) :
	window(window)
{
}

void Playground::update() {
	for (auto i = 0u; i < elements.size(); i++) {
		elements[i]->update();
		if (!(elements[i]->isAlive())) {
			elements.erase(elements.begin() + i);
		}
	}
	for (auto& buffered_element : buffer)
		elements.push_back(std::move(buffered_element));
	buffer.clear();
	checkVictory();
}

void Playground::draw() {
	for (auto i = elements.size(); i > 0u; i--)
		elements[i-1]->draw(window);
}

void Playground::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyPressed) {
			for (auto& element : elements) {
				if (element->getType() == Elements::TYPE::Cursor) {
					if (!game_over) {
						switch (event.key.code) {
						case::sf::Keyboard::Up:
							element->move(Cursor::DIRECTION::Up);
							break;
						case::sf::Keyboard::Down:
							element->move(Cursor::DIRECTION::Down);
							break;
						case::sf::Keyboard::Left:
							element->move(Cursor::DIRECTION::Left);
							break;
						case::sf::Keyboard::Right:
							element->move(Cursor::DIRECTION::Right);
							break;
						case::sf::Keyboard::Enter:
							if (elements_position[element->getPosition().y][element->getPosition().x] == Elements::TYPE::Free) {
								if (player1_turn)
									placeElement(element->getPosition(), Elements::TYPE::Cross);
								else
									placeElement(element->getPosition(), Elements::TYPE::Circle);
								player1_turn = !player1_turn;
								if (player1_turn)
									element->setColor(sf::Color(255, 0, 0, 125));
								else
									element->setColor(sf::Color(0, 0, 255, 125));
							}
							break;
						default:
							break;
						}
					}
				}
			}
		}
	}
}

void Playground::placeElement(const sf::Vector2i position, const int element_type) {
	switch (element_type) {
	case::Elements::TYPE::Cursor:
		buffer.push_back(std::make_unique<Cursor>());
		break;
	case::Elements::TYPE::Cross:
		elements_position[position.y][position.x] = Elements::TYPE::Cross;
		buffer.push_back(std::make_unique<Cross>(position));
		break;
	case::Elements::TYPE::Circle:
		elements_position[position.y][position.x] = Elements::TYPE::Circle;
		buffer.push_back(std::make_unique<Circle>(position));
		break;
	default:
		break;
	}
}

void Playground::checkVictory() {
	if (!game_over) {
		// lignes
		for (int i = 0; i < 3; i++) {
			if (elements_position[i][0] != Elements::TYPE::Free &&
				elements_position[i][0] == elements_position[i][1] &&
				elements_position[i][1] == elements_position[i][2]) {
				std::cout << "Game Over!" << std::endl;
				game_over = true;
			}
		}

		// colonnes
		for (int i = 0; i < 3; i++) {
			if (elements_position[0][i] != Elements::TYPE::Free &&
				elements_position[0][i] == elements_position[1][i] &&
				elements_position[1][i] == elements_position[2][i]) {
				std::cout << "Game Over!" << std::endl;
				game_over = true;
			}
		}

		// diagonales
		if (elements_position[0][0] != Elements::TYPE::Free &&
			elements_position[0][0] == elements_position[1][1] &&
			elements_position[1][1] == elements_position[2][2]) {
			std::cout << "Game Over!" << std::endl;
			game_over = true;
		}
		if (elements_position[2][0] != Elements::TYPE::Free &&
			elements_position[2][0] == elements_position[1][1] &&
			elements_position[1][1] == elements_position[0][2]) {
			std::cout << "Game Over!" << std::endl;
			game_over = true;
		}
	}
}