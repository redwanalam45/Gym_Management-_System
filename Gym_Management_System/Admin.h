#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include <string>
#include <fstream>

using namespace std;

class Admin : public Person {
private:
    string adminId;
    string password; 

public:
    Admin(string name = "", int age = 0, string contact = "", string id = "", string pw = "");
    void displayDetails() const override;
    bool authenticate(string inputPassword) const;
    void saveData(ofstream& ofs) const override;
    void loadData(ifstream& ifs) override;
};

#endif