#ifndef PACKAGETYPE_H
#define PACKAGETYPE_H

#include <string>
#include <iostream>
#include <fstream> 
using namespace std;

class PackageType {
private:
    string typeName;
public:
    PackageType(string name = "Bronze");
    void display() const;
    string getName() const { return typeName; } 

    void saveData(ofstream& ofs) const;
    void loadData(ifstream& ifs);
};

#endif