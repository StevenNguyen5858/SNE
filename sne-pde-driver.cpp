#pragma once
#include <iostream>
#include "sne-processing-header.h"
#include "router.h"
using namespace std;


void sneSettings() {
    loadFonts();
    mainWindow.create(sf::VideoMode(400, 400), "SNE");
    windows["main"] = &mainWindow;
}

void eventHandler() {
    sf::Event event;
    while (activeWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			activeWindow->close();
		}

		if (event.type == sf::Event::Resized) {
			activeWindow->setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			int mouse_x = sf::Mouse::getPosition(*activeWindow).x;
			int mouse_y = sf::Mouse::getPosition(*activeWindow).y;
			app.mousePressed(mouse_x, mouse_y);
		}

		if (event.type == sf::Event::MouseMoved) {
			int mouse_x = sf::Mouse::getPosition(*activeWindow).x;
			int mouse_y = sf::Mouse::getPosition(*activeWindow).y;
			app.mouseMoved(mouse_x, mouse_y);
		}

		if (event.type == sf::Event::TextEntered) { // Use to trigger an action once when a key is pressed for text 
			string key = " ";
			if (event.key.code < 128) {
				key = event.text.unicode;
				app.keyPressed(key);
			}
		}

		if (event.type == sf::Event::KeyPressed) { // Use to trigger an action once when a key is pressed 
			string key = " ";
			if (event.key.code == sf::Keyboard::Escape) {
				activeWindow->close();
			}
		}
    }
}

int main() {
    sneSettings();
    router::setupPaging();

    while (activeWindow->isOpen()) {
        app.draw();
        eventHandler();
    }

	return 0;
}