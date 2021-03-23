// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#ifndef _HOME_CAMBENASSI_DOCUMENTS_CODE_COMPUTING_IV_PS4A_CIRCULARBUFFER_H_
#define _HOME_CAMBENASSI_DOCUMENTS_CODE_COMPUTING_IV_PS4A_CIRCULARBUFFER_H_

#include <stdint.h>
#include <vector>

class CircularBuffer{
 public:
        explicit CircularBuffer(int capacity);
        int size();
        bool isEmpty();
        bool isFull();
        void enqueue(int16_t x);
        int16_t dequeue();
        int16_t peek();

        // Data member
        std::vector<int16_t> ringBuffer;
};


#endif  // _HOME_CAMBENASSI_DOCUMENTS_CODE_COMPUTING_IV_PS4A_CIRCULARBUFFER_H_
