#pragma once
#include <iostream>
#include <string>
using namespace std;

class Inventory {
private:
	static int serum;
	static int patientBar;
public:
	Inventory();
	~Inventory();
	void setSerum(int serum);
	void setPatientBar(int patientBar);
	int getSerumm()  const;
	int getPatientBarr() const;

	static int getSerum();
	static int getPatientBar();

	void serumControl();
	void patientBarControl();
	void reloadSerum();
	void reloadPatientBar();
	friend ostream& operator<<(ostream& os, const Inventory& obj);
	
};
