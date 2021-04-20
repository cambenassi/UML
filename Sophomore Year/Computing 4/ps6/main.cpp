// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <iostream>
#include <fstream>

#include <regex> //NOLINT

// #include <boost/regex.hpp>

int main(int argc, char* argv[]) {
    std::string log = argv[1], outLog = log + ".rpt", temp;
    std::ifstream input(log);
    std::smatch smatches;
    std::regex startup("server started"),
    success("oejs.AbstractConnector:Started SelectChannelConnector");
    FILE *output = fopen(outLog.c_str(), "w");
    int numScanned = 0;
    bool start = false;

    fprintf(output, "Device Boot Report\n\nInTouch log file: %s\n-------------------------------------\n", log.c_str()); //NOLINT

    while (std::getline(input, temp)) {
        if (std::regex_search(temp, smatches, startup)) {
            fprintf(output, "\nStartup - Line: %d\tDate & Time: NYI\nStatus - ", numScanned); //NOLINT
            start = true;
        }
        if (start && std::regex_search(temp, smatches, success)) {
            fprintf(output, "Success, finished on line %d", numScanned); //NOLINT
            start = false;
        }  // fix failure, add date & time
        numScanned++;
    }
    fprintf(output, "Lines scanned: %d", numScanned);

    input.close();
    fclose(output);
    return 0;
}
