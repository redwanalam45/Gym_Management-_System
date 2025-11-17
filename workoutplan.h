#ifndef WORKOUTPLAN_H
#define WORKOUTPLAN_H

#include "exercise.h"
#include <vector>
#include <string>
#include <fstream> 

class WorkoutPlan {
private:
    string planName;
    vector<Exercise> exercises;
public:
    WorkoutPlan(string name = "Not Set");
    void addExercise(const Exercise& ex);
    void display() const;
    void saveData(ofstream& ofs) const;
    void loadData(ifstream& ifs);
};

#endif