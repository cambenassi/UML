// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <iostream>

#include <boost/regex.hpp>

int main(int argc, char* argv[]) {
    std::string log = argv[1];
    log = log + ".rpt";
    FILE *pFile = fopen(log.c_str(), "w");
    
    
    
    
    
    fclose(pFile);
    return 0;
}
