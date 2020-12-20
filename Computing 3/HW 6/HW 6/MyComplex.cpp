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
//insertion and extraction
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
    string x;
    char peekTemp;

    cin >> x;
    peekTemp = cin.peek();

    if(x.at(x.length() - 1) == 'i'){
        userInput.imaginary = stod(x);
        userInput.real = 0;
    }
    else if(peekTemp != '\n'){
        userInput.real = stod(x);
        cin >> x;
        userInput.imaginary = stod(x);
    }
    else{
        userInput.real = stod(x);
        userInput.imaginary = 0;
    }
    
    return os;
}
//addition (1 and 2 MyComplex objects)
MyComplex operator+(MyComplex a, const MyComplex& b){
    MyComplex sum;

    sum.real =  a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;

    return sum;
}
MyComplex operator+(MyComplex a, double summard){
    a.real += summard;
    
    return a;
}
MyComplex operator+(double summard, MyComplex a){
    a.real += summard;
    
    return a;
}
//subtraction (1 and 2 MyComplex objects)
MyComplex operator-(MyComplex a, const MyComplex& b){
    MyComplex difference;

    difference.real =  a.real - b.real;
    difference.imaginary = a.imaginary - b.imaginary;

    return difference;
}
MyComplex operator-(MyComplex a, double subtrahend){
    a.real -= subtrahend;
    
    return a;
}
MyComplex operator-(double subtrahend, MyComplex a){
    a.real -= subtrahend;
    
    return a;
}
//multiplication (1 and 2 MyComplex objects)
MyComplex operator*(MyComplex a, const MyComplex& b){
    MyComplex product;

    product.real =  (a.real * b.real) - (a.imaginary * b.imaginary);
    product.imaginary = (a.imaginary * b.real) + (b.imaginary * a.real);

    return product;
}
MyComplex operator*(MyComplex a, double factor){
    a.real *= factor;
    
    return a;
}
MyComplex operator*( double factor, MyComplex a){
    a.real *= factor;
    
    return a;
}
//division (1 and 2 MyComplex objects)
MyComplex operator/(MyComplex a, double dividend){
    MyComplex quotient;
    
    quotient.real = a.real / dividend;
    quotient.imaginary = a.imaginary / dividend;
    
    
    return quotient;
}
MyComplex operator/(MyComplex a, MyComplex b){
    MyComplex quotientTop, quotientBottom, conjugateTemp;
    
    b.getConjugate();
    conjugateTemp.real = b.real;
    conjugateTemp.imaginary = b.imaginary;
    b.getConjugate();
    
    quotientTop = a * conjugateTemp;
    quotientBottom = b * conjugateTemp;
    
    quotientTop.real = quotientTop.real / quotientBottom.real;
    quotientTop.imaginary = quotientTop.imaginary / quotientBottom.real;
    
    
    return quotientTop;
}

//conjugate function
void MyComplex::getConjugate(){
    if(imaginary != 0)
        imaginary = imaginary * -1;
}
