/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein. All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 9/15/2020
HW 2
Name: Cam Benassi
*/

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

void triangle (int a, int b, int c);
void triangle (double a, double b, double c);

int main(int argc, const char * argv[]) {
    
    const char * temp1;
    const char * temp2;
    const char * temp3;
    
    stringstream convert1;
    stringstream convert2;
    stringstream convert3;
    
    int side1, side2, side3;
    double dSide1, dSide2, dSide3;

    if (argc == 1){     //No command line arguments
        cin >> side1;
        cin >> side2;
        cin >> side3;
        
        if (side1 < 0 || side2 < 0 || side3 < 0){   //checks to see if any values are negative
            cerr << "Sides must be positive.\n";
            return 1;
        }
        
        triangle(side1, side2, side3);  //calls function triangle with 3 sides if all tests are passed
    }
    else if(argc == 5){ //Checks to see if command line arguments were '-d' or '-i'
        string argv2 = argv[1];
        if(argv2 == "-d"){          //command line arguments include '-d'
            temp1 = argv[2];        //assigning command line arguments to temporary variables
            temp2 = argv[3];
            temp3 = argv[4];
        
            convert1 << temp1;      //converting from const char* to double so arithmetic can be used
            convert1 >> dSide1;
            
            convert2 << temp2;
            convert2 >> dSide2;
            
            convert3 << temp3;
            convert3 >> dSide3;
            
            if (dSide1 < 0 || dSide2 < 0 || dSide3 < 0){   //checks to see if any values are negative
                cerr << "Sides must be positive.\n";
                return 1;
            }
            
            triangle(dSide1, dSide2, dSide3);
        }
        else if(argv2 == "-i"){     //command line arguments include '-i'
            temp1 = argv[2];        //assigning command line arguments to temporary variables
            temp2 = argv[3];
            temp3 = argv[4];
            
            convert1 << temp1;      //converting from const char* to int so arithmetic can be used
            convert1 >> side1;
            
            convert2 << temp2;
            convert2 >> side2;
            
            convert3 << temp3;
            convert3 >> side3;
            
            if (side1 < 0 || side2 < 0 || side3 < 0){   //checks to see if any values are negative
                cerr << "Sides must be positive.\n";
                return 1;
            }
            
            triangle(side1, side2, side3);  //calls function triangle with 3 sides if all tests are passed
        }
        
        
    }
    else{                       //Regular command line arguments
        if (argc <= 3){         //Checks to see if there are too few arguments
            cerr << "Not enough arguments\n";
            return 1;
        }
        if (argc > 5){          //Checks to see if there are too many arguments
            cerr << "Too many arguments\n";
            return 1;
        }
            
        temp1 = argv[1];
        temp2 = argv[2];
        temp3 = argv[3];
    
        convert1 << temp1;      //converting from const char* to int so arithmetic can be used
        convert1 >> side1;
        
        convert2 << temp2;
        convert2 >> side2;
        
        convert3 << temp3;
        convert3 >> side3;
        
        if (side1 < 0 || side2 < 0 || side3 < 0){   //checks to see if any values are negative
            cerr << "Sides must be positive.\n";
            return 1;
        }
        
        triangle(side1, side2, side3);  //calls function triangle with 3 sides if all tests are passed
        
    }
    
    
        
    return 0;   //if 0 is returned instead of 1, the program has run and done calculations successfully
}

void triangle (int a, int b, int c){
    int temp;   //sorting the numbers to have C be the greatest
    if (a >= b){
        if (a >= c){
            temp = c;
            c = a;
            a = temp;
        }
    }
    if(b >= a){
        if(b >= c){
            temp = c;
            c = b;
            b = temp;
        }
    }
    
    cout << a << " " << b << " " << c << " ";
    
    if (a + b > c){ //checks to see if sides can make a triangle, if possible code enters if statement
        if( (a * a + b * b == c * c) )
            cout << "Right ";
        
        if (a == b && b == c && c == a)
            cout << "Equilateral triangle\n";
        else if(a != b && b != c && c != a)
            cout << "Scalene triangle\n";
        else if( (a == b && c != a) || (b == c && a != b) || (c == a && b != c) )
            cout << "Isosceles triangle\n";
                
    }
    else
        cout << "Not a triangle\n";
    
}

void triangle (double a, double b, double c){
    
    const double EPSILON = .001;
    double temp;
    
    cout << fixed << setprecision(5) << a << " " << fixed << setprecision(5) << b << " " << fixed << setprecision(5) << c << " ";
    
    if(a > b || (fabs(a - b) < EPSILON) ){          //sorting so last value is at least as big as other 2 combined
        if(a > c || (fabs(a-c) < EPSILON) ){
            temp = c;
            c = a;
            a = temp;
        }
    }
    if(b > a || (fabs(b - a) < EPSILON) ){
        if(b > c || fabs(b - c) < EPSILON){
            temp = c;
            c = b;
            b = temp;
        }
    }
    
    if (a + b > c){                                     //checking to see if numbers form a triangle
        
        if( fabs(a * a + b * b) - fabs(c * c) < EPSILON){       //checking to see if triangle is right triangle
            cout << "Right ";
        }
        
        if (fabs(a - b) < EPSILON && fabs(b - c) < EPSILON && fabs(c - a) < EPSILON)//goes through different type of triangle tests
            cout << "Equilateral triangle\n";
        else if(fabs(a - b) >= EPSILON && fabs(b - c) >= EPSILON && fabs(c - a) >= EPSILON)
            cout << "Scalene triangle\n";
        else if( (fabs(a - b) < EPSILON && fabs(c - a) >= EPSILON) ||
                 (fabs(b - c) < EPSILON && fabs(a - b) >= EPSILON) ||
                 (fabs(c - a) < EPSILON && fabs(b - c) >= EPSILON) )
            cout << "Isosceles triangle\n";
        
    }
    else
        cout << "Not a trinagle\n";
}
