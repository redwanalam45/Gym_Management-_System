#include "packagetype.h"
#include <iostream>  
#include <fstream>   

PackageType::PackageType(string name) : typeName(name) {}

void PackageType::display() const {
    cout << "Package: " << typeName;
}

void PackageType::saveData(ofstream& ofs) const {
    ofs << typeName << endl;
}

void PackageType::loadData(ifstream& ifs) {
    getline(ifs, typeName);
}