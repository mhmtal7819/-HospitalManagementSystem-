#include <iostream>
#include <string>
#include <vector>
#include "Doctor.h"
#include "WorkingHours.h"
#include "PatientOperations.h"
#include "Login.h"
#include <stdlib.h>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;

const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "12345";

sql::Driver* driver;
sql::Connection* con;
sql::Statement* stmt;
sql::PreparedStatement* pstmt;

void initializeDatabase() {
    try {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        con->setSchema("hospital");
    }
    catch (sql::SQLException e) {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}

void closeDatabase() {
    delete con;
}

vector<Doctor> doctorData(Doctor& doctor_) {
    
    return doctor_.doctors;
}

vector<PatientOperations> patientData(PatientOperations& patient_) {
    
    return patient_.patients;
}

Doctor doctorMain;
PatientOperations patientMain;

void doctorSql(vector<Doctor> doctors);
void patientSql(vector<PatientOperations> patients);

int main() {
    initializeDatabase();

    Login login;
    login.login();

    

    

    try {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e) {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    con->setSchema("hospital");

    stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS doctors");
    cout << "Finished dropping table (if existed)" << endl;
    stmt->execute("CREATE TABLE doctors (iddoctors INT AUTO_INCREMENT PRIMARY KEY, doctor_name VARCHAR(50), doctor_title VARCHAR(50));");
    cout << "Finished creating table" << endl;
    delete stmt;

    stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS patients");
    cout << "Finished dropping table (if existed)" << endl;
    stmt->execute("CREATE TABLE patients (patients_id INT AUTO_INCREMENT PRIMARY KEY, patients_name VARCHAR(50), patients_surname VARCHAR(50), patients_urgency INTEGER);");
    cout << "Finished creating table" << endl;
    delete stmt;
    cout << "Your data is being saved.." << endl;

    doctorSql(doctorData(doctorMain));
    patientSql(patientData(patientMain));

    cout << "Control.." << endl;

    delete pstmt;
    delete con;

    system("pause");
    return 0;
}

void doctorSql(vector<Doctor> doctors) {
    pstmt = con->prepareStatement("INSERT INTO doctors(doctor_name,doctor_title) VALUES(?,?)");

    for (Doctor& doctor : doctors) {
        pstmt->setString(1, doctor.getName());
        pstmt->setString(2, doctor.getTitle());
        pstmt->execute();
    }

    delete pstmt;
}

void patientSql(vector<PatientOperations> patients) {
    pstmt = con->prepareStatement("INSERT INTO patients(patients_name,patients_surname,patients_urgency) VALUES(?,?,?)");

    for (PatientOperations& patient : patients) {
        pstmt->setString(1, patient.getName());
        pstmt->setString(2, patient.getSurname());
        pstmt->setInt(3, patient.getUrgency());
        pstmt->execute();
    }

    delete pstmt;
}
