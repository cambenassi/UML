// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Triangle.h"

// Constructor
Triangle::Triangle(double sideLength) {
    length = sideLength;

    sf::VertexArray temp(sf::LineStrip, 4);
    temp[0].position = sf::Vector2f(150.f, 150.f);
    temp[1].position = sf::Vector2f(450.f, 150.f);
    temp[2].position = sf::Vector2f(300.f, 400.f);
    temp[3].position = temp[0].position;

    triangle = temp;
}

// Member Functions
void Triangle::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    // window.draw(triangle_texture);
}
