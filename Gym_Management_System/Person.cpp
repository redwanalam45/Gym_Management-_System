#include "Person.h"

Person::Person(string n, int a, string c) : name(n), age(a), contact(c) {}

void Person::saveData(ofstream& ofs) const {
    ofs << name << endl;
    ofs << age << endl;
    ofs << contact << endl;
}

void Person::loadData(ifstream& ifs) {
    getline(ifs, name);
    ifs >> age;
    ifs.ignore(); 
    getline(ifs, contact);
}