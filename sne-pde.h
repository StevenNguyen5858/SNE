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


void fill(int r, int g, int b, int a) {
	sf::Color color = sf::Color(r, g, b, a);
	currentFill = color;
}

void fill(int r, int g, int b) {
	sf::Color color = sf::Color(r, g, b, 255);
	currentFill = color;
}

void fill(int greyValue) {
	currentFill = sf::Color(greyValue, greyValue, greyValue, 255);
}

void noFill() {
	currentFill = sf::Color::Transparent;
}

void stroke(int r, int g, int b, int a) {
	sf::Color color = sf::Color(r, g, b, a);
	currentStroke = color;
}

void stroke(int r, int g, int b) {
	sf::Color color = sf::Color(r, g, b, 255);
	currentStroke = color;
}

void stroke(int greyValue) {
	currentStroke = sf::Color(greyValue, greyValue, greyValue, 255);
}

void noStroke() {
	currentStroke = sf::Color::Transparent;
}

void strokeWeight(int strokeWeight) {
	currentStrokeWeight = -1 * strokeWeight;
}
