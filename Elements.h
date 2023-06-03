#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <SFML/Graphics.hpp>
#include <string_view>

class Elements
{
public:
	Elements() = delete;
	Elements(sf::Vector2i position, const std::string_view texture_location);
	virtual ~Elements() = default;
	void draw(sf::RenderWindow& window);
	virtual void update();
	virtual void move(const int direction);
	const int getType();
	const sf::Vector2i getPosition();
	const bool isAlive();
	const enum TYPE {
		Cursor,
		Cross,
		Circle,
		Free,
		Other
	};
	void setColor(sf::Color color);
protected:
	int type = TYPE::Other;
	sf::RectangleShape shape;
	sf::Vector2i position;
	bool alive = true;
private:
	sf::Sprite sprite;
	void setPosition();
};

#endif //ELEMENTS_H
