#pragma once
#include "sne-shapes.h"
#include "sne-text.h"
#include "sne-image.h"


void primativeShapesDemo() {
    stroke(255);

    fill(134, 4, 4);
    rect(30, 30, 50, 50);

    fill(111, 4, 4);
    circle(130, 30, 50);

    fill(92, 4, 4);
    triangle(230, 30, 280, 30, 255, 80);

    fill(81, 4, 4);
    line(330, 55, 380, 55);

    int alpha = 175;
    fill(134, 4, 4);
    rect(30, 130, 50, 50, alpha);

    fill(111, 4, 4);
    circle(130, 130, 50, alpha);

    fill(92, 4, 4);
    triangle(230, 130, 280, 130, 255, 180, alpha);

    fill(81, 4, 4);
    line(330, 155, 380, 155, alpha);


    alpha = 100;
    fill(134, 4, 4);
    rect(30, 230, 50, 50, alpha);

    fill(111, 4, 4);
    circle(130, 230, 50, alpha);

    fill(92, 4, 4);
    triangle(230, 230, 280, 230, 255, 280, alpha);

    fill(81, 4, 4);
    line(330, 255, 380, 255, alpha);


    alpha = 25;
    fill(134, 4, 4);
    rect(30, 330, 50, 50, alpha);

    fill(111, 4, 4);
    circle(130, 330, 50, alpha);

    fill(92, 4, 4);
    triangle(230, 330, 280, 330, 255, 380, alpha);

    fill(81, 4, 4);
    line(330, 355, 380, 355, alpha);

    activeWindow->display();
}

void textDemo() {
    textFont(gothamLight);
    textSize(60);

    text("Hello World", 10, 30, 400, 50, alignment::centerY);
    
    // Unlike fill, textFont reverts to a default after each use of text
    text("Hello World", 10, 130, 400, 50, alignment::centerY);

    textFont(gothamBold);
    text("Hello World", 10, 230, 400, 50, alignment::centerY);

    textFont(gothamBoldItalic);
    text("Hello World", 10, 330, 400, 50, alignment::centerY);

    activeWindow->display();
}

void imageDemo() {
    image("sne-resources/cat.jpg", 10, 100, 380, 213);

    activeWindow->display();
}