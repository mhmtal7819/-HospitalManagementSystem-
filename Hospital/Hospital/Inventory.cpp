#include <iostream>
#include <string>
#include "Inventory.h"
using namespace std;

int Inventory::patientBar = 50;
int Inventory::serum = 50;

Inventory::Inventory() {
	//boþ constructor
}
Inventory::~Inventory() {
	
}
void Inventory::setPatientBar(int patienBar) {
	this->patientBar = patienBar;
}
void Inventory::setSerum(int serum) {
	this->serum = serum;
}
int Inventory::getSerumm() const{
	return serum;
}
int Inventory::getPatientBarr() const{
	return patientBar;
}

int Inventory::getPatientBar() {
	patientBar--;
	return patientBar;
}

int Inventory::getSerum() {
	serum--;
	return serum;
}

void Inventory::patientBarControl() {
	string answer;
	if (getPatientBarr() < 30) {
		cout << "Patient bars are decreasing. Reload ? (Y/N)";
		cin >> answer;
		if (answer == "Yes" || answer == "Y" || answer == "y") {
			reloadPatientBar();
		}
		else if (answer == "No" || answer == "N" || answer == "n") {
			cout << "Remaining bar: " << getPatientBarr();
		}
	}
	else {
		cout << "Remaining bar: " << getPatientBarr() << endl;
	}
}
void Inventory::serumControl() {
	string answer;
	if (getSerumm() < 30) {
		cout << "Serums are decreasing. Reload ? (Y/N)";
		cin >> answer;
		if (answer == "Yes" || answer == "Y" || answer == "y") {
			reloadSerum();
		}
		else if (answer == "No" || answer == "N" || answer == "n") {
			cout << "Remaining serum: " << getSerumm();
		}
	}
	else {
		cout << "Remaining serums : " << getSerumm() << endl;
	}
	
}

void Inventory::reloadPatientBar() {
	setPatientBar(50);
}

void Inventory::reloadSerum() {
	setSerum(50);
}
ostream& operator<<(ostream& os, const Inventory& obj) {
	os << "Remaining patient bar: " << obj.getPatientBarr() << endl; 
		os << "Remaining serum: " << obj.getSerumm() << endl;
	return os;
}