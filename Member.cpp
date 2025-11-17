#include "Member.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Member::Member(string name, int age, string contact, string gender, long long id)
    : Person(name, age, contact), memberId(id), gender(gender), attendanceCount(0) {}

void Member::markAttendance() { attendanceCount++; }
void Member::logWeight(double weight) { weightLog.push_back(weight); }

void Member::displayProgress() const {
    cout << "\n--- Your Progress Report ---" << endl;
    cout << "Total Attendance: " << getAttendanceCount() << " days." << endl;
    if (weightLog.empty()) { cout << "No weight logged yet." << endl; }
    else {
        cout << "Weight History: ";
        for (double w : weightLog) { cout << w << "kg -> "; }
        cout << "End" << endl;
        if (weightLog.size() > 1) {
            double change = weightLog.back() - weightLog.front();
            cout << "Overall change: " << (change >= 0 ? "+" : "") << change << "kg" << endl;
        }
    }
    cout << "--------------------------" << endl;
}

int Member::getAttendanceCount() const { return attendanceCount; }
string Member::getGender() const { return gender; }
int Member::getAge() const { return age; }
int Member::getId() const { return memberId; }

void Member::displayDetails() const {
    cout << "\n--- Member Profile ---" << endl;
    cout << "ID: " << memberId << " | Name: " << name << endl;
    cout << "Age: " << age << " | Gender: " << gender << " | Contact: " << contact << endl;
    cout << "--- Plans & Packages ---" << endl;
    memberInfo.display();
    workoutPlan.display();
    dietPlan.display();
    cout << "----------------------" << endl;
}

void Member::saveData(ofstream& ofs) const {
    ofs << "Member" << endl; 
    ofs << memberId << endl;
    Person::saveData(ofs); 
    ofs << gender << endl;
    ofs << attendanceCount << endl;
    ofs << weightLog.size() << endl;
    for(double w : weightLog) { ofs << w << " "; }
    ofs << endl;
    memberInfo.saveData(ofs); 
    workoutPlan.saveData(ofs);
    dietPlan.saveData(ofs);
}

void Member::loadData(ifstream& ifs) {
    string tag;
    getline(ifs, tag);  
    if (tag != "Member") {
        return;
    }
    ifs >> memberId;
    ifs.ignore(); 
    Person::loadData(ifs); 
    getline(ifs, gender);
    ifs >> attendanceCount;
    int logSize;
    ifs >> logSize;
    weightLog.clear();
    for(int i = 0; i < logSize; ++i) { double w; ifs >> w; weightLog.push_back(w); }
    if (logSize > 0) ifs.ignore(); 
    memberInfo.loadData(ifs); 
    workoutPlan.loadData(ifs);
    dietPlan.loadData(ifs);
}

// Friend function implementation 
void showMemberInternal(const Member& m) {
    cout << "\n[Friend] Internal Snapshot:" << endl;
    cout << "ID: " << m.memberId << endl;
    cout << "Name: " << m.name << endl;
    cout << "Age: " << m.age << endl;
    cout << "Contact: " << m.contact << endl;
    cout << "Gender: " << m.gender << endl;
    cout << "AttendanceCount: " << m.attendanceCount << endl;
    cout << "WeightLog size: " << m.weightLog.size() << endl;
    if (!m.weightLog.empty()) {
        cout << "Weights: ";
        for (double w : m.weightLog) cout << w << " ";
        cout << endl;
    }
    cout << "--------------------------" << endl;
}