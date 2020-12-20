/*
Cam Benassi, Colton Choquette, Jalen Rojas, Sahil Patel
Computing III Lab 3
Section 803
Group #5
*/

#include  <iostream>

using namespace std;

class Mass
{
public:
    void setMassAvoirdupoisPounds(double massAPounds);
    void setMassTroyPounds(double massTPounds);
    void setMassMetricGrams(double massMGrams);

    double getMassAvoirdupoisPounds(void) const;
    double getMassTroyPounds(void) const;
    double getMassMetricGrams(void) const;
private:
    double drams;
};

int main(int argc, char* argv[])
{
  int choice;
  Mass Mass1;
  double massAPounds, massTPounds, massMGrams;
do
{
  cout << endl <<"Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: ";
  
  while (!(cin >> choice) || choice < 0 || choice > 3){
    cout << "That was not a valid input, try again\nPlease enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: ";
    cin.clear();
    cin.ignore(10000, '\n');
  }

  switch(choice){
    case 0:
      cout << "Thanks for using the mass conversion program!" << endl;
      return 0;
      break;
    case 1:
      cout << "Please enter a mass in Avoirdupois Pounds: ";
      while (!(cin >> massAPounds) || massAPounds < 0){
        cout << "That was not a valid input, try again\nPlease enter a mass in Avoirdupois Pounds: ";
        cin.clear();
        cin.ignore(10000, '\n');
      }
      Mass1.setMassAvoirdupoisPounds(massAPounds);
      break;
    case 2:
      cout << "Please enter a mass in Troy pounds: ";
      while (!(cin >> massTPounds) || massTPounds < 0){
        cout << "That was not a valid input, try again\nPlease enter a mass in Troy pounds: ";
        cin.clear();
        cin.ignore(10000, '\n');
      }
      Mass1.setMassTroyPounds(massTPounds);
      break;
    case 3:
      cout << "Please enter a mass in grams: ";
      while (!(cin >> massMGrams) || massMGrams < 0){
        cout << "That was not a valid input, try again\nPlease enter a mass in grams: ";
        cin.clear();
        cin.ignore(10000, '\n');
      }
      Mass1.setMassMetricGrams(massMGrams);
      break;
      
    default:
      cerr << "An error has occured\n";
      break;
  }

  cout << "Mass in Avoirdupois pounds is " << Mass1.getMassAvoirdupoisPounds() << endl;
  cout << "Mass in Troy pounds is " << Mass1.getMassTroyPounds() << endl;
  cout << "Mass in grams is " << Mass1.getMassMetricGrams() << endl;

}while(1);

cout << "Thanks for using the mass conversion program!" << endl;
    return 0;
}

void Mass::setMassAvoirdupoisPounds(double massAPounds)
{
  drams = massAPounds * 256;
}

void Mass::setMassTroyPounds(double massTPounds)
{
  drams = massTPounds * 96;
}

void Mass::setMassMetricGrams(double massMGrams)
{
  drams = massMGrams / 1.7718451953125;
}

double Mass::getMassAvoirdupoisPounds(void) const
{
  return drams / 256;
}

double Mass::getMassTroyPounds(void) const
{
  return drams / 96;
}

double Mass::getMassMetricGrams(void) const
{
  return drams *  1.7718451953125;
}
