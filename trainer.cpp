#include "trainer.h"
#include <iostream>
#include <fstream>

Trainer::Trainer(string name, int age, string contact, string spec)
    : Person(name, age, contact), specialization(spec) {}

void Trainer::displayDetails() const {
    cout << "Trainer Name: " << name << ", Age: " << age << ", Contact: " << contact << ", Specialization: " << specialization << endl;
    if (!assignedMembers.empty()) {
        cout << "  Assigned Members: ";
        for (const auto& member : assignedMembers) {
            cout << member << " ";
        }
        cout << endl;
    }
}

void Trainer::assignMember(string memberName) {
    assignedMembers.push_back(memberName);
    cout << memberName << " assigned to " << name << endl;
}

void Trainer::saveData(ofstream& ofs) const {
    Person::saveData(ofs);
    ofs << specialization << endl;
    ofs << assignedMembers.size() << endl;
    for (const auto& member : assignedMembers) {
        ofs << member << endl;
    }
}

void Trainer::loadData(ifstream& ifs) {
    Person::loadData(ifs);
    getline(ifs, specialization);
    int numMembers;
    ifs >> numMembers;
    ifs.ignore();
    assignedMembers.clear();
    for (int i = 0; i < numMembers; ++i) {
        string memberName;
        getline(ifs, memberName);
        assignedMembers.push_back(memberName);
    }
}