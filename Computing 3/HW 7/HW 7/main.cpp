//
//  main.cpp
//  HW 7
//
//  Created by Cam Benassi on 10/20/20.
//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


/*#############################   MyComplex Class   #########################################*/

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

/*#############################   MAIN   #########################################*/

int main(int argc, const char * argv[]) {
    MyComplex<int> Complex1;
    MyComplex<int> Complex2 = {5};
    MyComplex<int> Complex3 = {7, 13};
    
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

/*###########################   MyComplex Class Function Definitions   ###########################*/

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
