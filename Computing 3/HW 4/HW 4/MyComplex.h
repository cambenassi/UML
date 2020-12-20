//
//  MyComplex.h
//  HW 4
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
    
//insertion operator
    friend ostream& operator<<(ostream& os, const MyComplex& userInput);
};



#endif /* MyComplex_h */
