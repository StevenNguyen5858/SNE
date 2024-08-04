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
	void mousePressed(int mX, int mY);
	void mouseMoved(int mX, int mY);
	void keyPressed(string key);
}

Page templatePage("template-page", &templatepage::settings, &templatepage::setup, &templatepage::draw, &templatepage::mousePressed, &templatepage::mouseMoved, &templatepage::keyPressed);


void templatepage::settings() {

}

void templatepage::setup() {
	
}

void templatepage::draw() {
	primativeShapesDemo();
	//textDemo();
	//imageDemo();
}


void templatepage::mousePressed(int mX, int mY) {
	cout << "Mouse clicked: (" << mX << ", " << mY << ")" << endl;
}

void templatepage::mouseMoved(int mX, int mY) {

}

void templatepage::keyPressed(string key) {

}