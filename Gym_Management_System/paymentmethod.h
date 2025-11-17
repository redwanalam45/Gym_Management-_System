#ifndef PAYMENTMETHOD_H
#define PAYMENTMETHOD_H

#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

class PaymentMethod {
private:
    string methodType; 
public:
    PaymentMethod(string type = "Cash");
    void display() const;
    string getType() const { return methodType; }

    
    void saveData(ofstream& ofs) const;
    void loadData(ifstream& ifs);
};

#endif