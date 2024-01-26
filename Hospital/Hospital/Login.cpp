#include "Login.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;



/*PatientOperations patients;
Doctor doctors;
Inventory inventory;
WorkingHours workingHours;*/


void Login::login() {
    
    cout << "Welcome the Hospital Management System" << endl;
    int login;
    do {

        cout << "Please make your choice: " << "\n" << "1-)Manager Login " << "\n" << "2-)Patient Login" << "\n" << "3-)EXIT"
            << endl;
        cin >> login;
        if (login == 1) {
            int ch;
            string password;
            cout << "Please enter password: ";
            cin >> password;
            if (passwordControl(password)) {
                do {


                    cout << "1-)Add Doctor" << "\n" << "2-)Delete Doctor" << "\n" << "3-)Update Doctor" << "\n" << "4-)Get all Doctors"
                        << "\n" << "5-)Get all Patients" << "\n" << "6-) Inventory Control"<<"\n" <<"7-) Exit"<< endl;
                    cout << "Please make your choice: \n";
                    cin >> ch;
                    switch (ch) {
                    case 1:
                        doctors.addDoctor();
                        break;
                    case 2:
                        doctors.deleteDoctor();
                        break;
                    case 3:
                        doctors.updateDoctor();
                        break;
                    case 4:
                        doctors.getAllDoctors();
                        break;
                    case 5:
                        patients.getPatient();
                        break;
                    case 6:
                        cout << inventory;
                        break;

                    default:
                        cout << "\a";

                    }
                } while (ch != 7);
            }
            else {
                cout << "Wrong password" << endl;
                
            }
        }
        if (login == 2) {
            int ch;
            do {
                cout << "1-)Patient registration" << "\n" << "2-)Appointment" << "\n" << "3-)Exit" << endl;
                cout << "Your choice: ";
                cin >> ch;
                switch (ch) {
                case 1:
                    patients.addPatient();
                    break;
                case 2:
                    workingHours.getShifts();
                default:
                    cout << "\a";
                }
            } while (ch != 3);
        }
        
    } while (login != 3);

}

bool Login::passwordControl(string password) {
    if (password == "123") {
        return true;
    }
    else {
        return false;
    }
    return false;
}

