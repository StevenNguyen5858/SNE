#pragma once
#include "sne-application-header.h"


/*Each page requires the three basic modes from processing.
- settings runs once when the page is added to router.
- setup runs once when the page is opened.
- draw runs continously while the page is open.*/
namespace templatepage2 {
	void settings();
	void setup();
	void draw();
	void mousePressed(int mX, int mY);
	void mouseMoved(int mX, int mY);
	void keyPressed(string key);
}

Page templatePage2("template-page2", &templatepage2::settings, &templatepage2::setup, &templatepage2::draw, &templatepage2::mousePressed, &templatepage2::mouseMoved, &templatepage2::keyPressed);


void templatepage2::settings() {

}

void templatepage2::setup() {

}

void templatepage2::draw() {

}


void templatepage2::mousePressed(int mX, int mY) {

}

void templatepage2::mouseMoved(int mX, int mY) {

}

void templatepage2::keyPressed(string key) {

}