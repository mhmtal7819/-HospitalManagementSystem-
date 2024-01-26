// WorkingHours.h
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WorkingHours {
private:
    int id;
    
    int capacity[28] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6 };
    string days[7] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
    string hours[4] = { "9-11","11-13","13-15","15-17" };
    

public:
    WorkingHours(int id, string days, string hours);
    WorkingHours();
   
    void setId(int id);
    int getId() const;
    int getIId();

    
    void getShifts();
    
    vector<WorkingHours> vectorWork;
};