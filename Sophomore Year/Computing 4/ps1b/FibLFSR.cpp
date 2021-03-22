//#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include "FibLFSR.h"
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

FibLFSR::FibLFSR(string seed){
    //is the seed to short? pad with 0's
    if(seed.length() < 16){
        int pad = 16 - seed.length();
        string temp;
        while (pad > 0){
            temp += '0';
            pad--;
        }
        temp += seed;
        seed = temp;
    }
    //is the seed to long? trim it to 16 MSB
    if(seed.length() > 16){
        string::iterator it = seed.end();
        string temp;
        while (temp.length() <= 16){
            temp += *it;
            it--;
        }
        reverse(temp.begin(), temp.end());
        seed.clear();
        seed = temp;
        seed.pop_back();
    }
    //are there any letters? replace with 0's
    int i = 0;
    while(seed[i]){
        if(isalpha(seed[i]))
            seed[i] = '0';
        i++;
    }

    bits = seed;
}

int FibLFSR::step(){
    int length = bits.length();
    int temp = bits.at(0) ^ bits.at(2);
    temp ^= bits.at(3);
    temp ^= bits.at(5);

    for (int i = 0; i != length - 1; i++)
        bits.at(i) = bits.at(i + 1);

    string conv = to_string(temp);
    bits.at(bits.length() - 1) = conv.at(0);

    return temp;
}

int FibLFSR::generate(int k){
    int result = 0;

    for (int i = 0; i < k; i++){
        result = result * 2 + step();
    }

    return result;
}

ostream& operator<<(ostream& os, const FibLFSR& number){
    cout << number.bits;

    return os;
}

