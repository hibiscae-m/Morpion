#ifndef CROSS_H
#define CROSS_H

#include <SFML/Graphics.hpp>
#include "Elements.h"

class Cross :
    public Elements
{
public:
	Cross() = delete;
	explicit Cross(sf::Vector2i position);
};

#endif //CROSS_H