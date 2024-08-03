#pragma once
#include "sne-pde.h"


void fill(int r, int g, int b, int a) {
	sf::Color color = sf::Color(r, g, b, a);
	current_fill = color;
}
void fill(int r, int g, int b) {
	sf::Color color = sf::Color(r, g, b, 255);
	current_fill = color;
}
void fill(int greyValue) {
	current_fill = sf::Color(greyValue, greyValue, greyValue, 255);
}
void no_fill() {
	current_fill = sf::Color::Transparent;
}

void stroke(int r, int g, int b, int a) {
	sf::Color color = sf::Color(r, g, b, a);
	current_stroke = color;
}
void stroke(int r, int g, int b) {
	sf::Color color = sf::Color(r, g, b, 255);
	current_stroke = color;
}
void stroke(int greyValue) {
	current_stroke = sf::Color(greyValue, greyValue, greyValue, 255);
}
void no_stroke() {
	current_stroke = sf::Color::Transparent;
}
void stroke_weight(int stroke_weight) {
	current_stroke_weight = stroke_weight;
}

sf::RectangleShape r;
void rect(double x, double y, double w, double h) {
	r.setSize(sf::Vector2f(w, h));
	r.setPosition(x, y);
	r.setFillColor(current_fill);
	r.setOutlineThickness(current_stroke_weight);
	r.setOutlineColor(current_stroke);
	activeWindow->draw(r);
}
void rect(double x, double y, double w, double h, int alpha) {
	r.setSize(sf::Vector2f(w, h));
	r.setPosition(x, y);
	r.setFillColor(sf::Color(current_fill.r, current_fill.g, current_fill.b, alpha));
	r.setOutlineThickness(current_stroke_weight);
	r.setOutlineColor(current_stroke);
	activeWindow->draw(r);
}

sf::CircleShape c;
void circle(double x, double y, double d) {
	c.setRadius(d / 2);
	c.setPointCount(50);
	c.setPosition(x, y);
	c.setFillColor(current_fill);
	c.setOutlineColor(current_stroke);
	c.setOutlineThickness(current_stroke_weight);
	activeWindow->draw(c);
}
void circle(double x, double y, double d, int alpha) {
	c.setRadius(d / 2);
	c.setPointCount(50);
	c.setPosition(x, y);
	c.setFillColor(sf::Color(current_fill.r, current_fill.g, current_fill.b, alpha));
	c.setOutlineColor(current_stroke);
	c.setOutlineThickness(current_stroke_weight);
	activeWindow->draw(c);
}

vector<sf::Vertex> vertices;
sf::Vertex v;
void triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
	vertices.clear();
	v.color = current_fill;

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
	fill(current_fill.r, current_fill.g, current_fill.b, alpha);
	v.color = current_fill;

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
	v.color = current_fill;

	v.position = sf::Vector2f(x1, y1);
	vertices.push_back(v);
	v.position = sf::Vector2f(x2, y2);
	vertices.push_back(v);

	activeWindow->draw(&vertices[0], vertices.size(), sf::Lines);
	vertices.clear();
}
void line(double x1, double y1, double x2, double y2, int alpha) {
	vertices.clear();
	fill(current_fill.r, current_fill.g, current_fill.b, alpha);
	v.color = current_fill;

	v.position = sf::Vector2f(x1, y1);
	vertices.push_back(v);
	v.position = sf::Vector2f(x2, y2);
	vertices.push_back(v);

	activeWindow->draw(&vertices[0], vertices.size(), sf::Lines);
	vertices.clear();
}