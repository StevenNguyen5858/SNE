#pragma once
#include "sne-pde.h"


sf::Texture tempTexture;
sf::Sprite sprite;
sf::Image tempImage;
map<string, sf::Sprite> loadedSprites;

void image(string imgPath, double x, double y) {
	if (loadedSprites.find(imgPath) == loadedSprites.end()) {
		if (!tempImage.loadFromFile(imgPath)) {
			sf::err() << "Couldn't load " << imgPath << endl;
		} else {
			sprite.setPosition(sf::Vector2f(int(x), int(y)));
			tempTexture.loadFromImage(tempImage);
			sprite.setTexture(tempTexture);
			loadedSprites[imgPath] = sprite;
			activeWindow->draw(sprite);
		}
	}
	else {
		sprite = loadedSprites[imgPath];
		sprite.setPosition(sf::Vector2f(int(x), int(y)));
		activeWindow->draw(sprite);
	}
}

void image(string imgPath, double x, double y, double new_width, double new_height) {
	if (loadedSprites.find(imgPath) == loadedSprites.end()) {
		if (!tempImage.loadFromFile(imgPath)) {
			sf::err() << "Couldn't load " << imgPath << endl;
		}
		else {
			sprite.setPosition(sf::Vector2f(int(x), int(y)));
			tempTexture.loadFromImage(tempImage);
			sprite.setTexture(tempTexture);
			loadedSprites[imgPath] = sprite;

			double scaleW = (float)(new_width) / sprite.getTextureRect().getSize().x;
			double scaleH = (float)(new_height) / sprite.getTextureRect().getSize().y;
			sprite.setScale(sf::Vector2f(scaleW, scaleH));

			activeWindow->draw(sprite);
		}
	}
	else {
		sprite = loadedSprites[imgPath];
		sprite.setPosition(sf::Vector2f(int(x), int(y)));

		double scaleW = (float)(new_width) / sprite.getTextureRect().getSize().x;
		double scaleH = (float)(new_height) / sprite.getTextureRect().getSize().y;
		sprite.setScale(sf::Vector2f(scaleW, scaleH));

		activeWindow->draw(sprite);
	}
}

// Draws an sf::image object to buffer at default image size.
void image(sf::Image* img, double x, double y) {
	sprite.setPosition(sf::Vector2f(int(x), int(y)));
	tempTexture.loadFromImage(*img);
	sprite.setTexture(tempTexture);
	activeWindow->draw(sprite);
}

// Draws an sf::image object to buffer with given width and height. Images scale best by factors of two.
void image(sf::Image* img, double x, double y, double newWidth, double newHeight) {
	sprite.setPosition(sf::Vector2f(int(x), int(y)));
	tempTexture.loadFromImage(*img);
	sprite.setTexture(tempTexture);

	double scaleW = (float)(newWidth) / img->getSize().x;
	double scaleH = (float)(newHeight) / img->getSize().y;
	sprite.setScale(sf::Vector2f(scaleW, scaleH));

	activeWindow->draw(sprite);
}
