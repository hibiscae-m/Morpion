#pragma once

#include "Elements.h"
#include "ResourcesManager.h"
#include "WindowSettings.h"

Elements::Elements(sf::Vector2i position, const std::string_view texture_location) :
	position(position)
{
	sprite.setTexture(ResourcesManager<sf::Texture>::getResource(texture_location));
	sprite.setScale(((sprite.getGlobalBounds().width * WindowSettings::getResolution().x / (sprite.getGlobalBounds().width * 3)) / sprite.getGlobalBounds().width),
		((sprite.getGlobalBounds().height * WindowSettings::getResolution().y / (sprite.getGlobalBounds().height * 3)) / sprite.getGlobalBounds().height));
}

void Elements::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

const bool Elements::isAlive() {
	return alive;
}

const int Elements::getType() {
	return type;
}

const sf::Vector2i Elements::getPosition() {
	return position;
}

void Elements::setPosition() {
	sprite.setPosition((sprite.getGlobalBounds().width * position.x), (sprite.getGlobalBounds().height * position.y));
}

void Elements::update() {
	setPosition();
}

void Elements::move(const int direction) {

}

void Elements::setColor(sf::Color color) {
	sprite.setColor(color);
}
