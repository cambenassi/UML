/*
 Computing I -- COMP.1010 Honor Statement
 
 The practice of good ethical behavior is essential for maintaining
 good order in the classroom, providing an enriching learning
 experience for students, and as training as a practicing computing
 professional upon graduation.  This practice is manifested in the
 University’s Academic Integrity policy. Students are expected to
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
 
 Date: 11/18/2019
 Name: Cameron Benassi
 */
 
 /*
 Program: <Measurement Converter>
 Author: <Cameron Benassi>
 Date: <11/18/2019>
 Time spent: <1 hr>
 Sources of Help: <none>
 Purpose: <The purpose of this code is to demonstrate top down design, 
 along with converting measurements and weights.>
*/
 
 #include <stdio.h>

void read_length_us(int *feet, float *inches)
{
    printf("Enter feet and inches (separated by a space):\n");
    scanf("%d %f", feet, inches);
}

void convert_length_to_metric(int feet, float inches, int *meters, float *cm)
{
    *meters = *feet * .3048;
    *cm = ( (*feet * .3048 - *meters) * 100) + ( (*inches / 12 * .3048) * 100);
    if (*cm > 100)
    {
       *cm = *cm - 100;
       ++*meters;
    }
}

void output_length_metric(int feet, float inches, int meters, float cm)
{
    printf("%d and %6.4f inches converted to %d meters and %6.4f centimeters\n", feet, inches, meters, cm);
}

void length_to_metric(void)
{
    int feet, meters;
    float inches, cm;
    
    read_length_us(&feet, &inches);
    convert_length_to_metric(&feet, &inches, &meters, &cm);
    output_length_metric(feet, inches, meters, cm);
}

void read_length_metric(int *meters, float *cm)
{
    printf("Enter meters and centimeters (separated by a space):\n");
    scanf("%d %f", meters, cm);
}

void convert_length_to_us(int meters, float cm, int *feet, float *inches)
{
    *feet = *meters / .3048;
    *inches = ( (*cm / 100 / .3048)  * 12) + ( (*meters / .3048 - *feet) * 12);
}

void output_length_us(int meters, float cm, int feet, float inches)
{
    printf("%d meters and %6.4f centimeters converted to %d feet and %6.4f inches.\n", meters, cm, feet, inches);
}

void length_to_us(void)
{
    int meters, feet;
    float cm, inches;

    read_length_metric(&meters, &cm);
    convert_length_to_us(&meters, &cm, &feet, &inches);
    output_length_us(meters, cm, feet, inches);
}

void read_weight_us(int *pounds, float *ounces)
{
    printf("Enter pounds and ounces (separated by a space):\n");
    scanf("%d %f", pounds, ounces);
}

void convert_weight_to_metric(int pounds, int *kilograms, float ounces, float *grams)
{
    *kilograms = *pounds / 2.2046;
    *grams = ( (*pounds / 2.2046) - *kilograms) * 1000 + (*ounces / 16 / 2.2046) * 1000; 
    if (*grams >= 1000)
    {
       *grams = *grams - 1000;
       ++*kilograms;
    }
}

void output_weight_metric (int pounds, int kilograms, float ounces, float grams)
{
    printf("%d pounds and %6.4f ounces converted to %d kilograms and %6.4f grams\n", pounds, ounces, kilograms, grams);
}

void weight_to_metric(void)
{
    int pounds, kilograms;
    float ounces, grams;
    
    read_weight_us(&pounds, &ounces);
    convert_weight_to_metric(&pounds, &kilograms, &ounces, &grams);
    output_weight_metric(pounds, kilograms, ounces, grams);
}

void read_weight_metric(int *kilograms, float *grams)
{
    printf("Enter kilograms and grams (separated by a space):\n");
    scanf("%d %f", kilograms, grams);
}

void convert_weight_to_us (int kilograms, int *pounds, float grams, float *ounces)
{
    *pounds = *kilograms * 2.2046;
    *ounces = ( (*kilograms * 2.2046) - *pounds) * 16 + ( (*grams / 1000 * 2.2046) * 16);
}

void output_weight_us(int kilograms, int pounds, float grams, float ounces)
{
    printf("%d kilograms and %6.4f grams converted to %d pounds and %6.4f ounces\n", kilograms, grams, pounds, ounces);
}

void weight_to_us(void)
{
    int kilograms, pounds;
    float grams, ounces;
    
    read_weight_metric(&kilograms, &grams);
    convert_weight_to_us(&kilograms, &pounds, &grams, &ounces);
    output_weight_us(kilograms, pounds, grams, ounces);
}

void convert_lengths(void)                           //function only used when user watns to
{                                                    //convert lengths, used when user inputs
    int input;
   
   do{
      printf("1. convert lengths to metric\n2. convert lengths to US\n0. Return to Main Menu\n");
      scanf("%d", &input);
      
      if (input == 1)
      {
         length_to_metric();
      }
      else if (input == 2)
      {
         length_to_us();
      }
      
   } while (input != 0);
   
   printf("User chose to go main menu.\n\n");
   return;
}

void convert_weights(void)                           // function only used when user wants to
{                                                    // convert weights, used when user inputs
   int input;
   
   do{
      printf("1. convert weights from pounds/ounces to kilograms/grams\n2. convert weights from kilograms/grams to pounds/ounces\n0. Return to Main Menu\n");
      scanf("%d", &input);
      
      if (input == 1)
      {
         weight_to_metric();
      }
      else if (input == 2)
      {
         weight_to_us();
      }
      
   } while (input != 0); 
   
   printf("User chose to go main menu.\n\n");
   
   return; //'2'
}

int main(int argc, char * argv[])
{
   int input;
   
   do{
      printf("1. convert lengths\n2. convert weights\n0. Exit\nPlease choose from (1, 2, 0):\n");
      scanf("%d", &input);
      
      if (input == 1)
      {
         convert_lengths();
      }
      else if (input == 2)
      {
         convert_weights();
      }
      
   } while (input != 0); 
   
   printf("User chose to exit.\n");
   
   return 0;
}
