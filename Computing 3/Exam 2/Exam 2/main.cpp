//
//  main.cpp
//  Exam 2
//
//  Created by Cam Benassi on 11/19/20.
//

#include <iostream>
#include <string>

using namespace std;


/*##### Zorb & KiloZorb Classes #####*/

// The Zorb game - the base class
class Zorb {
    public:
         // value constructor
         //For Part 1, adding the virtual keyword to a member function
         //would allow for it to be overridden by a derived class
         Zorb(int p, int t) : _power(p), _team_id(t) {}
         bool operator< (const Zorb&) const;
         Zorb operator+ (const Zorb&) const;
         int getPower() { return _power; }
         int getTeamID() { return _team_id; }
         friend ostream& operator<< (ostream&, const Zorb&);
    private:
         int _power;
         int _team_id;
};

class KiloZorb : public Zorb {
public:
    KiloZorb(int p, int t) : Zorb(p * 1000, t) {}
    KiloZorb operator+ (Zorb& z);
    KiloZorb operator+ (KiloZorb& z);
    bool operator< (Zorb& z);
    bool operator< (KiloZorb& z);
};

/*##### Function Definitions #####*/

// operator< usage: Zorb z1, z2; if (z1 < z2) {}
// In the expression z1<z2, "this" Zorb is z1 (the left operand).
// Returns true if "this" Zorb (left operand) has a different team ID
// AND greater power than the other Zorb (right operand).
bool Zorb::operator< (const Zorb& z) const {
    if (this->_team_id == z._team_id)
         return false;
    else
         return this->_power < z._power;
}

// operator+ usage: Zorb z3 = z1 + z2;
// Constructs a new Zorb (here assigned to z3) with the combined power
// of the original two Zorbs (z1 and z2), and the team ID of the stronger of
// the original two Zorbs.
// In the expression z1+z2, "this" Zorb is z1 (the left operand).
Zorb Zorb::operator+ (const Zorb& z) const {
    return Zorb(this->_power + z._power, ((*this < z) ? z._team_id : this->_team_id) );
}


inline KiloZorb KiloZorb::operator+ (Zorb& z){
    return KiloZorb(this->getPower() + z.getPower(), ((*this < z) ? z.getTeamID() : this->getTeamID() ));
}

inline KiloZorb KiloZorb::operator+ (KiloZorb& z){
    return KiloZorb(this->getPower() + z.getPower(), ((*this < z) ? z.getTeamID() : this->getTeamID() ));
}
                                                 
inline bool KiloZorb::operator< (Zorb& z){
    if(this->getTeamID() == z.getTeamID())
        return false;
    else
        return this->getPower() < z.getPower();
}

inline bool KiloZorb::operator< (KiloZorb& z){
    if(this->getTeamID() == z.getTeamID())
        return false;
    else
        return this->getPower() < z.getPower();
}

/*##### Main #####*/

int main(int argc, const char * argv[]) {
    KiloZorb test = {1, 9}, test2 = {1, 3}, test3 = {0, 0};
    Zorb zTest = {1, 12};
    
    cout << "Testing KiloZorb Functions\n--------------------------\n1 KiloZorb (9 teamID) + 1 KiloZorb (3 teamID) = ";
    test3 = test + test2;                                                                  //since overloaded '+' returns a new KiloZorb, and there are no mutator functions,
    cout << test3.getPower() / 1000 << " power, " << test3.getTeamID() << " teamID\n";     //power must be divided by 1000 before printing
                                                
    cout << "1 KiloZorb (9 teamID) + 1 Zorb (12 teamID) = ";
    test3 = test + zTest;
    cout << test3.getPower() / 1000 << " power, " << test3.getTeamID() << " teamID\n";
    
    return 0;
}
