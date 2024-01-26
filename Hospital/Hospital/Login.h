#pragma once
#include "PatientOperations.h"
#include "Doctor.h"
#include "Inventory.h"
#include "WorkingHours.h"
#include <iostream>
using namespace std;
class Login {
public:
	void login();
	bool passwordControl(string password);
private:
	PatientOperations patients;
	Doctor doctors;
	Inventory inventory;
	WorkingHours workingHours;
};