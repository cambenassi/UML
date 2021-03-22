#include <iostream>
#include <stdint.h>
#include <bits/stdc++.h>

#include "CircularBuffer.h"

//Constructors
CircularBuffer::CircularBuffer(int capacity){
    if(capacity < 1)
        throw std::invalid_argument("CircularBuffer constructor: capacity must be greater than zero.");
    

    ringBuffer.resize(capacity);
    ringBuffer.clear();
}

int CircularBuffer::size(){
    return ringBuffer.size();
}

bool CircularBuffer::isEmpty(){
    if (ringBuffer.empty())
        return true;
    else
        return false;
}

bool CircularBuffer::isFull(){
    if(ringBuffer.size() == ringBuffer.capacity())
        return true;
    else
        return false;
}

void CircularBuffer::enqueue(int16_t x){
    if (isFull() == true)
        throw std::runtime_error("enqueue: can't enqueue to a full ring");
        

    ringBuffer.push_back(x);
}

int16_t CircularBuffer::dequeue(){
    if (isEmpty() == true)
        throw std::runtime_error("dequeue: can't dequeue to an empty ring");
       
    int16_t temp = ringBuffer.front();
    ringBuffer.erase(ringBuffer.begin());

    return temp;
}

int16_t CircularBuffer::peek(){
    if (isEmpty())
        throw std::runtime_error("peek: can't peek to an empty ring");

    int16_t temp = ringBuffer.front();
    return temp;
}