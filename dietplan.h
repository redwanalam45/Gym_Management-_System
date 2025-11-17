#ifndef DIETPLAN_H
#define DIETPLAN_H

#include "meal.h"
#include <vector>
#include <string>
#include <fstream> 

class DietPlan {
private:
    string planName;
    vector<Meal> meals;
public:
    DietPlan(string name = "Not Set");
    void addMeal(const Meal& meal);
    void display() const;
    void saveData(ofstream& ofs) const;
    void loadData(ifstream& ifs);
};

#endif