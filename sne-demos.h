#pragma once
#include "sne-header.h"


void primativeShapesDemo() {
    fill(134, 4, 4);
    rect(30, 30, 50, 50);

    fill(111, 4, 4);
    circle(130, 30, 50);

    fill(92, 4, 4);
    triangle(230, 30, 280, 30, 255, 80);

    fill(81, 4, 4);
    line(330, 55, 380, 55);
    activeWindow->display();
}
