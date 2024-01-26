#pragma once
#include <iostream>
#include <string>
using namespace std;
class Patient { //kalýtým vereceði iki sýnýf: patientcondition,patientOperetions
public:
	Patient(string name, string surname,int id);
	Patient();
	void setName(string name);
	void setSurname(string surname);
	void setHeight(int height);
	void setWeight(int weight);
	void setId(int id);

	int getId();
	string getName();
	string getSurname();
	int getHeight();
	int getWeight();

	 int getIId();
protected:
	string name;
	string surname;
	int id;
	int height;
	int weight;
};