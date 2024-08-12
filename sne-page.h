#pragma once
#include "sne-processing-header.h"
#include "sne-elements.h"

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
	vector<Element*> document = {};

	// Default Constructor:
	Page() {}

	// Basic processing page:
	Page(string name, void (*settings)(), void (*setup)(), void (*draw)()) {
		this->name = name;
		this->settingsF = settings;
		this->setupF = setup;
		this->drawF = draw;
	}

	// Proccessing page with event handling:
	Page(string name, void (*settings)(), void (*setup)(), void (*draw)(), void (*mousePressedF)(int mX, int mY), void (*mouseMovedF)(int mX, int mY), void (*keyPressedF)(string key)) {
		this->name = name;
		this->settingsF = settings;
		this->setupF = setup;
		this->drawF = draw;
		this->mousePressedF = mousePressedF;
		this->mouseMovedF = mouseMovedF;
		this->keyPressedF = keyPressedF;
	}

	// Proccessing page + UI
	Page(string name, void (*settings)(), void (*setup)(), void (*draw)(), void (*mousePressedF)(int mX, int mY), void (*mouseMovedF)(int mX, int mY), void (*keyPressedF)(string key), vector<Element*> document) {
		this->name = name;
		this->settingsF = settings;
		this->setupF = setup;
		this->drawF = draw;
		this->mousePressedF = mousePressedF;
		this->mouseMovedF = mouseMovedF;
		this->keyPressedF = keyPressedF;
		this->document = document;
	}

	#pragma region Processing Modes: Settings Setup Draw
	void settings() {
		settingsF();
	}

	void setup() {
		setupF();
	}

	void draw() {
		drawF();
		drawUI();
	}
	#pragma endregion

	#pragma region Event Handling
	void mousePressed(int mX, int mY) {
		mousePressedF(mX, mY);
	}

	void mouseMoved(int mX, int mY) {
		mouseMovedF(mX, mY);
	}

	void keyPressed(string key) {
		keyPressedF(key);
	}
	#pragma endregion

	#pragma region UI Helper Methods
	void drawUI() {
		for (int i = 0; i < document.size(); i++) {
			// cout << "Draw | Element | " << document[i]->name << endl;
			document[i]->draw();
		}
	}

	void addElement(Element* e) {
		document.push_back(e);
	}
	#pragma endregion
};
