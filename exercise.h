#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

class Exercise {
private:
    string name;
    int sets;
    int reps;
public:
    Exercise(string n = "", int s = 0, int r = 0);
    void display() const;
    void saveData(ofstream& ofs) const;
    void loadData(ifstream& ifs);
};

#endif