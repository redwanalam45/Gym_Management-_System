#include "dietplan.h"

DietPlan::DietPlan(string name) : planName(name) {}

void DietPlan::addMeal(const Meal& meal) {
    meals.push_back(meal);
}

void DietPlan::display() const {
    cout << "Diet Plan: " << planName << endl;
    if (meals.empty()) {
        cout << "  (No meals defined)" << endl;
    }
    for (const auto& meal : meals) {
        meal.display();
    }
}

void DietPlan::saveData(ofstream& ofs) const {
    ofs << planName << endl;
    ofs << meals.size() << endl;
    for (const auto& meal : meals) {
        meal.saveData(ofs);
    }
}

void DietPlan::loadData(ifstream& ifs) {
    getline(ifs, planName);
    int numMeals;
    ifs >> numMeals;
    ifs.ignore();
    meals.clear();
    for (int i = 0; i < numMeals; ++i) {
        Meal meal;
        meal.loadData(ifs);
        meals.push_back(meal);
    }
}