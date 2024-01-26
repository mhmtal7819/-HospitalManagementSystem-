#pragma once
#include "WorkingHours.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Doctor {
private:
	string name;
	int id;
	string title;
	vector<Doctor> doctors;
	vector<Doctor> defaultVectorDoctor;
	vector<int> workingHoursIds;
	//vector<int> doctorsIds;
	
public:
	Doctor(string name, string title,int id);
	Doctor();
	

	void setId(int id);
	void setName(string name);
	void setTitle(string title);

	int getId() const;
	string getName() const;
	string getTitle() const;

	 int getIId();
    
	void defaultDoctor();
	

	void addDoctor();
	void deleteDoctor();
	void updateDoctor();
	void getAllDoctors();
	
	bool idControl(int select);
	
	friend vector<Doctor> doctorData(Doctor& obj);

	void matchDoctorsWithWorkingHours(vector<Doctor>& doctors, vector<WorkingHours> workingHours);
	void doctorShifts();
	

};
