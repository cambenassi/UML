//
//  main.cpp
//  HW 5
//
//  Created by Cam Benassi on 10/20/20.
//

#include <iostream>
#include "MyComplex.h"
using namespace std;

int main(int argc, const char * argv[]) {
    MyComplex Complex1;
    MyComplex Complex2 = {5};
    MyComplex Complex3 = {7, 13};
    
    //constructor tests
    cout << "Constructor Tests:\nComplex1 (Default Constructor): " << Complex1 << "\nComplex2 (1 Value Constructor): " << Complex2 << "\nComplex3 (2 Value Constructor): " << Complex3 << endl;
    
    //accessor tests
    cout << "\nAccessor Function tests:\ngetReal test on Complex3: " << Complex3.getReal() << "\ngetImaginary test on Complex3: " << Complex3.getImaginary() << endl;
    
    /*Insertion Operator Tests*/
    
    //mutator tests
    Complex3.setReal(4);
    cout << "\nMutator Function tests:\nComplex3.setReal(4): " << Complex3 << endl;
    Complex3.setImaginary(-9);
    cout << "Complex3.setImaginary(-9): " << Complex3 << endl;

    //overloaded function tests
    Complex2.setReal(12);
    Complex2.setImaginary(-36);
    cout << "\nOverloaded Function Tests:\n12-36i + 4-9i = " << Complex2 + Complex3 << endl;
    cout << "12-36i + 4 = " << Complex2 + 4 << endl;
    cout << "12-36i - 4-9i = " << Complex2 - Complex3 << endl;
    cout << "12-36i - 4 = " << Complex2 - 4 << endl;
    cout << "12-36i * 4-9i = " << Complex2 * Complex3 << endl;
    cout << "12-36i * 4 = " << Complex2 * 4 << endl;
    cout << "12-36i / 4-9i = " << Complex2 / Complex3 << endl;
    cout << "12-36i / 4 = " << Complex2 / 4 << endl;
    
    //conjugate tests
    Complex3.getConjugate();
    cout << "\nConjugate Function Test:\nConjugate of 4-9i: " << Complex3 << endl;
    
    //extraction operator test
    cout << "\nInput Values to Test Extraction Operator (formatted  # #i):";
    cin >> Complex1;
    cout << "Extraction operator test: " << Complex1 << endl;
    
    
    return 0;
}
