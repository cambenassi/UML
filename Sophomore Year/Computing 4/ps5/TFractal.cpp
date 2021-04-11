// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Triangle.h"

int main(int argc, char* argv[]) {
    if (argc != 3)
        return 1;

    Triangle tree(atof(argv[1]), atof(argv[2]));


    return 0;
}
