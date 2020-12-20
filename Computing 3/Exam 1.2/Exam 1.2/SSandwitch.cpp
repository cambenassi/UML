//
//  SSandwich.cpp
//  Exam 1
//
//  Created by Cam Benassi on 10/15/20.
//

#include <iostream>
#include "SSandwitch.h"
using namespace std;

//Default Sandwich Constructor
SloppySandwitch::SloppySandwitch() noexcept{
    sandSize = size::regular;
    sandType = breadType::white;
    sandFormat = breadFormat::wrap;
    contentsList = vector<string>();
}

//value constructor
SloppySandwitch::SloppySandwitch(size userSize, breadType userType, breadFormat userFormat){
    sandSize = userSize;
    sandType = userType;
    sandFormat = userFormat;
    contentsList = vector<string>();
}

//accessor functions
size SloppySandwitch::getSize(){
    return sandSize;
}

breadType SloppySandwitch::getBreadType(){
    return sandType;
}

breadFormat SloppySandwitch::getBreadFormat(){
    return sandFormat;
}

//mutator functions
//each function is compatable with int or enum class variables
void SloppySandwitch::setSize(int userSize){
    switch (userSize) {
        case 0:
            sandSize = size::regular;
            break;
        case 1:
            sandSize = size::glutton;
            break;
            
        default:
            break;
    }
}
void SloppySandwitch::setSize(size userSize){
    sandSize = userSize;
}

void SloppySandwitch::setBreadType(int userType){
    switch (userType) {
        case 0:
            sandType = breadType::white;
            break;
        case 1:
            sandType = breadType::wheat;
            break;
        case 2:
            sandType = breadType::rye;
            break;
            
        default:
            break;
    }
}
void SloppySandwitch::setBreadType(breadType userType){
    sandType = userType;
}

void SloppySandwitch::setBreadFormat(int userFormat){
    switch (userFormat) {
        case 0:
            sandFormat = breadFormat::wrap;
            break;
        case 1:
            sandFormat = breadFormat::sub;
            break;
        case 2:
            sandFormat = breadFormat::sliced;
            break;
            
        default:
            break;
    }
}
void SloppySandwitch::setBreadFormat(breadFormat userFormat){
    sandFormat = userFormat;
}

SloppySandwitch& SloppySandwitch::operator+(const string& userInput){
    contentsList.push_back(userInput);
    return *this;
}

//print function for contentList
void SloppySandwitch::printContents(){
    for(int i = 0; i < contentsList.size(); i++)
        cout << contentsList.at(i) << ", ";
    
    cout << endl;
}

