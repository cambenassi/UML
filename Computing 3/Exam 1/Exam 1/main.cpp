//
//  main.cpp
//  Exam 1
//
//  Created by Cam Benassi on 10/15/20.
//

#include <iostream>
#include "SSandwitch.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    SloppySandwitch sand1;
    
    sand1.setSize(size::regular);
    sand1.setBreadType(breadType::rye);
    sand1.setBreadFormat(breadFormat::sliced);
    sand1.operator+("Cheese");
    sand1.operator+("Lettuce");
    sand1.operator+("Only a little mustard");
    
    
    sand1.getSize();
    sand1.getBreadType();
    sand1.getBreadFormat();
    
    return 0;
}
