#include <iostream>
#include <stdint.h>

#include "CircularBuffer.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

//tests fail-safes for peek, isEmpty
BOOST_AUTO_TEST_CASE(peekEmptyTest){
    CircularBuffer test(1);
    BOOST_REQUIRE_THROW(test.peek(), std::runtime_error);
}

//tests fail-safes for enqueue, isFull
BOOST_AUTO_TEST_CASE(enqueueFullTest){
    CircularBuffer test(1);
    test.enqueue(1);
    BOOST_REQUIRE_THROW(test.enqueue(1), std::runtime_error);
}

//tests fail-safes for dequeue, isEmpty
BOOST_AUTO_TEST_CASE(dequeueEmptyTest){
    CircularBuffer test(1);
    BOOST_REQUIRE_THROW(test.dequeue(), std::runtime_error);
}

//tests that enqueue works
BOOST_AUTO_TEST_CASE(enqueueTest){
    CircularBuffer test(2);
    BOOST_REQUIRE_NO_THROW(test.enqueue(1));
}

//tests that dequeue works
BOOST_AUTO_TEST_CASE(dequeueTest){
    CircularBuffer test(2);
    test.enqueue(1);
    BOOST_REQUIRE_NO_THROW(test.dequeue());
}