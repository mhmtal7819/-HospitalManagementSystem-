#pragma once
#include "Doctor.h"
#include "Patient.h"
class Sql {
public:
	void DoctorSql(vector<Doctor> doctors); //add doctor database
	void PatientSql(vector<Patient> patients); //add patients database
};
