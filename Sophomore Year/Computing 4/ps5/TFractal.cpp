// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Triangle.h"

void fTree(std::vector<Triangle> &triangleVec, sf::RenderWindow &window, int &depth, double length);  // NOLINT

int main(int argc, char* argv[]) {
    if (argc != 3)
        return 1;
    double length = atof(argv[1]);
    int depth = atof(argv[2]);

    std::vector<Triangle> triangleVec;
    sf::RenderWindow window(sf::VideoMode(600, 600), "TFractal");

    fTree(triangleVec, window, depth, length);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear();
        window.draw(triangleVec[0].triangle);
        window.display();
    }

    std::cout << length << std::endl << depth << std::endl;
    return 0;
}

void fTree(std::vector<Triangle> &triangleVec, sf::RenderWindow &window, int &depth, double length) {  // NOLINT
    if (triangleVec.empty()) {
        Triangle tree(length);
        triangleVec.push_back(tree);
    } else {

    }

    depth -= 1;
}
