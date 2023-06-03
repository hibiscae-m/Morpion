#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include "Elements.h"

class Circle : 
	public Elements
{
public:
	Circle() = delete;
	explicit Circle(sf::Vector2i position);
};

#endif //CIRCLE_H
