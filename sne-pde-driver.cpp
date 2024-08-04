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
    sf::Event e;
    while (activeWindow->pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            activeWindow->close();
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