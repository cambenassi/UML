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
    //extraction and insertion
    friend ostream& operator<<(ostream& os, const MyComplex& userInput);
    friend istream& operator>>(istream& os, MyComplex& userInput);
    //addition
    friend MyComplex operator+(MyComplex a, const MyComplex& b);
    friend MyComplex operator+(MyComplex a, double summard);
    friend MyComplex operator+(double summard, MyComplex a);
    //subtraction
    friend MyComplex operator-(MyComplex a, const MyComplex& b);
    friend MyComplex operator-(MyComplex a, double subtrahend);
    friend MyComplex operator-(double subtrahend, MyComplex a);
    //multiplication
    friend MyComplex operator*(MyComplex a, const MyComplex& b);
    friend MyComplex operator*(MyComplex a, double factor);
    friend MyComplex operator*( double factor, MyComplex a);
    //division
    friend MyComplex operator/(MyComplex a, double dividend);
    friend MyComplex operator/(MyComplex a, MyComplex b);
    
//conjugate function
    void getConjugate();
};



#endif /* MyComplex_h */
