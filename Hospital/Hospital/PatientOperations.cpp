#include "PatientOperations.h"
#include "Patient.h"

#include <iostream>
#include <string>
PatientOperations* patientOp;

PatientOperations::PatientOperations(string name, string surname, int urgency, int id) :Patient(name, surname,id) {
	this->urgency = urgency;
}
PatientOperations::PatientOperations() {
	dfPatients.push_back(PatientOperations("mehmet", "yilmaz", ptU.getUrgency(), getIId()));
	defaultPatients();
}
void PatientOperations::defaultPatients() {
	for (PatientOperations pt : dfPatients) {
		
		patients.push_back(PatientOperations(pt.getName(), pt.getSurname(), 2, pt.getId()));
	}
}
void PatientOperations::addPatient() {
	string name;
	string surname;
	int height;
	int weight;
	cout << "Your name: ";
	cin >> name;
	cout << "Your lastname: ";
	cin >> surname;
	cout << "Height(cm): ";
	cin >> height;
	cout << "Weight(kg): ";
	cin >> weight;
	ptU.setUrgency(height, weight); 
	

	cout << endl;
	patients.push_back(PatientOperations(name, surname, ptU.getUrgency(),getIId()));
}

int PatientOperations::getUrgency() {
	return urgency;
}
void PatientOperations::getPatient() {
	for (int i = 0; i < patients.size(); i++) {
		cout << "Id: " << patients[i].getId() << endl;
		cout << "Name: " << patients[i].getName() << endl;
		cout << "Surname: " << patients[i].getSurname() << endl;
		cout << "Urgency: " << patients[i].getUrgency() << endl;
		cout << endl;
	}
}