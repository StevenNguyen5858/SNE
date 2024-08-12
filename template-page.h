#pragma once
#include "sne-application-header.h"


namespace templatepage {
	void settings();
	void setup();
	void draw();
	void mousePressed(int mX, int mY);
	void mouseMoved(int mX, int mY);
	void keyPressed(string key);

	// If using UI implementation, comment the below initialization and uncomment the initialization from the page's document file.
	// Page templatePage("template-page", &templatepage::settings, &templatepage::setup, &templatepage::draw, &templatepage::mousePressed, &templatepage::mouseMoved, &templatepage::keyPressed);
}


#pragma region Template instructions: How to create a page
/*	To create a processing page:
*	- Reference the "template-page" folder to create base files (only one page file for processing is necessary).
*	- Use a unique namespace name to define your page. Re-name the Page object similarly.
*	- Each page implements the three basic modes from processing: Settings, Setup, and Draw. Code may be placed in these "mode" functions to act as drivers.
*	- Each page implements various events such as mousePressed, keyPressed, and mouseMoved. Code may be placed in these event functions for event based actions.
* 
*	To create a processing page with UI:
*	- Follow the above steps first, thenn create an additional file for the document.
*	- Comment out the Page templatePage initialization in this file and uncomment the initialization from the document file.
*/
#pragma endregion


#pragma region Processing Modes: Settings Setup Draw
// Settings runs once when the page is added to router.
void templatepage::settings() {
	
}

// Setup runs once when the page is opened.
void templatepage::setup() {
	
}

// Draw runs continously while the page is open.
void templatepage::draw() {
	primativeShapesDemo();
}
#pragma endregion


#pragma region Event Handling
void templatepage::mousePressed(int mX, int mY) {
	cout << "(Event) | Mouse Pressed: (" << mX << ", " << mY << ")" << endl;
}

void templatepage::mouseMoved(int mX, int mY) {

}

void templatepage::keyPressed(string key) {
	cout << "(Event) | Key Pressed: (" << key << ")" << endl;
}
#pragma endregion