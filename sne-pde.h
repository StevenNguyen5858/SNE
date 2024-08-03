#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"


using namespace std;

sf::RenderWindow mainWindow;
map<string, sf::RenderWindow*> windows;
sf::RenderWindow* activeWindow = &mainWindow;


sf::Color current_fill = sf::Color(255, 255, 255, 255);
sf::Color current_stroke = sf::Color(0, 0, 0, 255);
int current_stroke_weight = 1;
