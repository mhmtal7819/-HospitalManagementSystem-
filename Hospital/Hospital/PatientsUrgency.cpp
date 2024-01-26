#include <iostream>
#include "PatientsUrgency.h"
using namespace std;

PatientsUrgency::PatientsUrgency() {
	
}
void PatientsUrgency::setUrgency(int height=0, int weight=0) {
	int height_ = (height * height) / 10000;
	int urgency_ = weight / height_;
	if (urgency_ >= 35) {
		this->urgency = 1;
	}
	if (urgency_ >= 25 && urgency_ < 35) {
		this->urgency = 2;
	}
	if (urgency_ < 25) {
		this->urgency = 3;
	}

	if (getUrgency() == 1) {
		inventory.getSerum();
		inventory.getPatientBar();
	}
	else {
		inventory.getPatientBar();
	}
	inventory.patientBarControl();
	inventory.serumControl();
}
int PatientsUrgency::getUrgency() {
	return urgency;
}