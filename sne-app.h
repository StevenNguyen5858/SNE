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
		if (activePage != NULL) {
			activePage->draw();
		}
	}

	void addPage(string pathName, Page* page) {
		if (pages.size() == 0) {
			openPage(page);
		}
		page->settings();
		pages[pathName] = page;
	}

	void openPage(Page* page) {
		activeWindow->setTitle(title + "/" + page->name);
		pageHistory.push(activePage);
		activePage = page;

		page->setupF();
	}
};

App app;