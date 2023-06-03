#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/Graphics.hpp>
#include "Elements.h"

class Cursor : public Elements
{
public:
	Cursor();
	void move(const int direction) override;
	const enum DIRECTION {
		Up,
		Down,
		Left,
		Right
	};
};

#endif //CURSOR_H