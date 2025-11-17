#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

class Person {
protected:
    string name;
    int age;
    string contact;

public:
    Person(string n = "", int a = 0, string c = "");
    virtual ~Person() {} 

    string getName() const { return name; } 
    int getAge() const { return age; } 

    //Declaration of virtual function
    virtual void displayDetails() const = 0; 
    
    virtual void saveData(ofstream& ofs) const;
    virtual void loadData(ifstream& ifs);
};

#endif