// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Triangle.h"

// Constructor
Triangle::Triangle(double userLength, int userDepth) {
    length = userLength;
    depth = userDepth;
}

// Member Functions
void Triangle::fTree() {
}

void Triangle::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    // window.draw(triangle_texture);
}
