#pragma once
#include "sne-processing-header.h"


class Page {
	// Access specifier:
public:
	string name = "page";
	void (*settingsF)() = NULL;
	void (*setupF)() = NULL;
	void (*drawF)() = NULL;
	void (*mousePressedF)(int mX, int mY) = NULL;
	void (*mouseMovedF)(int mX, int mY) = NULL;
	void (*keyPressedF)(string key) = NULL;

	// Default Constructor:
	Page(){}

	// Basic processing page:
	Page(string name, void (*settings)(), void (*setup)(), void (*draw)()) {
		this->name = name;
		this->settingsF = settings;
		this->setupF = setup;
		this->drawF = draw;
	}

	// App page with event handling:
	Page(string name, void (*settings)(), void (*setup)(), void (*draw)(), void (*mousePressedF)(int mX, int mY), void (*mouseMovedF)(int mX, int mY), void (*keyPressedF)(string key)) {
		this->name = name;
		this->settingsF = settings;
		this->setupF = setup;
		this->drawF = draw;
		this->mousePressedF = mousePressedF;
		this->mouseMovedF = mouseMovedF;
		this->keyPressedF = keyPressedF;
	}
	
	void settings() {
		settingsF();
	}

	void setup() {
		setupF();
	}

	void draw() {
		drawF();
	}

	void mousePressed(int mX, int mY) {
		mousePressedF(mX, mY);
	}

	void mouseMoved(int mX, int mY) {
		mouseMovedF(mX, mY);
	}

	void keyPressed(string key) {
		keyPressedF(key);
	}
};
