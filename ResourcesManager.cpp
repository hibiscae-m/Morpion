#include "ResourcesManager.h"

#include "ResourcesManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

template<>
std::unordered_map<std::string_view, sf::Texture> ResourcesManager<sf::Texture>::resources{};

template<>
std::unordered_map<std::string_view, sf::SoundBuffer> ResourcesManager<sf::SoundBuffer>::resources{};
