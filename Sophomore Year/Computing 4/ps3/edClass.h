#ifndef edClass_h
#define edClass_h

class ED {
    public:
        //constructors & destructor
        ED(std::string a, std::string b);
        ED();
        //~ED();
        //overloaded << operator
        friend std::istream& operator>>(std::istream& os, ED& dest);
        //member functions
        static int penalty(char a, char b);
        static int min(int a, int b, int c);
        int optDistance();
        std::string stringAllignment();
        //data members
        std::string dnaA, dnaB;
        int **matrix;
};

#endif