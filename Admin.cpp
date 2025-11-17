#include "Admin.h"
#include <iostream>
#include <fstream>

Admin::Admin(string name, int age, string contact, string id, string pw)
    : Person(name, age, contact), adminId(id), password(pw) {}

void Admin::displayDetails() const {
    cout << "Admin Name: " << name << ", ID: " << adminId << ", Contact: " << contact << endl;
}

bool Admin::authenticate(string inputPassword) const {
    return password == inputPassword;
}

void Admin::saveData(ofstream& ofs) const {
    Person::saveData(ofs);
    ofs << adminId << endl;
}

void Admin::loadData(ifstream& ifs) {
    Person::loadData(ifs);
    getline(ifs, adminId);
}