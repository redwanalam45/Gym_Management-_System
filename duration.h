#ifndef DURATION_H
#define DURATION_H

#include <iostream> 
#include <fstream> 

class Duration {
private:
    int months;

public:
    Duration(int m = 1);
    int getDuration() const; 

    friend std::ostream& operator<<(std::ostream& os, const Duration& d);

    void saveData(std::ofstream& ofs) const; 
    void loadData(std::ifstream& ifs);      
};

#endif