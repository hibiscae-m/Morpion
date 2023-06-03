#include "Cursor.h"

Cursor::Cursor() :
	Elements({ 0,0 }, "cursor.png")
{
	type = Elements::TYPE::Cursor;
	setColor(sf::Color(255,0,0,125));
	update();
}

void Cursor::move(const int direction) {
	if (direction == DIRECTION::Up) {
		if ((position.y - 1) < 0)
			position.y += 2;
		else
			position.y--;
	}
	if (direction == DIRECTION::Down) {
		if ((position.y + 1) > 2)
			position.y -= 2;
		else
			position.y++;
	}
	if (direction == DIRECTION::Left) {
		if ((position.x - 1) < 0)
			position.x += 2;
		else
			position.x--;
	}
	if (direction == DIRECTION::Right) {
		if ((position.x + 1) > 2)
			position.x -= 2;
		else
			position.x++;
	}
}
