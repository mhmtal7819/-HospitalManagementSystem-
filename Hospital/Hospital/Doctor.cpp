#include "Doctor.h"
#include "WorkingHours.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

 
 WorkingHours workingHourss;




Doctor::Doctor(string name, string title,int id) {
	setName(name);
	setId(id);
	setTitle(title);
}
Doctor::Doctor() {
	defaultVectorDoctor.push_back(Doctor("mehmet", "doctor", getIId()));
	defaultVectorDoctor.push_back(Doctor("samet", "doctor", getIId()));
	defaultVectorDoctor.push_back(Doctor("ali", "doctor", getIId()));
	defaultVectorDoctor.push_back(Doctor("hasan", "doctor", getIId()));
	defaultVectorDoctor.push_back(Doctor("hamit", "doctor", getIId()));
	defaultVectorDoctor.push_back(Doctor("furkan", "doctor", getIId()));
	defaultVectorDoctor.push_back(Doctor("bekir", "doctor", getIId())); 
	defaultVectorDoctor.push_back(Doctor("meryem", "doctor", getIId()));
	doctors = std::vector<Doctor>();
	defaultDoctor();
	
}

void Doctor::setName(string name) {
	this->name = name;
}
void Doctor::setId(int id) {
	this->id = id;
}
void Doctor::setTitle(string title) {
	this->title = title;
}
int Doctor::getId() const {
	return id;
}
string Doctor::getName()const {
	return name;
}
string Doctor::getTitle()const {
	return title;
}
int Doctor::getIId() {
	
	id++;
	setId(id);
    return id;
}

void Doctor::defaultDoctor() {
	for (Doctor vector : defaultVectorDoctor) {
		doctors.push_back(Doctor(vector.getName(), vector.getTitle(), vector.getId()));
	}
	
}

void Doctor::addDoctor() {
	
	string name;
	string title;
	cout << "Doctor name: ";
	cin >> name;
	cout << endl;
	cout << "Title: ";
	cin >> title;
	cout << endl;
	doctors.push_back(Doctor(name, title,getIId()));
}
void Doctor::getAllDoctors() {
	
	

	for (int i = 0; i < doctors.size(); i++) {
		cout << "Id: " << doctors[i].getId() << endl;
			cout << "Title: " << doctors[i].getTitle() << endl;
			cout << "Name: " << doctors[i].getName() << endl;
		cout << endl;
	}
}

void Doctor::deleteDoctor() {
	int select;
	getAllDoctors();
	cout << "Enter id: ";
	cin >> select;
	if (idControl(select)) {
		doctors.erase(doctors.begin() + (select-1));
		cout << "Doctor was erased" << endl;
	}
	else {
		cout << "Wrong id number" << endl;
	}
}

void Doctor::updateDoctor() {
	int select;
	string value,name,title;
	getAllDoctors();
	cout << "Enter id: ";
	cin >> select;
	cout << endl;
	if (idControl(select)) {
		cout << "Which value do you want to change? (name/title ?)";
		cin >> value;
		if (value == "name") {
			cout << "Enter new name: ";
			cin >> name;
			doctors[select-1].setName(name);
			cout << " Doctor's name was updated.." << endl;
		}
		else if (value == "title") {
			cout << "Enter new title: ";
			cin >> title;
			doctors[select-1].setTitle(title);
			cout << " Doctor's title was updated.." << endl;
		}
		else {
			cout << "Invalid value.." << endl;
		}
	}
	
}

bool Doctor::idControl(int select) {
	for (int i = 0; i < doctors.size(); i++) {
		if (select == doctors[i].getId()) {
			return true;
		}
	}
	return false;
}


void Doctor::matchDoctorsWithWorkingHours(vector<Doctor>& doctors, vector<WorkingHours> workingHours) {
	sort(doctors.begin(), doctors.end(),
		[](const Doctor& a, const Doctor& b) { return a.workingHoursIds.size() < b.workingHoursIds.size(); });

	// Greedy matching
	for (const WorkingHours& wh : workingHours) {
		

		auto minDoctorIt = std::min_element(doctors.begin(), doctors.end(),
			[](const Doctor& a, const Doctor& b) { return a.workingHoursIds.size() < b.workingHoursIds.size(); });

		// `minDoctorIt` iþaretçisinin geçerli bir doktora iþaret ettiðinden emin olun
		if (minDoctorIt != doctors.end()) { // Iteratorün geçerliliðini kontrol et
			if (minDoctorIt->id == 0) { // id deðerini kontrol et
				// Hata ver
				return;
			}

			// `workingHoursIds` vektörünün boþ olmadýðýndan emin olun
			if (minDoctorIt->workingHoursIds.empty()) {
				// Vektörün boyutunu artýr
				minDoctorIt->workingHoursIds.resize(1);
			}

			// Çalýþma saatlerini ekle
			minDoctorIt->workingHoursIds.push_back(wh.getId());
		}


	}
}

void Doctor::doctorShifts() {
	matchDoctorsWithWorkingHours(doctors, workingHourss.vectorWork);
	// Sonuçlarý display et 
	cout << "DoctorShifts kontrol.." << endl;
	for (const Doctor& doctor : doctors) {
		std::cout << "Doctor " << doctor.name << " (ID: " << doctor.id << ") is assigned to working hours: ";
		for (int whId : doctor.workingHoursIds) {
			std::cout << whId << " ";
		}
		std::cout << std::endl;
	}
}





