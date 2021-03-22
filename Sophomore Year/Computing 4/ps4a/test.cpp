#include <iostream>
#include <stdint.h>

#include "CircularBuffer.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE main
#include <boost/test/unit_test.hpp>

int main(int argc, char* argv[]){

    CircularBuffer test(1);
    test.peek();


    return 0;
}