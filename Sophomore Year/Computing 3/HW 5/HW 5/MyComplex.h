//
//  MyComplex.h
//  HW 5
//
//  Created by Cam Benassi on 10/21/20.
//

#ifndef MyComplex_h
#define MyComplex_h
using namespace std;


class MyComplex{
private:
    double real;
    double imaginary;

public:
//constructors
    MyComplex() noexcept;
    MyComplex(double userReal);
    MyComplex(double userReal, double userImaginary);
    
//accessor functions
    double getReal();
    double getImaginary();
    
//mutator functions
    void setReal(double userReal);
    void setImaginary(double userImaginary);
    
//overloaded operators
    friend ostream& operator<<(ostream& os, const MyComplex& userInput);
    friend istream& operator>>(istream& os, MyComplex& userInput);
    friend MyComplex operator+(MyComplex a, const MyComplex& b);
    friend MyComplex operator-(MyComplex a, const MyComplex& b);
    friend MyComplex operator*(MyComplex a, const MyComplex& b);
    
//conjugate function
    void getConjugate();
};



#endif /* MyComplex_h */
