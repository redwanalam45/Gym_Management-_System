#ifndef PAYMENT_H
#define PAYMENT_H

#include "paymentmethod.h"
#include <string>
#include <iostream>
#include <ctime> 
#include <fstream> 

using namespace std;

class Payment {
private:
    double amount;
    string paymentDate;
    PaymentMethod method;

public:
    Payment(double amt = 0.0, PaymentMethod m = PaymentMethod("Cash"));
    void display() const;

    void saveData(ofstream& ofs) const;
    void loadData(ifstream& ifs);
};

#endif