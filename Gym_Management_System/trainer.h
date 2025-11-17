#ifndef TRAINER_H
#define TRAINER_H

#include "Person.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Trainer : public Person {
private:
    string specialization;
    vector<string> assignedMembers; 

public:
    Trainer(string name = "", int age = 0, string contact = "", string spec = "");
    void displayDetails() const override;
    void assignMember(string memberName);
    void saveData(ofstream& ofs) const override;
    void loadData(ifstream& ifs) override;
};

#endif