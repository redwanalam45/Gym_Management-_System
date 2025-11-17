#include "exercise.h"
#include <fstream> 

Exercise::Exercise(string n, int s, int r) : name(n), sets(s), reps(r) {}

void Exercise::display() const {
    cout << "  - " << name << " (" << sets << " sets x " << reps << " reps)" << endl;
}

void Exercise::saveData(ofstream& ofs) const {
    ofs << name << endl;
    ofs << sets << endl;
    ofs << reps << endl;
}

void Exercise::loadData(ifstream& ifs) {
    getline(ifs, name);
    ifs >> sets;
    ifs >> reps;
    ifs.ignore();
}