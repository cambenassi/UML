/*
 Computing I -- COMP.1010 Honor Statement
 
 The practice of good ethical behavior is essential for maintaining
 good order in the classroom, providing an enriching learning
 experience for students, and as training as a practicing computing
 professional upon graduation.  This practice is manifested in the
 University's Academic Integrity policy. Students are expected to
 strictly avoid academic dishonesty and adhere to the Academic
 Integrity policy as outlined in the course catalog.  Violations
 will be dealt with as outlined therein.
 
 All programming assignments in this class are to be done by the
 student alone.  No outside help is permitted except the instructor
 and approved tutors.
 
 I certify that the work submitted with this assignment is mine and
 was generated in a manner consistent with this document, the
 course academic policy on the course website on Blackboard, and
 the UMass Lowell academic code.
 
 Date: 11/20/2019
 Name: Cameron Benassi
 */
 
 /***********************************************
Author: <Cameron Benassi>
Date: <11/20/2019>
Purpose: <This program takes a user inputed string and 
prints it, then reverses it>
 Sources of Help: <none>
 Time Spent: <30 mins>
***********************************************/

#include <stdio.h>

void reverseString (char string[], int i);

int main()
{
    int length = 80, i = 0;
    char string[length];
    
    printf("Please enter a string:\n");
    
    while (i < length)
    {
        scanf("%c", &string[i]);
        if (string[i] == '\n')
        {
            string[i] = '\0';
            break;
        }
        i++;
    }
    
    printf("%s\n", string);
    
    reverseString(string, i);
    
    printf("%s\n", string);
    
    return 0;
}

void reverseString (char string[], int i)
{
    int j;
    char temp;
    
    for (j = 0; j < i; j++)
    {
        temp = string[i - 1];
        string[i - 1] = string[j];
        string[j] = temp;
        --i;
    }
}