// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Triangle.h"

// Constructor
Triangle::Triangle(double sideLength, double x, double y) {
    length = sideLength;
    centerX = x;
    centerY = y;
    double height = (sqrt(3) / 2) * sideLength;

    sf::VertexArray temp(sf::LineStrip, 4);
    temp[0].position = sf::Vector2f(x - sideLength / 2.0, y - height / 3.0);
    temp[1].position = sf::Vector2f(x + sideLength / 2.0, y - height / 3.0);
    temp[2].position = sf::Vector2f(x, y + height * (2.0 / 3.0));
    temp[3].position = temp[0].position;
    for (int i = 0; i <= 3; i++)
        temp[i].color = sf::Color::Red;
    triangle = temp;
}

// Member Functions
void Triangle::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    // window.draw(triangle_texture);
}
