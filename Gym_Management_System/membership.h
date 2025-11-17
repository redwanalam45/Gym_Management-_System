#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include "duration.h"
#include "packagetype.h"
#include <iostream>
#include <fstream> 

using namespace std;

class Membership {
private:
    PackageType type;
    Duration duration;
    double price;
public:
    Membership(PackageType t = PackageType("Bronze"), Duration d = Duration(1), double p = 0.0);
    void display() const;
    void saveData(ofstream& ofs) const;
    void loadData(ifstream& ifs);
};

#endif