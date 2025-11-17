#include "duration.h"
#include <fstream> 
#include <limits>   

using namespace std;

Duration::Duration(int m) : months(m) {}

int Duration::getDuration() const {
    return months;
}

ostream& operator<<(ostream& os, const Duration& d) {
    os << d.months << " months";
    return os;
}

void Duration::saveData(ofstream& ofs) const {
    ofs << months << std::endl;
}

void Duration::loadData(ifstream& ifs) {
    ifs >> months;
    
    ifs.ignore(numeric_limits<streamsize>::max(), '\n'); 
}