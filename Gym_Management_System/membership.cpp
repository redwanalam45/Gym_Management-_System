#include "membership.h"
#include <iostream>
#include <fstream> 

using namespace std;

Membership::Membership(PackageType t, Duration d, double p) 
    : type(t), duration(d), price(p) {}

void Membership::display() const {
    type.display();
    cout << ", Duration: " << duration.getDuration() << " months, Price: $" << price << endl;
}

void Membership::saveData(ofstream& ofs) const {
    ofs << type.getName() << endl; 
    ofs << duration.getDuration() << endl; 
    ofs << price << endl;
}

void Membership::loadData(ifstream& ifs) {
    string typeName;
    getline(ifs, typeName);
    type = PackageType(typeName); 
    int durMonths;
    ifs >> durMonths;
    duration = Duration(durMonths); 
    ifs >> price;
    ifs.ignore(); 
}