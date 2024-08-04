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
}

Page templatePage2("template-page2", &templatepage2::settings, &templatepage2::setup, &templatepage2::draw);


void templatepage2::settings() {

}

void templatepage2::setup() {

}

void templatepage2::draw() {

}