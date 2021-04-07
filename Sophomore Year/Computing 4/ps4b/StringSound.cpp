// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include "StringSound.h"

#include <math.h>
#include <stdlib.h>
#include <random>

#include <iostream>

// Constructors
StringSound::StringSound(double frequency) {
    _cb = new CircularBuffer(ceil(frequency));

    for (int i = 0; i < ceil(frequency); i++) {
        _cb->enqueue(0);
    }

    _time = 0;
}

StringSound::StringSound(std::vector<sf::Int16> init) {
    if (init.empty())
        throw std::bad_alloc();

    _cb = new CircularBuffer(init.size());

    std::for_each(init.begin(), init.end(),
        [this, init](unsigned int i){_cb->enqueue(init[i]);});

    _time = 0;
}

StringSound::~StringSound() {
    delete _cb;
}

// Member functions
void StringSound::pluck() {
    while (!_cb->isEmpty())
        _cb->dequeue();

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(-32768, 32767);
    while (!_cb->isFull()) {
        int random = distribution(generator);
        _cb->enqueue(random);
    }
}

void StringSound::tic() {
    int16_t first, second;

    first = _cb->dequeue();
    second = _cb->peek();

    _cb->enqueue(.996 * .5 * (first + second));
}

sf::Int16 StringSound::sample() {
    return _cb->peek();
}

int StringSound::time() {
    return _time;
}

