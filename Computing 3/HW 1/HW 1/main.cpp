/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein. All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 9/15/2020
HW 1
Name: Cam Benassi
*/

#include <iostream>
#include <sstream>
using namespace std;

void triangle (int a, int b, int c);

int main(int argc, const char * argv[]) {
    
    const char * temp1;
    const char * temp2;
    const char * temp3;
    
    int side1, side2, side3;
    
    if (argc == 1){     //No command line arguments
        cin >> side1;
        cin >> side2;
        cin >> side3;
        
    }
    else{   //Command Line arguments
        for (int i = 0; i < argc + 1; i++){
            if (argc <= 3){ //Checks to see if there are too few arguments
                cerr << "Not enough arguments\n";
                return 1;
            }
            if (argc > 4){  //Checks to see if there are too many arguments
                cerr << "Too many arguments\n";
                return 1;
            }
            
            if(i == 0){ //Assigning command line arguments to temporary variables
                temp1 = argv[1];
            }
            if(i == 1){
                temp2 = argv[2];
            }
            if(i == 2){
                temp3 = argv[3];
            }
        }
        
        stringstream convert1;  //converting from const char* to int so arithmetic can be used
        stringstream convert2;
        stringstream convert3;
        convert1 << temp1;
        convert1 >> side1;
        
        convert2 << temp2;
        convert2 >> side2;
        
        convert3 << temp3;
        convert3 >> side3;
        
    }
    
    if (side1 < 0 || side2 < 0 || side3 < 0){   //checks to see if any values are negative
        cerr << "Sides must be positive.\n";
        return 1;
    }
    
    triangle(side1, side2, side3);  //calls function triangle with 3 sides if all tests are passed
        
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
