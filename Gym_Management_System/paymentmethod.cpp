#include "paymentmethod.h"
#include <fstream>

PaymentMethod::PaymentMethod(string type) : methodType(type) {}

void PaymentMethod::display() const {
    cout << "Payment Method: " << methodType;
}

void PaymentMethod::saveData(ofstream& ofs) const {
    ofs << methodType << endl;
}

void PaymentMethod::loadData(ifstream& ifs) {
    getline(ifs, methodType);
}