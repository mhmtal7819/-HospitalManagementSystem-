
#include <stdlib.h>

#include <vector>
#include "Sql.h"


#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std; 

//for demonstration only. never save your password in the code!
const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "12345";

sql::Driver* driver; //driver sýnýfýna ait "driver" deðiþkeni bu sýnýf sürücü iþlevlerini saðlar
sql::Connection* con; //connection sýnýfýna ait con... . Bu sýnýf, veritabanýyla iletiþim kurma iþlemlerini saðlar.
sql::Statement* stmt;  //SQL ifadelerini yürütmek için kullanýlan sýnýftýr. Bu sýnýf, sorgularý doðrudan yürütür.
sql::PreparedStatement* pstmt;  // Bu sýnýf, parametrelerin kullanýldýðý sorgularýn veritabanýna gönderilmesini saðlar.


Doctor doctor;
Patient patient;

void Sql::DoctorSql(vector<Doctor> doctors) { //int main()
    
    try
    {
        driver = get_driver_instance(); //baðlantý oluþturma kýsmý
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    //hospital adlý veritabanýna baðlanýyor
    con->setSchema("hospital");

    /*  stmt = con->createStatement(); //tablo oluþturma kýsmý
      stmt->execute("DROP TABLE IF EXISTS inventory");
      cout << "Finished dropping table (if existed)" << endl;
      stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
      cout << "Finished creating table" << endl;
      delete stmt; */

    pstmt = con->prepareStatement("INSERT INTO doctors(iddoctors,doctor_name,doctor_title) VALUES(?,?,?)");
    for (Doctor doctor : doctors) {
        pstmt->setInt(1, doctor.getId()); //1 in anlamý ilk soru iþaretinin deðeri demektir 
        pstmt->setString(2, doctor.getName());
        pstmt->setString(3, doctor.getTitle());
        pstmt->execute();
    }
   

    delete pstmt;
    delete con;
    system("pause");
    
} 


void Sql::PatientSql(vector<Patient> patients) {
    try
    {
        driver = get_driver_instance(); //baðlantý oluþturma kýsmý
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    //hospital adlý veritabanýna baðlanýyor
    con->setSchema("hospital");

    /*  stmt = con->createStatement(); //tablo oluþturma kýsmý
      stmt->execute("DROP TABLE IF EXISTS inventory");
      cout << "Finished dropping table (if existed)" << endl;
      stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
      cout << "Finished creating table" << endl;
      delete stmt; */

    pstmt = con->prepareStatement("INSERT INTO doctors(patients_id,patients_name,patients_surname,patients_urgency) VALUES(?,?,?,?)");
    for (Patient patient : patients) {
        pstmt->setInt(1, patient.getId()); //1 in anlamý ilk soru iþaretinin deðeri demektir 
        pstmt->setString(2, patient.getName());
        pstmt->setString(3, patient.getSurname());
        pstmt->setInt(4, patient.getUrgency());
        pstmt->execute();
    }


    delete pstmt;
    delete con;
    system("pause");
    
}

