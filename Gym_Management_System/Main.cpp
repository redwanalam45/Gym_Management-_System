#include <iostream>
#include <vector>
#include <fstream>
#include <limits> 
#include <string>
#include <cmath>
#include "Member.h"        
#include "Nutritionist.h"  
#include "Admin.h"        
#include "trainer.h"       
#include "package.h"      
#include "packagetype.h"   
#include "duration.h"      
#include "workoutplan.h"   
#include "dietplan.h"      
#include "membership.h"    
#include "fooditem.h"      
#include "meal.h"         
#include "paymentmethod.h" 
#include "payment.h"       

using namespace std;

vector<Member*> g_members;
long long nextMemberId = 2025001; 
Nutritionist g_nutritionist("Dr. Anika", 32, "01721372013", "MSc in Nutrition"); 
Admin g_admin("Admin User", 40, "admin@gym.com", "ADM001", "admin123"); 

void adminPanel();
void memberPanel(Member* loggedInMember);
void registerUser();
void loginUser();
void loadMembersFromFile();
void saveMembersToFile();
void getPersonalizedPlan(Member* member);
void logMyWeight(Member* member);


int main() {
    loadMembersFromFile(); 
    int choice;
    do {
        cout << "\n\n===== Welcome to Fitness Zone Gym =====" << endl;
        cout << "1. Login (For Existing Members)" << endl;
        cout << "2. Register (For New Members)" << endl;
        cout << "3. Admin Login" << endl;
        cout << "0. Exit Program" << endl;
        cout << "=====================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        while (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Enter your choice: ";
            cin >> choice;
        }

        switch (choice) {
            case 1: loginUser(); break;
            case 2: registerUser(); break;
            case 3: adminPanel(); break;
            case 0: cout << "Thank you for using our system. Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    
    for (auto* member : g_members) { 
        delete member; 
    }
    g_members.clear(); 
    return 0;
}


void registerUser() {
    string name, contact, gender;
    int age, packageChoice, durationChoice;

    cout << "\n--- New Member Registration ---" << endl;
    cout << "Enter your full name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    
    while (cin.fail() || age <= 0) {
        cout << "Invalid age. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> age;
    }
    cout << "Enter your contact number: ";
    cin >> contact;
    cout << "Enter your gender (Male/Female): ";
    cin >> gender;

    cout << "\n--- Choose a Package Type ---" << endl;
    cout << "1. Gold (Access to all facilities)" << endl;
    cout << "2. Silver (Gym + Cardio)" << endl;
    cout << "3. Bronze (Gym only)" << endl;
    cout << "Enter choice (1-3): ";
    cin >> packageChoice;
    while (cin.fail() || packageChoice < 1 || packageChoice > 3) {
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> packageChoice;
    }

    cout << "\n--- Choose Membership Duration ---" << endl;
    cout << "1. 3 Months" << endl;
    cout << "2. 6 Months" << endl;
    cout << "3. 12 Months" << endl;
    cout << "Enter choice (1-3): ";
    cin >> durationChoice;
    while (cin.fail() || durationChoice < 1 || durationChoice > 3) {
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> durationChoice;
    }

    PackageType selectedPackage;
    Duration selectedDuration;
    double price = 0.0;

    if (packageChoice == 1) selectedPackage = PackageType("Gold");
    else if (packageChoice == 2) selectedPackage = PackageType("Silver");
    else selectedPackage = PackageType("Bronze"); // Default to Bronze

    if (durationChoice == 1) { selectedDuration = Duration(3); price = 3000; }
    else if (durationChoice == 2) { selectedDuration = Duration(6); price = 5500; }
    else { selectedDuration = Duration(12); price = 10000; } // Default to 12 months

    Member* newMember = new Member(name, age, contact, gender, nextMemberId++);
    Membership memberInfo(selectedPackage, selectedDuration, price);
    newMember->setMembership(memberInfo);


    newMember->setWorkoutPlan(WorkoutPlan("Beginner's Workout"));
    newMember->setDietPlan(DietPlan("General Balanced Diet"));

    g_members.push_back(newMember); 
    saveMembersToFile(); 

    cout << "\nRegistration Successful!" << endl;
    cout << "Your Member ID is: " << newMember->getId() << endl;
    cout <<". Please remember it for login." << endl;
}

void loginUser() {
    int id;
    cout << "\n--- Member Login ---" << endl;
    cout << "Enter your Member ID: ";
    cin >> id;
    
    while (cin.fail() || id <= 0) {
        cout << "Invalid ID. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> id;
    }


    Member* foundMember = nullptr;
    for (auto* member : g_members) {
        if (member->getId() == id) {
            foundMember = member;
            break;
        }
    }

    if (foundMember != nullptr) {
        cout << "\nWelcome back, " << foundMember->getName() << "!" << endl;
        memberPanel(foundMember); 
    } else {
        cout << "Sorry, Member ID not found. Please register or try again." << endl;
    }
}


void memberPanel(Member* loggedInMember) {
    int choice;
    do {
        cout << "\n--- Member Dashboard ---" << endl;
        cout << "1. View My Profile & Plans" << endl;
        cout << "2. Get a Personalized Diet Plan from Nutritionist" << endl;
        cout << "3. Log My Current Weight" << endl;
        cout << "4. View My Progress Report" << endl;
        cout << "5. Mark Today's Attendance" << endl;
        cout << "0. Logout" << endl;
        cout << "------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter your choice: ";
            cin >> choice;
        }

        switch (choice) {
            case 1: loggedInMember->displayDetails(); break;
            case 2: getPersonalizedPlan(loggedInMember); break;
            case 3: logMyWeight(loggedInMember); break;
            case 4: loggedInMember->displayProgress(); break;
            case 5: 
                loggedInMember->markAttendance();
                saveMembersToFile(); 
                cout << "\nAttendance marked! Total days: " << loggedInMember->getAttendanceCount() << endl;
                break;
            case 0: cout << "Logging out..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
}


void getPersonalizedPlan(Member* member) {
    double height, weight;
    string goal;

    cout << "\n--- Personalized Plan Generator ---" << endl;
    g_nutritionist.displayDetails(); 
    cout << "To create a plan, we need some information." << endl;
    cout << "Enter your height in meters (e.g., 1.75): ";
    cin >> height;
    while (cin.fail() || height <= 0) {
        cout << "Invalid height. Please enter a positive number in meters: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> height;
    }
    cout << "Enter your weight in kilograms (e.g., 70): ";
    cin >> weight;
    while (cin.fail() || weight <= 0) {
        cout << "Invalid weight. Please enter a positive number in kilograms: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> weight;
    }
    cout << "What is your goal? (type 'lose', 'gain', or 'maintain'): ";
    cin >> goal;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    
    if (height > 0 && weight > 0) {
        double bmr;
        float bmi;
        bmi = weight / (height*height);
        cout<<"\nYour BMI is "<<bmi<<endl;
        if (member->getGender() == "Male" || member->getGender() == "male") {
            bmr = (10 * weight) + (6.25 * height * 100) - (5 * member->getAge()) + 5;
        } else { 
            bmr = (10 * weight) + (6.25 * height * 100) - (5 * member->getAge()) - 161;
        }
        cout << "\nYour estimated BMR is: " << bmr << " calories/day." << endl;
        
        DietPlan newPlan = g_nutritionist.createDietPlan(bmr, goal); 
        member->setDietPlan(newPlan); 
        saveMembersToFile(); 
        cout << "\nYour new personalized diet plan has been generated and saved!" << endl;
        newPlan.display(); 
    } else {
        cout << "Invalid height or weight. Cannot create personalized plan." << endl;
    }
}

void logMyWeight(Member* member) {
    double currentWeight;
    cout << "\n--- Log Your Weight ---" << endl;
    cout << "Enter your current weight in kg: ";
    cin >> currentWeight;
    while (cin.fail() || currentWeight <= 0) {
        cout << "Invalid weight. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> currentWeight;
    }

    if(currentWeight > 0) {
        member->logWeight(currentWeight); 
        saveMembersToFile(); 
        cout << "Weight logged successfully!" << endl;
        member->displayProgress(); 
    } else {
        cout << "Invalid weight. Weight not logged." << endl;
    }
}


void adminPanel() {
    string password;
    cout << "\n--- Admin Login ---" << endl;
    cout << "Enter admin password: ";
    cin >> password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    if (g_admin.authenticate(password)) { 
        cout << "Admin login successful!" << endl;
        int choice;
        do {
            cout << "\n--- Admin Dashboard ---" << endl;
            cout << "1. View All Members" << endl;
            cout << "2. Find Member by ID" << endl;
            cout << "0. Logout" << endl;
            cout << "-----------------------" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            while (cin.fail()) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
            }

            if (choice == 1) {
                if (g_members.empty()) {
                    cout << "No members in the system." << endl;
                } else {
                    for (const auto* member : g_members) {
                        member->displayDetails(); 
                    }
                }
            } else if (choice == 2) {
                int id;
                cout << "Enter Member ID to find: ";
                cin >> id;
                while (cin.fail() || id <= 0) {
                    cout << "Invalid ID. Please enter a positive number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> id;
                }

                bool found = false;
                for (const auto* member : g_members) {
                    if (member->getId() == id) {
                        member->displayDetails(); 
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Member not found with ID: " << id << endl;
            } else if (choice != 0) {
                cout << "Invalid choice. Please try again." << endl;
            }

        } while (choice != 0);
    } else {
        cout << "Incorrect password. Access denied." << endl;
    }
}


void saveMembersToFile() {
    ofstream outFile("members.dat"); 
    if (!outFile) {
        cerr << "Error: Could not open file 'members.dat' for writing." << endl;
        return;
    }
    outFile << g_members.size() << endl; 
    for (const auto* member : g_members) {
        member->saveData(outFile); 
    }
    outFile.close();
}

void loadMembersFromFile() {
    ifstream inFile("members.dat"); 
    if (!inFile) {
    
        return;
    }
    for (auto* member : g_members) {
        delete member;
    }
    g_members.clear();

    int count;
    inFile >> count; 
    if (inFile.fail()) { 
        inFile.close();
        return;
    }
    inFile.ignore(); 

    for (int i = 0; i < count; ++i) {
        string typeIdentifier;
        getline(inFile, typeIdentifier); 

        if (typeIdentifier == "Member") {
            Member* member = new Member(); 
            member->loadData(inFile); 
            g_members.push_back(member); 
            if (member->getId() >= nextMemberId) {
                nextMemberId = member->getId() + 1; 
            }
        }
        
    }
    inFile.close();
}