#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    cout << "Hello world!\n";

    if(argc == 4)
        cout << "Correct\n";
    
    for(int i = 0; i < argc; i++)
        cout << "argv[" << i << "] = '" << argv[i] << "'\n";
    
    return 0;
}
