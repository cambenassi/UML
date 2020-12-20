//
//  MyComplex.cpp
//  HW 5
//
//  Created by Cam Benassi on 10/21/20.
//

#include <iostream>
#include "MyComplex.h"
#include <string>
#include <cmath>
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

//overloaded operators
ostream& operator<<(ostream& os, const MyComplex& userInput){
    if(userInput.real != 0 && userInput.imaginary != 0){
        if(userInput.imaginary < 0)
            cout << userInput.real << userInput.imaginary << "i";
        else
            cout << userInput.real << "+" << userInput.imaginary << "i";
    }
    else if(userInput.real == 0 && userInput.imaginary == 0)
        cout << "0";
    else if(userInput.real == 0)
        cout << userInput.imaginary << "i";
    else if(userInput.imaginary == 0)
        cout << userInput.real;
    
    return os;
}
istream& operator>>(istream& os, MyComplex& userInput){
    cin >> userInput.real;
    cin >> userInput.imaginary;
    
    return os;
}
MyComplex operator+(MyComplex a, const MyComplex& b){
    MyComplex sum;

    sum.real =  a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;

    return sum;
}
MyComplex operator-(MyComplex a, const MyComplex& b){
    MyComplex difference;

    difference.real =  a.real - b.real;
    difference.imaginary = a.imaginary - b.imaginary;

    return difference;
}
MyComplex operator*(MyComplex a, const MyComplex& b){
    MyComplex product;

    product.real =  (a.real * b.real) - (a.imaginary * b.imaginary);
    product.imaginary = (a.imaginary * b.real) + (b.imaginary * a.real);

    return product;
}

//conjugate function
void MyComplex::getConjugate(){
    if(imaginary != 0)
        imaginary = imaginary * -1;
}
