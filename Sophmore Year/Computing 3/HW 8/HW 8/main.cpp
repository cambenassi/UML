//
//  main.cpp
//  HW 8
//
//  Created by Cam Benassi on 11/30/20.
//

#include <iostream>
#include <algorithm>
using namespace std;

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

//Function Definitions

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

//Main
int main(int argc, const char * argv[]) {
    Rational test1 = {1, 2}, test2 = {1, 6}, test3, test4 = {4};
    
    cout << "Constructors:\n2 value constructors: " << test1 << "\n1 Value Constructors: " << test4 << "\nDefault Constructor: " << test3;
    
    test3 = test1 + test2;
    cout << "\n\nOverloaded Functions:\n1/2 + 1/6 = " << test3;
    
    test3 = test1 - test2;
    cout << "\n1/2 - 1/6 = " << test3;
    
    test3 = test1 * test2;
    cout << "\n1/2 * 1/6 = " << test3;
    
    test3 = test1 / test2;
    cout << "\n1/2 / 1/6 = " << test3 << endl << endl;
    
    return 0;
}
