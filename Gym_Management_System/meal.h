#ifndef MEAL_H
#define MEAL_H

#include "fooditem.h"
#include <vector>
#include <string>
#include <fstream> 

class Meal {
private:
    string name;
    vector<FoodItem> items;
public:
    Meal(string n = "");
    void addFoodItem(const FoodItem& item);
    void display() const;
    void saveData(ofstream& ofs) const;
    void loadData(ifstream& ifs);
};

#endif