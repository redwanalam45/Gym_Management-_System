#ifndef PACKAGE_H
#define PACKAGE_H

#include "packagetype.h"
#include "duration.h"
#include <iostream>
#include <string>    
#include <fstream>   

using namespace std;

class Package {
private:
    string name;
    PackageType type;
    Duration duration;
    double price;

public:
    Package(string n = "Basic", PackageType t = PackageType("Bronze"), Duration d = Duration(1), double p = 0.0);
    void display() const;
    double getPrice() const { return price; }
    string getName() const { return name; }
    void saveData(ofstream& ofs) const;
    void loadData(ifstream& ifs);
};

#endif