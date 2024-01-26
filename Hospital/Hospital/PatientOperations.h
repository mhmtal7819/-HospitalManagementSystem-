#pragma once
#include "Patient.h"
#include "Inventory.h"
#include "PatientsUrgency.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PatientOperations :public Patient {
private:
	vector<PatientOperations> patients;
	vector<PatientOperations> dfPatients;
	int urgency;
	Inventory inventory; 
	PatientsUrgency ptU;
public:
	PatientOperations(string name, string surname,int urgency,int id);
	PatientOperations();
	void addPatient();
	void getPatient();
	
	void defaultPatients();

	int getUrgency();
	friend vector<PatientOperations> patientData(PatientOperations& obj);
};