/*
Cam Benassi, Artyom Martirosyan, Sahil Patel, Wilbert DelaRosa
Computing III Lab 2
Section 803
Group #10
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void getUserInput(int &pounds, double &ounces);
void imperialToMetric(int pounds, double ounces, int &kilograms, double &grams);
void outputCalculation(int pounds, double ounces, int kilograms, double grams);

int main(int argc, const char * argv[]) {
    
    int pounds, kilograms;
    double ounces, grams;
    
    getUserInput(pounds, ounces);
    
    imperialToMetric(pounds, ounces, kilograms, grams);
    
    //outputCalculation(pounds, ounces, kilograms, grams);
    
    return 0;
}

void getUserInput(int &pounds, double &ounces)
{
    cout << "Please enter the number of pounds: ";
    //cin >> pounds;
    while(!(cin >> pounds) || pounds < 0){
      cout << "That's not a number greater than or equal to 0! Please try again... Please enter the number of pounds: " << endl;
      //cin >> pounds;
      cin.clear();
      cin.ignore(10000, '\n');
    }
    
    cout << "Please enter the number of ounces: ";
    //cin >> ounces;
    while (!(cin >> ounces) || ounces < 0 || ounces >= 16){
      cout << "That's not a number greater than 0 and less than 16! Please try again... Please enter the number of ounces: " << endl;
      //cin >> ounces;
      cin.clear();
      cin.ignore(10000, '\n');
    }
}

void imperialToMetric(int pounds, double ounces, int &kilograms, double &grams){
  double combinedWeightI = pounds;
  double combinedWeightM;
  combinedWeightI = (ounces / 16) + combinedWeightI;

  //cout << "combinedWeightI = " << combinedWeightI << endl;

  combinedWeightM = combinedWeightI * 0.45359237;
  kilograms = floor(combinedWeightM);
  grams = (combinedWeightM - kilograms) * 1000;

  //cout << "combinedWeightM = " << combinedWeightM << endl;
  
  outputCalculation(pounds, ounces, kilograms, grams);

}

void outputCalculation(int pounds, double ounces, int kilograms, double grams){
  cout << pounds << " pounds and " << fixed << setprecision(8) << ounces << " ounces converts to" << endl << kilograms << " kilograms and " << fixed << setprecision(8) << grams << " grams." << endl;
  
}
