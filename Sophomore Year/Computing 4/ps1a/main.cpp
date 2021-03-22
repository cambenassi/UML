#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include "FibLFSR.h"
using namespace std;

int main(int argc, const char * argv[]) {
    FibLFSR test = {"1011011000110110"};

    for (int i = 0; i < 7; i++){
        test.generate(5);
        cout << test << endl;
    }
    

    return 0;
}