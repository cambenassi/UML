//
//  main.cpp
//  HW 8
//
//  Created by Cam Benassi on 11/30/20.
//

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


//Rational Class Definition
class Rational{
public:
    //constructors
    Rational() noexcept {numerator = 1; denominator = 1;};
    Rational(long userN) {numerator = userN; denominator = 1;};
    Rational(long userN, long userD);
    
    //member functions
    long getNum() {return numerator;};
    long getDem() {return denominator;};
    friend long gcd(long frac1, long frac2);
    friend Rational operator+(Rational a, const Rational& b);
    friend Rational operator-(Rational a, const Rational& b);
    friend Rational operator*(Rational a, const Rational& b);
    friend Rational operator/(Rational a, Rational b);
    friend ostream& operator<<(ostream& os, const Rational& a);
    
    
    
private:
    long numerator, denominator;
};


//MyComplex Class Definition
template <class T>
class MyComplex{
private:
    T real, imaginary;

public:
//constructors
    MyComplex() noexcept;
    MyComplex(T);
    MyComplex(T, T);
    
//accessor functions
    T getReal();
    T getImaginary();
    
//mutator functions
    void setReal(T);
    void setImaginary(T);

//overloaded operators
    //extraction and insertion
    template <class f>
    friend ostream& operator<<(ostream& os, const MyComplex<f>& userInput);
    template <class f>
    friend istream& operator>>(istream& os, MyComplex<f>& userInput);
    //addition
    MyComplex operator+ (MyComplex) const;
    friend MyComplex operator+ (T, MyComplex);
    //subtraction
    MyComplex operator- (MyComplex) const;
    MyComplex operator- (T) const;
    friend MyComplex operator- (T, MyComplex);
    //multiplication
    MyComplex operator* (MyComplex) const;
    friend MyComplex operator* (T, MyComplex);
    //division
    MyComplex operator/ (T) const;
    MyComplex operator/ (MyComplex) const;

//conjugate function
    void getConjugate();
};

//Main
int main(int argc, const char * argv[]) {
    Rational num1 = {1, 6}, num2 = {2, 8};
    MyComplex<Rational> test = {num1, num2}, test2 = {num1, num2};
    
    cout << test.getReal().getNum() << "/" << test.getReal().getDem() << " + " << test.getImaginary().getNum() << "/" << test.getImaginary().getDem() << "i\n";
    
    //For this assignment, small tweaks were made to the overloaded << function in order to get this code to work with the Rational code. Other than that,
    //there was nothing major that had to be done in order for the two to work.     Thank you for the great semester, have a nice winter break!
    
    return 0;
}


//Rational Function Definitions

//Two Value Constructor
Rational::Rational(long userN, long userD){
    numerator = userN;
    denominator = userD;
    
    try{
        if(denominator == 0)
            throw 0;
    }
    catch (int e){
        cout << "Denominator cannot be 0.\n";
    }
}

//Overloaded Operators
ostream& operator<<(ostream& os, Rational& a){
    cout << a.getNum() << "/" << a.getDem();
    return os;
}

long gcd(long frac1, long frac2){
    long quotient, remainder;

    if(frac1 == 0)
        return frac2;
    else if(frac2 == 0)
        return frac1;
    else{
        quotient = frac2;
        remainder = static_cast<int>(frac1 % frac2);

        return gcd(quotient, remainder);
    }
}

Rational operator+(Rational a, const Rational& b){
    Rational sum;
    long divisor;
    
    sum.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
    sum.denominator = a.denominator * b.denominator;
    
    divisor = gcd(sum.getNum(), sum.getDem());
    
    sum.numerator /= divisor;
    sum.denominator /= divisor;
    
    if(sum.denominator < 0){
        sum.numerator *= -1;
        sum.denominator *= -1;
    }
    
    return sum;
}

Rational operator-(Rational a, const Rational& b){
    Rational difference;
    long divisor;
    
    difference.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
    difference.denominator = a.denominator * b.denominator;
    
    divisor = gcd(difference.getNum(), difference.getDem());
    
    difference.numerator /= divisor;
    difference.denominator /= divisor;
    
    if(difference.denominator < 0){
        difference.numerator *= -1;
        difference.denominator *= -1;
    }
    
    return difference;
}

