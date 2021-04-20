// Copyright 2021 Cameron Benassi @ UML. All rights reserved.


#include <iostream>
#include <fstream>
#include <regex>

#include <boost/regex.hpp>

int main(int argc, char* argv[]) {
    std::string log = argv[1];
    std::string outLog = log + ".rpt";
    std::string temp;
    std::ifstream input(log);
    FILE *output = fopen(outLog.c_str(), "w");
    int numScanned = 0, initiated = 0, completed = 0;
    
    fprintf(output, "Device Boot Report\n\nInTouch log file: %s\n", 
    log.c_str());
    fprintf(output, "Lines scanned: ");
    
    while (std::getline(input, temp)) {
        
        
        numScanned++;
    }
    fprintf(output, "%d", numScanned);
    
    
    input.close();
    fclose(output);
    return 0;
}
