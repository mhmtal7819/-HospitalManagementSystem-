// WorkingHours.cpp
#include "WorkingHours.h"
#include "Doctor.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;



Doctor doctorv;



WorkingHours::WorkingHours(int id, string day, string hour) : id(id) { //burda manuel atama yapabiliriz.
    // days ve hours dizilerinden ilgili elemanlarý kopyalayýn
    for (int i = 0; i < days->length(); i++) {
        if (day == days[i]) {
            days[0] = day;
            break;
        }
    }
    for (int i = 0; i < hours->length(); i++) {
        if (hour == hours[i]) {
            hours[0] = hour;
            break;
        }
    }
}

WorkingHours::WorkingHours()  {
    
   
    for (int i = 0; i <= days->length(); i++) {
        for (int j = 0; j < hours->length(); j++) {
            vectorWork.push_back(WorkingHours(getIId(), days[i], hours[j]));
        }
    }
    
}




void WorkingHours::getShifts() {
    
    doctorv.doctorShifts();
    
   
    
    int ch;
    
    for (int i = 0; i <=days->length(); i++) {
        for (int j = 0; j < hours->length(); j++) {
            if (capacity[i * hours->length() + j] < 5) {
                cout << "Id: " << vectorWork[i * hours->length() + j].getId() << ", Day: " << days[i] << ", Hour: " << hours[j] << endl;
            }
            
        }
    }
    cout << "Please make your choice: ";
    cin >> ch;
    
        cout << "Your appointment has been created.." << endl;
        capacity[ch-1]++;
    
    
}



void WorkingHours::setId(int id) {
    this->id = id;
}

int WorkingHours::getId() const{
    return id;
}

int WorkingHours::getIId() {
    id++;
    setId(id); 
    return id;
}

