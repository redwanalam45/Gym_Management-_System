#include "meal.h"

Meal::Meal(string n) : name(n) {}

void Meal::addFoodItem(const FoodItem& item) {
    items.push_back(item);
}

void Meal::display() const {
    cout << "  * " << name << ":" << endl;
    for (const auto& item : items) {
        item.display();
    }
}

void Meal::saveData(ofstream& ofs) const {
    ofs << name << endl;
    ofs << items.size() << endl;
    for (const auto& item : items) {
        item.saveData(ofs);
    }
}

void Meal::loadData(ifstream& ifs) {
    getline(ifs, name);
    int numItems;
    ifs >> numItems;
    ifs.ignore();
    items.clear();
    for (int i = 0; i < numItems; ++i) {
        FoodItem item;
        item.loadData(ifs);
        items.push_back(item);
    }
}