#pragma once
#include "Patient.h"
#include "Inventory.h"
class PatientsUrgency:public Patient {
private:
	int urgency;
	Inventory inventory;
public:
	
	int getUrgency();
	PatientsUrgency();
	void setUrgency(int height, int weight);
};