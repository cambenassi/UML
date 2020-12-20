/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein. All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 9/9/2020
Lab #1
Name:  Timofey Fayzullin, Scott Landry, Ethan Derr, Cam Benassi - Group 1
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    int control = 1;
    double AI = 1;
    double AR = 1;
    double LP = 1;
    while (control == 1)
    {
        cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to quit): ";
        cin >> AI;
        if (AI == 0)
        {
            control = 0;
            return 0;
        }
        cout << "Please enter the amount you would like to receive: ";
        cin >> AR;
        cout << "Please enter loan period in months: ";
        cin >> LP;
        cout << "The total amount of your loan (including interest at 15% per annum) is " << (AR / ((100 - AI) / 100))<< "." << endl;
        cout << "Your monthly payment for " << LP << " months will be " << fixed << setprecision(2) << (AR / ((100 - AI) / 100)) / LP << endl;
        AI = 1;
        AR = 1;
        LP = 1;
    }
    return 0;
}
