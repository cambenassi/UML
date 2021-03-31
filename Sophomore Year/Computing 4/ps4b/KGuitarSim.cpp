#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "CircularBuffer.h"
#include "StringSound.h"

#define SAMPLES_PER_SEC 44100
#define CONCERT 440.0

std::vector<sf::Int16> makeSamples(StringSound &gs);

int main(int argc, char* argv[]){
    sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound Lite");
    sf::Event event;
    sf::Sound tempSound;
    sf::SoundBuffer tempBuf;
    std::vector<sf::Int16> samples;
    std::vector<sf::Sound> sounds;
    std::string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
    double freq;

    for(int i = 0; i < keys.size(); i++){
        freq = CONCERT * pow(2, (i - 24) / 12);
        StringSound tempStringSound(freq);

        samples = makeSamples(tempStringSound);
        tempBuf.loadFromSamples(&samples[i], samples.size(), 2, SAMPLES_PER_SEC);
        tempSound.setBuffer(tempBuf);
        sounds.push_back(tempSound);

        samples.clear();
    }

    while (window.isOpen()){
        while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed) 
    			window.close();
			else if (event.type == sf::Event::TextEntered){
        			if (event.text.unicode < 128){
          				char key = static_cast<char>(event.text.unicode);  
          				for (int x = 0; x < (signed)keys.size(); x++) {
            				if (keys[x] == key){
              					sounds[x].play();
              					break;
            				}
          				}
        			}
      			}
    		}
	window.clear();
 	window.display();
  	}

    return 0;
}

std::vector<sf::Int16> makeSamples(StringSound &gs) {
  std::vector<sf::Int16> samples;

  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}