#include <iostream>
#include "edClass.h"

#include <SFML/System.hpp>

int main(int argc, char* argv[]){
    ED test;
    sf::Clock clock;
    sf::Time t;

    std::cin >> test;
    test.~ED();

    t = clock.getElapsedTime();
    std::cout << "\nExecution time is " << t.asSeconds() << " seconds\n";

    return 0;
}