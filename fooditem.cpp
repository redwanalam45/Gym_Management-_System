#include "fooditem.h"
#include <fstream> 

FoodItem::FoodItem(string n, int c) : name(n), calories(c) {}

void FoodItem::display() const {
    cout << "    - " << name << " (" << calories << " kcal)" << endl;
}

void FoodItem::saveData(ofstream& ofs) const {
    ofs << name << endl;
    ofs << calories << endl;
}

void FoodItem::loadData(ifstream& ifs) {
    getline(ifs, name);
    ifs >> calories;
    ifs.ignore();
}