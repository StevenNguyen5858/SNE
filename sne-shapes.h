#pragma once
#include "sne-pde.h"


sf::RectangleShape r;
void rect(double x, double y, double w, double h) {
	r.setSize(sf::Vector2f(w, h));
	r.setPosition(x, y);
	r.setFillColor(currentFill);
	r.setOutlineThickness(currentStrokeWeight);
	r.setOutlineColor(currentStroke);
	activeWindow->draw(r);
}

void rect(double x, double y, double w, double h, int alpha) {
	r.setSize(sf::Vector2f(w, h));
	r.setPosition(x, y);
	r.setFillColor(sf::Color(currentFill.r, currentFill.g, currentFill.b, alpha));
	r.setOutlineThickness(currentStrokeWeight);
	r.setOutlineColor(currentStroke);
	activeWindow->draw(r);
}


sf::CircleShape c;
void circle(double x, double y, double d) {
	c.setRadius(d / 2);
	c.setPointCount(50);
	c.setPosition(x, y);
	c.setFillColor(currentFill);
	c.setOutlineColor(currentStroke);
	c.setOutlineThickness(currentStrokeWeight);
	activeWindow->draw(c);
}

void circle(double x, double y, double d, int alpha) {
	c.setRadius(d / 2);
	c.setPointCount(50);
	c.setPosition(x, y);
	c.setFillColor(sf::Color(currentFill.r, currentFill.g, currentFill.b, alpha));
	c.setOutlineColor(currentStroke);
	c.setOutlineThickness(currentStrokeWeight);
	activeWindow->draw(c);
}


vector<sf::Vertex> vertices;
vector<sf::Vertex> vertices2;
sf::Vertex v;

sf::Vector2f vf(double x, double y) {
	return sf::Vector2f(x, y);
}

void addVertex(double x, double y) {
	v.position = vf(int(x), int(y));
	vertices.push_back(v);
}

void triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
	vertices.clear();
	v.color = currentFill;

	v.position = sf::Vector2f(x1, y1);
	vertices.push_back(v);
	v.position = sf::Vector2f(x2, y2);
	vertices.push_back(v);
	v.position = sf::Vector2f(x3, y3);
	vertices.push_back(v);

	activeWindow->draw(&vertices[0], vertices.size(), sf::Triangles);
	vertices.clear();
}

void triangle(double x1, double y1, double x2, double y2, double x3, double y3, int alpha) {
	vertices.clear();
	fill(currentFill.r, currentFill.g, currentFill.b, alpha);
	v.color = currentFill;

	v.position = sf::Vector2f(x1, y1);
	vertices.push_back(v);
	v.position = sf::Vector2f(x2, y2);
	vertices.push_back(v);
	v.position = sf::Vector2f(x3, y3);
	vertices.push_back(v);

	activeWindow->draw(&vertices[0], vertices.size(), sf::Triangles);
	vertices.clear();
}

void line(double x1, double y1, double x2, double y2) {
	vertices.clear();
	v.color = currentFill;

	v.position = sf::Vector2f(x1, y1);
	vertices.push_back(v);
	v.position = sf::Vector2f(x2, y2);
	vertices.push_back(v);

	activeWindow->draw(&vertices[0], vertices.size(), sf::Lines);
	vertices.clear();
}

void line(double x1, double y1, double x2, double y2, int alpha) {
	vertices.clear();
	fill(currentFill.r, currentFill.g, currentFill.b, alpha);
	v.color = currentFill;

	v.position = sf::Vector2f(x1, y1);
	vertices.push_back(v);
	v.position = sf::Vector2f(x2, y2);
	vertices.push_back(v);

	activeWindow->draw(&vertices[0], vertices.size(), sf::Lines);
	vertices.clear();
}

void roundedRectangleHelper(double x, double y, double w, double h, int r, int strokeWeight, int pointCount = 0) {
	strokeWeight = abs(strokeWeight);
	vertices.clear();
	v.color = (strokeWeight != 0)? currentFill : currentStroke;
	int cornerPointCount = (pointCount == 0)? 190 : pointCount;
	double degreesShort = 0.18;
	double pi = 2 * acos(0.0);

	int xPos;
	int yPos;
	int cornerCenterX;
	int cornerCenterY;
	int centerX = int(x + (w / 2));
	int centerY = int(y + (h / 2));
	
	// Center
	addVertex(centerX, centerY);

	// Top Right Corner
	cornerCenterX = (x + w) - r;
	cornerCenterY = (y + r);
	for (double i = pi / 2 - degreesShort; i > degreesShort; i = i - (pi / 2) / cornerPointCount) {
		xPos = cornerCenterX + abs(cos(i) * r);
		yPos = cornerCenterY - abs(sin(i) * r);
		addVertex(xPos - strokeWeight, yPos + strokeWeight);
	}

	// Bottom Right Corner
	cornerCenterX = (x + w) - r;
	cornerCenterY = (y + h) - r;
	for (double i = 2 * pi - degreesShort; i > (3.0 / 2.0 * pi) + degreesShort; i = i - (pi / 2) / cornerPointCount) {
		xPos = cornerCenterX + abs(cos(i) * r);
		yPos = cornerCenterY + abs(sin(i) * r);
		addVertex(xPos - strokeWeight, yPos - strokeWeight);
	}

	// Bottom Left Corner
	cornerCenterX = x + r;
	cornerCenterY = (y + h) - r;
	for (double i = (3.0 / 2.0 * pi) - degreesShort; i > pi + degreesShort; i = i - (pi / 2) / cornerPointCount) {
		xPos = cornerCenterX - abs(cos(i) * r);
		yPos = cornerCenterY + abs(sin(i) * r);
		addVertex(xPos + strokeWeight, yPos - strokeWeight);
	}

	// Top Left Corner
	cornerCenterX = x + r;
	cornerCenterY = y + r;
	for (double i = pi - degreesShort; i > pi / 2 + degreesShort; i = i - (pi / 2) / cornerPointCount) {
		xPos = cornerCenterX - abs(cos(i) * r);
		yPos = cornerCenterY - abs(sin(i) * r);
		addVertex(xPos + strokeWeight, yPos + strokeWeight);
	}

	// Top Right Corner
	cornerCenterX = (x + w) - r;
	cornerCenterY = (y + r);
	xPos = cornerCenterX + abs(cos(pi / 2 - degreesShort) * r);
	yPos = cornerCenterY - abs(sin(pi / 2 - degreesShort) * r);
	addVertex(xPos - strokeWeight, yPos + strokeWeight);
}

void roundedRectangle(double x, double y, double w, double h, int r, int pointCount = 0) {
	int shortestSide = (w < h) ? w : h;
	r = (r * 2 < shortestSide) ? r : shortestSide / 2;

	// Stroke outline
	roundedRectangleHelper(x, y, w, h, r, 0, pointCount);
	activeWindow->draw(&vertices[0], vertices.size(), sf::TriangleFan);

	if (currentStroke == currentFill) {
		vertices.clear();
		return;
	}

	// Inner rounded rectangle
	roundedRectangleHelper(x, y, w, h, r - abs(currentStrokeWeight), currentStrokeWeight, pointCount);
	activeWindow->draw(&vertices[0], vertices.size(), sf::TriangleFan);

	vertices.clear();
}
