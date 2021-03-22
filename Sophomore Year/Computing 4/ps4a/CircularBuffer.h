#ifndef CircularBuffer_h
#define CircularBuffer_h

#include <vector>
#include <stdint.h>

class CircularBuffer{
    public:
        CircularBuffer(int capacity);
        int size();
        bool isEmpty();
        bool isFull();
        void enqueue(int16_t x);
        int16_t dequeue();
        int16_t peek();

        //data member
        std::vector<int16_t> ringBuffer;
};


#endif