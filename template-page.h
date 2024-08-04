#pragma once
#include "sne-application-header.h"


/*Each page requires the three basic modes from processing.
- settings runs once when the page is added to router.
- setup runs once when the page is opened.
- draw runs continously while the page is open.*/
namespace templatepage {
	void settings();
	void setup();
	void draw();
}

Page templatePage("template-page", &templatepage::settings, &templatepage::setup, &templatepage::draw);


void templatepage::settings() {

}

void templatepage::setup() {
	
}

void templatepage::draw() {
	primativeShapesDemo();
	//textDemo();
	//imageDemo();
}