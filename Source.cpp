#pragma once
#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML Application Template");
    sf::Event e;

    while (window.isOpen()) {
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

	return 0;
}