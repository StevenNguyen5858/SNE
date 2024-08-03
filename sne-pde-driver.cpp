#pragma once
#include <iostream>
#include "sne-header.h"
#include <thread>
using namespace std;


void sneSettings() {
    mainWindow.create(sf::VideoMode(400, 400), "SNE Application Template");
    windows["main"] = &mainWindow;
}

int main() {
    sneSettings();

    primativeShapesDemo();

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