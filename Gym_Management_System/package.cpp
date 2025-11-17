#include "package.h" 
#include <iostream>  
#include <fstream>   

Package::Package(string n, PackageType t, Duration d, double p)
    : name(n), type(t), duration(d), price(p) {}

void Package::display() const {
    cout << "Package Name: " << name << ", Type: ";
    type.display();
    cout << ", Duration: " << duration.getDuration() << " months, Price: $" << price << endl;
}

void Package::saveData(ofstream& ofs) const {
    ofs << name << endl;
    type.saveData(ofs); 
    duration.saveData(ofs); 
    ofs << price << endl;
}

void Package::loadData(ifstream& ifs) {
    getline(ifs, name);
    type.loadData(ifs); 
    duration.loadData(ifs); 
    ifs >> price;
    ifs.ignore();
}