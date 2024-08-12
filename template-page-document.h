#pragma once
#include "sne-application-header.h"
#include "template-page.h"


namespace templatepage {
	vector<Content> titleContents = {
		Content(ContentType::text	, "Hello"),
		Content(ContentType::box	, 50, 50, 200, 50),
		Content(ContentType::fill	, color(255, 0, 0)),
		Content(ContentType::stroke	, color(255, 255, 0)),
	};
	Element title("Template Page Title", titleContents);


	vector<Element*> document = {
		&title
	};

	Page templatePage("template-page", &templatepage::settings, &templatepage::setup, &templatepage::draw, &templatepage::mousePressed, &templatepage::mouseMoved, &templatepage::keyPressed, document);
}