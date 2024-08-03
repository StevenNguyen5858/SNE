#pragma once
#include "sne-pde.h"


sf::Font currentFont;
sf::Font defaultFont;
sf::Font fontBold;
sf::Uint32 textStyle = sf::Text::Bold;
double currentTextSize = 10;

sf::Font gotham;
sf::Font gothamBold;
sf::Font gothamBoldItalic;
sf::Font gothamItalic;
sf::Font gothamLight;

enum alignment {
	centerX = 0,
	centerY = 1,
	centerXY = 3,
};

void loadFonts() {
	gotham.loadFromFile("sne-resources/Gotham.ttf");
	gothamBold.loadFromFile("sne-resources/GothamBold.ttf");
	gothamBoldItalic.loadFromFile("sne-resources/GothamBoldItalic.ttf");
	gothamItalic.loadFromFile("sne-resources/GothamItalic.ttf");
	gothamLight.loadFromFile("sne-resources/GothamLight.ttf");

	defaultFont = gotham;
	currentFont = defaultFont;
}

void textSize(double textH) {
	currentTextSize = textH;
}

void textFont(sf::Font f) {
	currentFont = f;
}

double textWidth(string str) {
	sf::Text text;

	text.setFont(currentFont);
	text.setStyle(textStyle);
	text.setString(str);
	text.setCharacterSize(currentTextSize);
	double textW = text.getGlobalBounds().width;
	return textW;
}

// Draws text to buffer.
void text(string str, double x, double y, double h) {
	sf::Text text;
	// Text Style:
	text.setFont(currentFont);
	text.setStyle(textStyle);
	text.setFillColor(currentFill);
	text.setString(str);
	text.setCharacterSize(h);
	// Text Positioning:
	text.setPosition(sf::Vector2f(x, y));

	activeWindow->draw(text);
	currentFont = defaultFont;
}

void text(string str, double x, double y, double w, double h, alignment a) {
	if (a == alignment::centerY) {
		sf::Text text;
		// Text Style:
		text.setFont(currentFont);
		text.setStyle(textStyle);
		text.setFillColor(currentFill);
		text.setString("A");
		text.setCharacterSize(currentTextSize);

		sf::FloatRect bounds = text.getGlobalBounds();
		sf::Vector2f position = text.getPosition();


		double yOffset = bounds.top - position.y;
		double centeredY = (y)+((h - bounds.height) / 2);
		double centeredYCorrected = centeredY - yOffset;
		text.setPosition(int(x), centeredYCorrected);

		text.setString(str);
		activeWindow->draw(text);
		currentFont = defaultFont;
	}
	if (a == alignment::centerXY) {
		sf::Text text;
		// Text Style:
		text.setFont(currentFont);
		text.setStyle(textStyle);
		text.setFillColor(currentFill);
		text.setString("A");
		text.setCharacterSize(currentTextSize);

		sf::FloatRect bounds = text.getGlobalBounds();
		sf::Vector2f position = text.getPosition();


		double yOffset = bounds.top - position.y;
		double centeredY = (y)+((h - bounds.height) / 2);
		double centeredYCorrected = centeredY - yOffset;

		text.setString(str);
		double centeredOffsetX = ((w)-(text.getGlobalBounds().width)) / 2;
		int centeredX = (x)+centeredOffsetX;
		text.setPosition(sf::Vector2f(centeredX, centeredYCorrected));

		activeWindow->draw(text);
		currentFont = defaultFont;
	}
}
