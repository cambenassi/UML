// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <iostream>
#include <vector>

#include <math.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Triangle.h"

void fTree(std::vector<Triangle> &triangleVec, sf::RenderWindow &window, int &depth, double &length);  // NOLINT

int main(int argc, char* argv[]) {
    if (argc != 3)
        return 1;
    double length = atof(argv[1]);
    int depth = atof(argv[2]);

    std::vector<Triangle> triangleVec;
    sf::RenderWindow window(sf::VideoMode(1400, 1400), "TFractal");

    fTree(triangleVec, window, depth, length);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear();
        for (long unsigned int i = 0; i < triangleVec.size(); i++)
            window.draw(triangleVec[i].triangle);
        window.display();
    }

    return 0;
}

void fTree(std::vector<Triangle> &triangleVec, sf::RenderWindow &window, int &depth, double &length) {  // NOLINT
    std::vector<Triangle> tempVec;

    if (triangleVec.empty()) {
        Triangle tree(length, 700.0, 700.0);
        triangleVec.push_back(tree);
    } else if (depth == 0) {
        return;
    } else if (triangleVec.size() == 1) {
        double centerLeftX, centerLeftY,
            centerRightX, centerRightY,
            centerDownX, centerDownY;

            centerLeftX = (triangleVec[0].centerX - length / 2.0);
            centerLeftY = (triangleVec[0].centerY - ((sqrt(3.0) / 2.0) * length) * 2 / 3);  //NOLINT

            centerRightX = (triangleVec[0].centerX + length * 3.0 / 4.0);
            centerRightY = (triangleVec[0].centerY - ((sqrt(3.0) / 2.0) * length) * 1 / 6);  //NOLINT

            centerDownX = (triangleVec[0].centerX - length * 1.0 / 4.0);
            centerDownY = (triangleVec[0].centerY + ((sqrt(3.0) / 2.0) * length) * 5 / 6);  //NOLINT

            length = length / 2;
            Triangle tempTriangleLeft(length, centerLeftX, centerLeftY);
            Triangle tempTriangleRight(length, centerRightX, centerRightY);
            Triangle tempTriangleDown(length, centerDownX, centerDownY);
            triangleVec.push_back(tempTriangleLeft);
            triangleVec.push_back(tempTriangleRight);
            triangleVec.push_back(tempTriangleDown);

            triangleVec[0].hasChildren = true;
    } else {
        for (auto &iter : triangleVec) {
            if (!iter.hasChildren) {  // will not skip middle past 3
                double centerLeftX, centerLeftY,
                centerRightX, centerRightY,
                centerDownX, centerDownY;

                centerLeftX = (iter.centerX - length / 2.0);
                centerLeftY = (iter.centerY - ((sqrt(3.0) / 2.0) * length) * 2 / 3);  //NOLINT

                centerRightX = (iter.centerX + length * 3.0 / 4.0);
                centerRightY = (iter.centerY - ((sqrt(3.0) / 2.0) * length) * 1 / 6);  //NOLINT

                centerDownX = (iter.centerX - length * 1.0 / 4.0);
                centerDownY = (iter.centerY + ((sqrt(3.0) / 2.0) * length) * 5 / 6);  //NOLINT

                Triangle tempTriangleLeft(length / 2, centerLeftX, centerLeftY);
                Triangle tempTriangleRight(length / 2, centerRightX, centerRightY);  //NOLINT
                Triangle tempTriangleDown(length / 2, centerDownX, centerDownY);

                tempVec.push_back(tempTriangleLeft);
                tempVec.push_back(tempTriangleRight);
                tempVec.push_back(tempTriangleDown);

                Triangle temp = iter;
                temp.hasChildren = true;
                iter = temp;
            }
        }
        length = length / 2;
        triangleVec.insert(triangleVec.end(), tempVec.begin(), tempVec.end());
        tempVec.clear();
    }
    depth -= 1;
    fTree(triangleVec, window, depth, length);
}
