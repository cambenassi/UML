// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#ifndef SOPHOMORE_YEAR_COMPUTING_4_PS4B_STRINGSOUND_H_
#define SOPHOMORE_YEAR_COMPUTING_4_PS4B_STRINGSOUND_H_

#include <vector>

#include <SFML/System.hpp>

#include "CircularBuffer.h"

class StringSound {
 public:
    // constructors & destructor
    explicit StringSound(double frequency);
    explicit StringSound(std::vector<sf::Int16> init);
    StringSound(const StringSound& obj) {}
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

#endif  // SOPHOMORE_YEAR_COMPUTING_4_PS4B_STRINGSOUND_H_
