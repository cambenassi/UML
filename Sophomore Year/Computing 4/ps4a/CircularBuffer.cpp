#include <iostream>
#include <stdint.h>

#include "CircularBuffer.h"

//Constructors
CircularBuffer::CircularBuffer(int capacity){
    try {
        if(capacity < 1)
            throw std::invalid_argument("CircularBuffer constructor: capacity must be greater than zero.");
    }
    catch (const std::invalid_argument& e){
        std::cout << "CircularBuffer constructor: capacity must be greater than zero.\n";
    }
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
    if(ringBuffer.size() == ringBuffer.__capacity())
        return true;
    else
        return false;
}

void CircularBuffer::enqueue(int16_t x){
    try{
        if (isFull() == true){
            throw std::runtime_error("enqueue: can't enqueue to a full ring");
        }
    }
    catch (const std::runtime_error& e){
        std::cout << "enqueue: can't enqueue to a full ring\n";
    }

    ringBuffer.push_back(x);
}

int16_t CircularBuffer::dequeue(){
    try{
        if (isEmpty() == true){
            throw std::runtime_error("dequeue: can't dequeue to an empty ring");
        }
    }
    catch (const std::runtime_error& e){
        std::cout << "dequeue: can't dequeue to an empty ring\n";
    }
    
    int16_t temp = ringBuffer.front();
    ringBuffer.pop_front();

    return temp;
}

int16_t CircularBuffer::peek(){
    try{
        if (isEmpty() == true){
            throw std::runtime_error("peek: can't peek to an empty ring");
        }
    }
    catch (const std::runtime_error& e){
        std::cout << "peek: can't peek to an empty ring\n";
    }

    int16_t temp = ringBuffer.front();
    return temp;
}