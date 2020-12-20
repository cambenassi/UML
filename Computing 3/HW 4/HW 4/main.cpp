//
//  main.cpp
//  HW 4
//
//  Created by Cam Benassi on 10/20/20.
//

#include <iostream>
#include "MyComplex.h"
using namespace std;

int main(int argc, const char * argv[]) {
    MyComplex test;
    MyComplex test2 = {9, -4};
    
    cout << "Constructor and Insertion tests:\nTest 1 (default): " << test << "\nTest 2 (9, -4): " << test2 << endl;
    
    test.setReal(2);
    test.setImaginary(3);
    
    cout << "\nAccessor and Mutator tests:\nTest 1: " << test.getReal() << "+" << test.getImaginary() << "i\n\n";
    
    
    return 0;
}
