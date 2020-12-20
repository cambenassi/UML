//
//  MyComplex.cpp
//  HW 4
//
//  Created by Cam Benassi on 10/21/20.
//

#include <iostream>
#include "MyComplex.h"
using namespace std;

//constructors
MyComplex::MyComplex() noexcept{
    real = 0.0; imaginary = 0.0;
}
MyComplex::MyComplex(double userReal){
    real = userReal; imaginary = 0.0;
}
MyComplex::MyComplex(double userReal, double userImaginary){
    real = userReal; imaginary = userImaginary;
}

//accessor functions
double MyComplex::getReal(){
    return real;
}
double MyComplex::getImaginary(){
    return imaginary;
}

//mutator functions
void MyComplex::setReal(double userReal){
    real = userReal;
}
void MyComplex::setImaginary(double userImaginary){
    imaginary = userImaginary;
}

//insertion operator
ostream& operator<<(ostream& os, const MyComplex& userInput){
    if(userInput.imaginary < 0)
        cout << userInput.real  << userInput.imaginary << "i";
    else
        cout << userInput.real << "+" << userInput.imaginary << "i";
    
    return os;
}
