#include "nutritionist.h"
#include <iostream>
#include <fstream> 

using namespace std;

Nutritionist::Nutritionist(string name, int age, string contact, string qual)
    : Person(name, age, contact), qualification(qual) {}

void Nutritionist::displayDetails() const {
    cout << "Nutritionist Name: " << name << ", Qualification: " << qualification << endl;
}

DietPlan Nutritionist::createDietPlan(double bmr, string goal) {
    DietPlan customPlan("Custom Diet Plan");
    double targetCalories;

    if (goal == "lose") {
        targetCalories = bmr - 400;
        cout << "Nutritionist suggests a calorie deficit diet of approx. " << targetCalories << " kcal." << endl;
    } else if (goal == "gain") {
        targetCalories = bmr + 400;
        cout << "Nutritionist suggests a calorie surplus diet of approx. " << targetCalories << " kcal." << endl;
    } else {
        targetCalories = bmr;
        cout << "Nutritionist suggests a maintenance diet of approx. " << targetCalories << " kcal." << endl;
    }

    Meal breakfast("Breakfast");
    breakfast.addFoodItem(FoodItem("Oats", 150));
    breakfast.addFoodItem(FoodItem("Milk", 100));
    
    Meal lunch("Lunch");
    lunch.addFoodItem(FoodItem("Brown Rice", 200));
    lunch.addFoodItem(FoodItem("Chicken Breast", 250));
    
    Meal dinner("Dinner");
    dinner.addFoodItem(FoodItem("Fish", 200));
    dinner.addFoodItem(FoodItem("Vegetables", 100));
    
    customPlan.addMeal(breakfast);
    customPlan.addMeal(lunch);
    customPlan.addMeal(dinner);
    
    return customPlan;
}

void Nutritionist::saveData(ofstream& ofs) const {
    Person::saveData(ofs);
    ofs << qualification << endl;
}

void Nutritionist::loadData(ifstream& ifs) {
    Person::loadData(ifs);
    getline(ifs, qualification);
}