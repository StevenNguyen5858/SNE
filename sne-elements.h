#pragma once
#include "sne-processing-header.h"
#include <variant> 


// TODO (Dynamic map based events in Element Object).
/*	void (*mousePressedF)(int mX, int mY) = NULL;
	void (*mouseMovedF)(int mX, int mY) = NULL;
	void (*keyPressedF)(string key) = NULL;
	bool canClick = false;
	bool canHover = false;
	bool canType = false;
*/
enum eventdirective {
	click = 0,
	mousemove = 1,
	keypress = 2,
};


// Bounding click-box of an Elemment.
class Box {
public:
	int x = -1;
	int y = -1;
	int w = 0;
	int h = 0;

	Box() {};
	Box(int x, int y, int w, int h) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
};


// Used to properly classify Content for use in Element objects.
enum class ContentType {
	text,
	box,
	fill,
	stroke,
	strokeWeight,
};


// Used to dynamically build parts of a UI Element object.
class Content {
public:
	variant<string, Box, sf::Color> data;
	ContentType type;

	Content() {};

	// Expect type: text
	Content(ContentType type, string str) {
		this->type = type;
		this->data = str;
	};

	// Expeccted type: box
	Content(ContentType type, int x, int y, int w, int h) {
		this->type = type;
		this->data = Box(x, y, w, h);
	};

	// Expected types: fill, stroke
	Content(ContentType type, sf::Color c) {
		this->type = type;
		this->data = c;
	};
};


class Element {
	// Access specifier:
public:
	string name = "element";

	// Dynamic Element components
	vector<Content> contents = {};
	string text = "";
	Box box;
	sf::Color fillColor = sf::Color(255, 255, 255);
	sf::Color strokeColor = sf::Color(255, 255, 255);

	// Default Constructor
	Element() {}

	// Create empty element. Useful for testing Element object has been added to Page.
	Element(string name) {
		this->name = name;
	}

	// Dynamically create an element.
	Element(string name, vector<Content> contents) {
		this->name = name;
		this->contents = contents;
		populateContents();
	}

	// Assign Element attributes after vector<Content> contents is initialized.
	void populateContents() {
		for (int i = 0; i < contents.size(); i++){
			Content c = contents[i];
			if (c.type == ContentType::box) {
				this->box = get<Box>(c.data);
			}
			if (c.type == ContentType::text) {
				this->text = get<string>(c.data);
			}
			if (c.type == ContentType::fill) {
				this->fillColor = get<sf::Color>(c.data);
			}
			if (c.type == ContentType::stroke) {
				this->strokeColor = get<sf::Color>(c.data);
			}
		}
	}

	void draw() {
		if (!this->text.empty()) {
			fill(fillColor);
			cout << this->text << endl;
		}
		if (this->box.x != -1) {
			fill(fillColor);
			stroke(strokeColor);
			rect(box.x, box.y, box.w, box.h);
		}
	}
};