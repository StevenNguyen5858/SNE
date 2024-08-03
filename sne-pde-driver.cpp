#pragma once
#include <iostream>
#include "sne-header.h"
using namespace std;


void sneSettings() {
    loadFonts();
    mainWindow.create(sf::VideoMode(400, 400), "SNE Application Template");
    windows["main"] = &mainWindow;
}

int main() {
    sneSettings();

    //primativeShapesDemo();
    textDemo();

    while (activeWindow->isOpen()) {
        sf::Event e;
        while (activeWindow->pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                activeWindow->close();
            }
        }
    }

	return 0;
}