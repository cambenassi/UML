//
//  SSandwitch.h
//  Exam 1
//
//  Created by Cam Benassi on 10/15/20.
//

#ifndef SSandwitch_h
#define SSandwitch_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//enum class for sandwich mods
enum class size {regular, glutton};
enum class breadType {white, wheat, rye};
enum class breadFormat {wrap, sub, sliced};

class SloppySandwitch{
private:
  size sandSize;
  breadType sandType;
  breadFormat sandFormat;
  vector<string> contentsList;
    
public:

//constructors
  SloppySandwitch() noexcept;
  SloppySandwitch(size userSize, breadType userType, breadFormat userFormat);
    
//accessor functions
  size getSize();
  breadType getBreadType();
  breadFormat getBreadFormat();
    
//print function for testing
  void printContents();
    
//mutator functions
  void setSize(int userSize);
  void setSize(size userSize);
  void setBreadType(int userType);
  void setBreadType(breadType userType);
  void setBreadFormat(int userFormat);
  void setBreadFormat(breadFormat userFormat);
  SloppySandwitch& operator+(const string& userInput);
};

#endif /* SSandwitch_h */
