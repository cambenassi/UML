// Copyright 2021 Cameron Benassi @ UML. All rights reserved.

#include <iostream>
#include <fstream>

#include <regex> //NOLINT

#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(int argc, char* argv[]) {
    std::string log = argv[1], outLog = log + ".rpt", temp, timeStart, timeEnd;
    std::ifstream input(log);
    boost::smatch smatches;
    boost::regex startup("server started"),
    success("oejs.AbstractConnector:Started SelectChannelConnector"),
    date("([0-9]{2}):([0-9]{2}):([0-9]{2})");
    boost::posix_time::ptime t1, t2;
    FILE *output = fopen(outLog.c_str(), "w");
    int numScanned = 1;
    bool start = false;

    fprintf(output, "Device Boot Report\n\nInTouch log file: %s\n-------------------------------------\n", log.c_str()); //NOLINT

    while (std::getline(input, temp)) {
        if (start && boost::regex_search(temp, smatches, startup)) {
            fprintf(output, "Status - Failure\n");
        }
        if (boost::regex_search(temp, smatches, startup)) {
            fprintf(output, "Startup on line: %d | ", numScanned); //NOLINT
            if (boost::regex_search(temp, smatches, date)) {
                timeStart = "2000-10-24 " + smatches.str();
                t1 = boost::posix_time::time_from_string(timeStart);
            }
            start = true;
        }
        if (start && boost::regex_search(temp, smatches, success)) {
            timeEnd = "2000-10-24 ";
            for (int i = 11; i < 19; i++)
                timeEnd += temp[i];

            t2 = boost::posix_time::time_from_string(timeEnd);
            boost::posix_time::time_duration td = t2 - t1;
            fprintf(output, "Status - Success, finished on line %d | Duration: %ld minutes & %ld seconds\n", numScanned, td.minutes(), td.seconds()); //NOLINT
            start = false;
        }
        numScanned++;
    }
    fprintf(output, "\nLines scanned: %d", numScanned);

    input.close();
    fclose(output);
    return 0;
}
