// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#ifndef  TRIANGLE_H_
#define  TRIANGLE_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Triangle : public sf::Drawable{
 public:
    explicit Triangle(double sideLength, double x, double y);
    sf::VertexArray triangle;
    double length, centerX, centerY;
    bool hasChildren = false;
 private:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;  // NOLINT
};

// SOPHOMORE_YEAR_COMPUTING_4_PS5_TRIANGLE_H_
#endif  // TRIANGLE_H_
