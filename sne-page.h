#pragma once
#include "sne-processing-header.h"


class Page {
	// Access specifier:
public:
	string name = "page";
	void (*settingsF)() = NULL;
	void (*setupF)() = NULL;
	void (*drawF)() = NULL;

	// Default Constructor:
	Page(){}

	// Basic processing page:
	Page(string name, void (*settings)(), void (*setup)(), void (*draw)()) {
		this->name = name;
		this->settingsF = settings;
		this->setupF = setup;
		this->drawF = draw;
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
};
