#pragma once
#include "sne-pde.h"


void fill(int r, int g, int b, int a) {
	sf::Color color = sf::Color(r, g, b, a);
	currentFill = color;
}
void fill(int r, int g, int b) {
	sf::Color color = sf::Color(r, g, b, 255);
	currentFill = color;
}
void fill(int greyValue) {
	currentFill = sf::Color(greyValue, greyValue, greyValue, 255);
}
void no_fill() {
	currentFill = sf::Color::Transparent;
}

void stroke(int r, int g, int b, int a) {
	sf::Color color = sf::Color(r, g, b, a);
	currentStroke = color;
}
void stroke(int r, int g, int b) {
	sf::Color color = sf::Color(r, g, b, 255);
	currentStroke = color;
}
void stroke(int greyValue) {
	currentStroke = sf::Color(greyValue, greyValue, greyValue, 255);
}
void no_stroke() {
	currentStroke = sf::Color::Transparent;
}
void stroke_weight(int stroke_weight) {
	currentStrokeWeight = stroke_weight;
}

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
sf::Vertex v;
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