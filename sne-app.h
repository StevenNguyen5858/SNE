#pragma once
#include "sne-page.h"
#include <stack>


class App {
	// Acccess specifier:
public:
	map<string, Page*> pages = {};
	stack<Page*> pageHistory = {};
	Page* activePage = NULL;
	string title = "myapp";

	// Default Constructor:
	App() {}

	void draw() {
		if (activePage == NULL) return;
		activePage->draw();
	}

	void mousePressed(int mX, int mY) {
		if (activePage == NULL) return;
		activePage->mousePressed(mX, mY);
	}

	void mouseMoved(int mX, int mY) {
		if (activePage == NULL) return;
		activePage->mouseMoved(mX, mY);
	}

	void keyPressed(string key) {
		if (activePage == NULL) return;
		activePage->keyPressed(key);
	}

	void addPage(string pathName, Page* page) {
		if (pages.size() == 0) {
			openPage(page);
		}
		page->settings();
		pages[pathName] = page;
	}

	// Add current page to pageHistory stack, update window title to page name, activate and setup() page.
	void openPage(Page* page) {
		activeWindow->setTitle(title + "/" + page->name);
		pageHistory.push(activePage);
		activePage = page;

		page->setup();
	}
};

App app;
