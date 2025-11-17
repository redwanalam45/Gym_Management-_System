#include "payment.h"
#include <fstream>
#include <iomanip> 
#include <ctime>

Payment::Payment(double amt, PaymentMethod m) : amount(amt), method(m) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d", ltm);
    paymentDate = buf;
}

void Payment::display() const {
    cout << "Payment Amount: $" << amount << ", Date: " << paymentDate << ", ";
    method.display();
    cout << endl;
}

void Payment::saveData(ofstream& ofs) const {
    ofs << amount << endl;
    ofs << paymentDate << endl;
    method.saveData(ofs); 
}

void Payment::loadData(ifstream& ifs) {
    ifs >> amount;
    ifs.ignore();
    getline(ifs, paymentDate);
    method.loadData(ifs); 
}