Rational operator*(Rational a, const Rational& b){
    Rational product;
    long divisor;
    
    product.numerator = a.numerator * b.numerator;
    product.denominator = a.denominator * b.denominator;
    
    divisor = gcd(product.getNum(), product.getDem());
    
    product.numerator /= divisor;
    product.denominator /= divisor;
    
    if(product.denominator < 0){
        product.numerator *= -1;
        product.denominator *= -1;
    }
    
    return product;
}

Rational operator/(Rational a, Rational b){
    Rational dividend;
    long divisor, temp;
    
    temp = b.numerator;
    b.numerator = b.denominator;
    b.denominator = temp;
    
    dividend.numerator = a.numerator * b.numerator;
    dividend.denominator = a.denominator * b.denominator;
    
    divisor = gcd(dividend.getNum(), dividend.getDem());
    
    dividend.numerator /= divisor;
    dividend.denominator /= divisor;
    
    if(dividend.denominator < 0){
        dividend.numerator *= -1;
        dividend.denominator *= -1;
    }
    
    return dividend;
}

//MyComplex Function Definitions

//constructors
template <class T>
MyComplex<T>::MyComplex() noexcept{
    real = 0.0; imaginary = 0.0;
}
template <class T>
MyComplex<T>::MyComplex(T userReal){
    real = userReal; imaginary = 0.0;
}
template <class T>
MyComplex<T>::MyComplex(T userReal, T userImaginary){
    real = userReal; imaginary = userImaginary;
}

//accessor functions
template <class T>
T MyComplex<T>::getReal(){
    return real;
}
template <class T>
T MyComplex<T>::getImaginary(){
    return imaginary;
}

//mutator functions
template <class T>
void MyComplex<T>::setReal(T userReal){
    real = userReal;
}
template <class T>
void MyComplex<T>::setImaginary(T userImaginary){
    imaginary = userImaginary;
}

//overloaded operators
//insertion and extraction
template <class T>
ostream& operator<<(ostream& os, const MyComplex<T>& userInput){
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
template <class T>
istream& operator>>(istream& os, MyComplex<T>& userInput){
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
template <class T>
MyComplex<T> MyComplex<T>::operator+ (MyComplex summard) const{
    return MyComplex(this->real + summard.real, this->imaginary + summard.imaginary);
}
template<class T>
MyComplex<T> operator+ (double summard, MyComplex<T> a){
    return MyComplex<T>(a.real + summard, a.imaginary);
}
//subtraction (1 and 2 MyComplex objects)
template <class T>
MyComplex<T> MyComplex<T>::operator- (MyComplex subtrahend) const{
    return MyComplex(this->real - subtrahend.real, this->imaginary - subtrahend.imaginary);
}
template <class T>
MyComplex<T> MyComplex<T>::operator- (T subtrahend) const{
    return MyComplex(this->real - subtrahend, this->imaginary);
}
template <class T>
MyComplex<T> operator- (T subtrahend, MyComplex<T> a) {
    return MyComplex<T>(subtrahend - a.real, -(a.imaginary));
}
//multiplication (1 and 2 MyComplex objects)
template <class T>
MyComplex<T> MyComplex<T>::operator* (MyComplex factor) const {
    return MyComplex(this->real * factor.real - this->imaginary * factor.imaginary, this->imaginary * factor.real + this->real * factor.imaginary);
}
template <class T>
MyComplex<T> operator* (double factor, MyComplex<T> a) {
    return MyComplex<T>(a.real * factor, a.imaginary * factor);
}
//division (1 and 2 MyComplex objects)
template <class T>
MyComplex<T> MyComplex<T>::operator/ (T dividend) const{
    return MyComplex(this->real / dividend, this->imaginary / dividend);
}
template <class T>
MyComplex<T> MyComplex<T>::operator/ (MyComplex dividend) const{
    double qBottom = dividend.real * dividend.real + dividend.imaginary * dividend.imaginary;
    return MyComplex((this->real * dividend.real + this->imaginary * dividend.imaginary) / qBottom, (this->imaginary * dividend.real - this->real * dividend.imaginary) / qBottom);
}
//conjugate function
template <class T>
void MyComplex<T>::getConjugate(){
    if(this->imaginary != 0)
        this->imaginary = this->imaginary * -1;
}



