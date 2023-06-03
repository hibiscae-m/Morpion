#include "Cross.h"

Cross::Cross(sf::Vector2i position) :
	Elements(position, "cross.png")
{
	shape.setSize({ 100, 100 });
	type = TYPE::Cross;
	update();
}
