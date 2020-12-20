#include <iostream>
#include <string>

using namespace std;


// ***** Add your Date class definition and driver program at the end of this file
// (at about line 107). *****




// The Month class provided below is a "helper" class for your Date class.
// Note that although both classes are defined in this single compilation unit (file),
// we are not nesting the Month class in the Date class or vice versa.

class Month {
    friend class Date;
    
    friend ostream& operator<< (ostream&, Month);
    
    private:
        enum EMonth { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
            
        Month() : _month(Jan) {} // default constructor
        Month(int im) : _month( static_cast<EMonth>(im) ) {} // value constructor
        
        void setMonth(string m) { _month = StringToEMonth(m); } // mutator functions
        void setMonth(int im) { _month = static_cast<EMonth>(im); }
        
        /* Private helper member functions */
        EMonth StringToEMonth(string);
        int MonthToInt() { return static_cast<int>(_month); }
        string MonthToString();
        string MonthToString2();

        EMonth _month;
};

/* Definitions of helper member functions for class Month */

Month::EMonth Month::StringToEMonth(string m) {
    if (m == "Jan") return Jan;
    else if (m == "Feb") return Feb;
    else if (m == "Mar") return Mar;
    else if (m == "Apr") return Apr;
    else if (m == "May") return May;
    else if (m == "Jun") return Jun;
    else if (m == "Jul") return Jul;
    else if (m == "Aug") return Aug;
    else if (m == "Sep") return Sep;
    else if (m == "Oct") return Oct;
    else if (m == "Nov") return Nov;
    else if (m == "Dec") return Dec;
    else {
        cerr << "Month::StringToMonth: Invalid input month \"" << m << "\"\n";
        exit(1);
    }
}

string Month::MonthToString() {
    switch (_month) {
        case Jan: return "Jan";
        case Feb: return "Feb";
        case Mar: return "Mar";
        case Apr: return "Apr";
        case May: return "May";
        case Jun: return "Jun";
        case Jul: return "Jul";
        case Aug: return "Aug";
        case Sep: return "Sep";
        case Oct: return "Oct";
        case Nov: return "Nov";
        case Dec: return "Dec";
        default:
            cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
            exit(1);
    }
}

string Month::MonthToString2() {
    switch (_month) {
        case Jan: return "January";
        case Feb: return "February";
        case Mar: return "March";
        case Apr: return "April";
        case May: return "May";
        case Jun: return "June";
        case Jul: return "July";
        case Aug: return "August";
        case Sep: return "September";
        case Oct: return "October";
        case Nov: return "November";
        case Dec: return "December";
        default:
            cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
            exit(1);
    }
}

/* Definition of friend function operator<< */

ostream& operator<< (ostream& out, Month m) {
    out << m.MonthToString2();
    return out;
}


// ***** Add your Date class definition and driver program below. *****

class Date {
private:
  Month month;
  int  dayOfMonth;
  int  year;

public:
  Date();
  Date(int numMonth, int day, int refYear);
  Date(string stingMonth, int day, int refYear );
  void changeMonth(int numMonth );
  void outputDateAsInt(ostream& out);
  void outputDateAsString(ostream& out);
  string getMonth() {
    return month.MonthToString2();
  }

  int getDayOfMonth() {
    return dayOfMonth;
  }

  int getYear() {
    return year;
  }
  
  Date operator++ () {
    return Date( month.MonthToInt() , dayOfMonth, ++year);
  }
};

Date::Date(){
  month =  Month();
  dayOfMonth = 1;
  year = 2018;
}

Date::Date(int numMonth, int day, int refYear) : Date() {
  month.setMonth(numMonth);
  dayOfMonth = day;
  year = refYear;
}

Date::Date(string stringMonth, int day, int refYear) : Date() {
  month.StringToEMonth(stringMonth);
  dayOfMonth = day;
  year = refYear;
}

void Date::changeMonth(int numMonth) {
  month.setMonth(numMonth);
}

void Date::outputDateAsInt(ostream& out) {
  out << month.MonthToInt() << "/" << dayOfMonth << "/" << year;
}

void Date::outputDateAsString(ostream& out) {
  out << month.MonthToString() << " " << dayOfMonth << ", " << year;
}

ostream& operator<< (ostream& out, Date date) {
  out << date.getMonth() << " " << date.getDayOfMonth() << ", " << date.getYear();
  return out;
}

int main(int argc, char *argv[]) {
  Date date1 = Date();
  Date date2 = Date(2, 1, 2018);
  Date date3 = Date("Mar", 1, 2018);
  Date date4 = Date(12, 31, 2018);
  cout << date1 << endl;
  cout << date2 << endl;
  cout << date3 << endl;
  
  date3.changeMonth(7);
  cout << date3 << endl;
  date4.outputDateAsInt(cout);
  cout << endl;
  date4.outputDateAsString(cout);
  cout << endl;
  ++date4;
  cout << date4;
  return 0;
}
