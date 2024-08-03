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


sf::Color currentFill = sf::Color(255, 255, 255, 255);
sf::Color currentStroke = sf::Color(0, 0, 0, 255);
int currentStrokeWeight = 1;
