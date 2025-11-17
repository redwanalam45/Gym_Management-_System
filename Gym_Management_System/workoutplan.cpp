#include "workoutplan.h"

WorkoutPlan::WorkoutPlan(string name) : planName(name) {
    if (name == "Beginner's Workout") {
        addExercise(Exercise("Push-ups", 3, 10));
        addExercise(Exercise("Squats", 3, 12));
        addExercise(Exercise("Plank", 3, 30)); 
    } else if (name == "Advanced Cardio") {
        addExercise(Exercise("Running", 1, 30)); 
        addExercise(Exercise("Cycling", 1, 45)); 
    }
}

void WorkoutPlan::addExercise(const Exercise& ex) {
    exercises.push_back(ex);
}

void WorkoutPlan::display() const {
    cout << "Workout Plan: " << planName << endl;
    if (exercises.empty()) {
        cout << "  (No exercises defined)" << endl;
    }
    for (const auto& ex : exercises) {
        ex.display();
    }
}

void WorkoutPlan::saveData(ofstream& ofs) const {
    ofs << planName << endl;
    ofs << exercises.size() << endl;
    for (const auto& ex : exercises) {
        ex.saveData(ofs);
    }
}

void WorkoutPlan::loadData(ifstream& ifs) {
    getline(ifs, planName);
    int numExercises;
    ifs >> numExercises;
    ifs.ignore();
    exercises.clear();
    for (int i = 0; i < numExercises; ++i) {
        Exercise ex;
        ex.loadData(ifs);
        exercises.push_back(ex);
    }
}