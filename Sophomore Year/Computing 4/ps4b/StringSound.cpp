// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include "StringSound.h"

#include <math.h>

#include <iostream>

// Constructors
StringSound::StringSound(double frequency) {
    _cb = new CircularBuffer(ceil(frequency));
    
    for(int i = 0; i < ceil(frequency); i++){
        _cb->enqueue(0);
    }

    _time = 0;
}

StringSound::StringSound(std::vector<sf::Int16> init){
    _cb = new CircularBuffer(init.size());

    for(long unsigned int i = 0; i < init.size(); i++){
        _cb->enqueue(init.at(i));
    }

    _time = 0;
}

StringSound::~StringSound(){
    delete _cb;
}

// Member functions
void StringSound::pluck(){
    while(!_cb->isEmpty())
        _cb->dequeue();
    

    while(!_cb->isFull()){
        int random = rand() % (32767 + 1 - -32768) + -32768;
        _cb->enqueue(random);
    }
}

void StringSound::tic(){
    int16_t first, second;

    first = _cb->dequeue();
    second = _cb->peek();

    _cb->enqueue(.996 * .5 * (first + second));

}

sf::Int16 StringSound::sample(){
    return _cb->peek();
}

int StringSound::time(){
    return _time;
}
