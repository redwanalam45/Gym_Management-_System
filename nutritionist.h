#ifndef NUTRITIONIST_H
#define NUTRITIONIST_H

#include "Person.h"
#include "dietplan.h" 
#include "fooditem.h" 
#include "meal.h"     
#include <string>
#include <fstream> 

using namespace std;

class Nutritionist : public Person {
private:
    string qualification;

public:
    Nutritionist(string name = "", int age = 0, string contact = "", string qual = "");
    void displayDetails() const override;
    DietPlan createDietPlan(double bmr, string goal);
    void saveData(ofstream& ofs) const override;
    void loadData(ifstream& ifs) override;
};

#endif