
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

sql::Driver* driver; //driver s�n�f�na ait "driver" de�i�keni bu s�n�f s�r�c� i�levlerini sa�lar
sql::Connection* con; //connection s�n�f�na ait con... . Bu s�n�f, veritaban�yla ileti�im kurma i�lemlerini sa�lar.
sql::Statement* stmt;  //SQL ifadelerini y�r�tmek i�in kullan�lan s�n�ft�r. Bu s�n�f, sorgular� do�rudan y�r�t�r.
sql::PreparedStatement* pstmt;  // Bu s�n�f, parametrelerin kullan�ld��� sorgular�n veritaban�na g�nderilmesini sa�lar.


Doctor doctor;
Patient patient;

void Sql::DoctorSql(vector<Doctor> doctors) { //int main()
    
    try
    {
        driver = get_driver_instance(); //ba�lant� olu�turma k�sm�
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    //hospital adl� veritaban�na ba�lan�yor
    con->setSchema("hospital");

    /*  stmt = con->createStatement(); //tablo olu�turma k�sm�
      stmt->execute("DROP TABLE IF EXISTS inventory");
      cout << "Finished dropping table (if existed)" << endl;
      stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
      cout << "Finished creating table" << endl;
      delete stmt; */

    pstmt = con->prepareStatement("INSERT INTO doctors(iddoctors,doctor_name,doctor_title) VALUES(?,?,?)");
    for (Doctor doctor : doctors) {
        pstmt->setInt(1, doctor.getId()); //1 in anlam� ilk soru i�aretinin de�eri demektir 
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
        driver = get_driver_instance(); //ba�lant� olu�turma k�sm�
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    //hospital adl� veritaban�na ba�lan�yor
    con->setSchema("hospital");

    /*  stmt = con->createStatement(); //tablo olu�turma k�sm�
      stmt->execute("DROP TABLE IF EXISTS inventory");
      cout << "Finished dropping table (if existed)" << endl;
      stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
      cout << "Finished creating table" << endl;
      delete stmt; */

    pstmt = con->prepareStatement("INSERT INTO doctors(patients_id,patients_name,patients_surname,patients_urgency) VALUES(?,?,?,?)");
    for (Patient patient : patients) {
        pstmt->setInt(1, patient.getId()); //1 in anlam� ilk soru i�aretinin de�eri demektir 
        pstmt->setString(2, patient.getName());
        pstmt->setString(3, patient.getSurname());
        pstmt->setInt(4, patient.getUrgency());
        pstmt->execute();
    }


    delete pstmt;
    delete con;
    system("pause");
    
}

