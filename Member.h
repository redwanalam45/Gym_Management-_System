#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include "membership.h" 
#include "workoutplan.h"
#include "dietplan.h"
#include <string>
#include <vector>
#include <fstream> 

using namespace std;

class Member : public Person {
private:
    long long memberId;
    string gender;
    int attendanceCount;
    vector<double> weightLog;
    Membership memberInfo;
    WorkoutPlan workoutPlan;
    DietPlan dietPlan;

public:
    Member(string name = "", int age = 0, string contact = "", string gender = "", long long id = 0);
    
    void setMembership(const Membership& m) { memberInfo = m; }
    void setWorkoutPlan(const WorkoutPlan& wp) { workoutPlan = wp; }
    void setDietPlan(const DietPlan& dp) { dietPlan = dp; }
    
    void displayDetails() const override;
    void saveData(ofstream& ofs) const override;
    void loadData(ifstream& ifs) override;
    
    void markAttendance();
    void logWeight(double weight);
    void displayProgress() const;
    
    int getAttendanceCount() const;
    string getGender() const;
    int getAge() const;
    int getId() const;

    //Friend function declaration
    friend void showMemberInternal(const Member& m);
};

#endif