#include "AlgorithmClass.h"
#include <algorithm>




/*void AlgorithmClass::algortihmFunction() {
    vector<Doctor> algvectorDoc = doctorData(algorithmDoctor);
    vector <WorkingHours> algvectorWork = dataWorkingHours(workingHours);
    algorithmDoctor.matchDoctorsWithWorkingHours(algvectorDoc, algvectorWork);
}*/



/*void AlgorithmClass::matchDoctorsWithWorkingHours(vector<Doctor>& doctors, vector<WorkingHours> workingHours)
{
	// (sah�p oldukklar� �al��ma saatine g�re s�ralar)
	sort(doctors.begin(), doctors.end(),
		[](const Doctor& a, const Doctor& b) { return a.workingHoursIds.size() < b.workingHoursIds.size(); });

	// Greedy matching
	for (const WorkingHours& wh : workingHours) {
		//(en az say�da �al��ma grubuna sahip doctoru bul)
		auto minDoctorIt = std::min_element(doctors.begin(), doctors.end(),
			[](const Doctor& a, const Doctor& b) { return a.workingHoursIds.size() < b.workingHoursIds.size(); });

		// (gurplar� doctorlarla e�le�tir)
		minDoctorIt->workingHoursIds.push_back(wh.getId());
	}

	// Sonu�lar� display et 
	cout << "DoctorShifts kontrol.." << endl;
	for (const Doctor& doctor : doctors) {
		std::cout << "Doctor " << doctor.getName() << " (ID: " << doctor.getId() << ") is assigned to working hours: ";
		for (int whId : doctor.workingHoursIds) {
			std::cout << whId << " ";
		}
		std::cout << std::endl;
	}
} */
