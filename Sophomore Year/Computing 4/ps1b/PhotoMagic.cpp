#include <iostream>
#include "FibLFSR.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
 
using namespace std;

void transform(sf::Image& image, FibLFSR* seed);

int main(int argc, char* argv[]){
    //get file names & seed, call transform, then save
    sf::Image image;
    if(!image.loadFromFile(argv[1]))
        return -1;
    FibLFSR seed = {argv[3]};

    transform(image, &seed);
    
    if(!image.saveToFile(argv[2]))
        return -1;

    //creating windows
    sf::Vector2u size = image.getSize();
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original");
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encrypted");
    
    sf::Texture originalText;
    originalText.loadFromFile(argv[1]);
    sf::Texture encryptedText;
	encryptedText.loadFromImage(image);
    
    sf::Sprite originalSprite;
    originalSprite.setTexture(originalText);
	sf::Sprite encryptedSprite;
	encryptedSprite.setTexture(encryptedText);
    
    while (window1.isOpen() && window2.isOpen()) { 
        sf::Event event;
        while (window1.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(originalSprite);
        window1.display();
        window2.clear();
        window2.draw(encryptedSprite);
        window2.display();
    }

    return 0;
}

void transform(sf::Image& image, FibLFSR* seed){
    sf::Color p;
    sf::Vector2u size = image.getSize();

    for(unsigned int y = 0; y < size.y; y++){
        for (unsigned int x = 0; x < size.x; x++){
            p = image.getPixel(x, y);
            p.r ^= seed->generate(8);;
            p.b ^= seed->generate(8);;
            p.g ^= seed->generate(8);;
            image.setPixel(x, y, p);
        }
    }

}