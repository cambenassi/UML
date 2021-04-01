// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#ifndef StringSound_h
#define StringSound_h

#include <vector>

#include <SFML/System.hpp>

#include "CircularBuffer.h"

class StringSound {
 public:
    // constructors & destructor
    explicit StringSound(double frequency);
    explicit StringSound(std::vector<sf::Int16> init);
    StringSound (const StringSound& obj) {};
    ~StringSound();
    // Member functions
    void pluck();
    void tic();
    sf::Int16 sample();
    int time();
// data members
 private:
    CircularBuffer* _cb;
    int _time;
};

#endif  // file path