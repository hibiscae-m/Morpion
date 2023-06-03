#include "Circle.h"

Circle::Circle(sf::Vector2i position) :
	Elements(position, "circle.png")
{
	shape.setSize({ 100, 100 });
	type = TYPE::Circle;
	update();
}
