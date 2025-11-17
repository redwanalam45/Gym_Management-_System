#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

class FoodItem {
private:
    string name;
    int calories;
public:
    FoodItem(string n = "", int c = 0);
    void display() const;
    void saveData(ofstream& ofs) const;
    void loadData(ifstream& ifs);
};

#endif