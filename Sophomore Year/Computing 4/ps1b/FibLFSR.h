//#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef FibLFSR_h
#define FibLFSR_h
using namespace std;

class FibLFSR {
    private:
        string bits;
    public:
        FibLFSR(string seed);
        int step();
        int generate(int k);
        friend ostream& operator<<(ostream& os, const FibLFSR& number);

};

#endif