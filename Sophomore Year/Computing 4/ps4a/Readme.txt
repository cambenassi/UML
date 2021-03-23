/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Cameron Benassi


Hours to complete assignment: 1.5

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

In this assignment, I was tasked with creating test.cpp, CircularBuffer.cpp,
and CircularBuffer.h, which housed a CircularBuffer class, along with tests from
Boost Library to test said class. Tests were performed to make sure member functions
worked when they should, and threw exceptions when they should.



/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

In this assignment, I used classes along with a vector to implement what was required.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

Classes:
-Defined class "CircularBuffer"
-Has member functions along with data member (vector of ints, RingBuffer)
"class CircularBuffer{
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
};"

Vector:
-Data member of "CircularBuffer"
-Implemented enqueue and dequeue functions, along with other functions to pull
info from it

"std::vector<int16_t> ringBuffer;"



/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

Yes, I completed the whole assignment successfuly. I know that all of my 
code works, because the tests that implemented with Boost, along with some
I did before I wrote those, in a second .cpp file.


/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

Yes it does, because when ran, Boost says that there are zero issues
and all of my tests pass.



/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/

Time and space performance of ringBuffer = o(N)


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

none


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

none

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/