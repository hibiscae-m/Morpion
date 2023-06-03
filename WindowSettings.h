#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

#include <string_view>
#include <SFML/Graphics.hpp>

class WindowSettings
{
public:
	WindowSettings() = delete;
	inline static sf::Vector2i getResolution() {
		return { WINDOW_WIDTH, WINDOW_HEIGHT };
	};
	inline static sf::Time getFramerate() {
		return sf::seconds(FRAMERATE);
	};
	inline static std::string_view getName() {
		return WINDOW_NAME;
	};
private:
	static constexpr int WINDOW_WIDTH = 800;
	static constexpr int WINDOW_HEIGHT = 800;
	static constexpr std::string_view WINDOW_NAME = "Morpion!";
	static constexpr float FRAMERATE = (1.f / 10.f);
};

#endif //WINDOWSETTINGS_H