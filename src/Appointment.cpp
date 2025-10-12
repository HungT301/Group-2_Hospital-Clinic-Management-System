#include "Appointment.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

Appointment::Appointment() {}

void Appointment::nhap() {
	cout << "Enter appointment id: "; 
	getline(cin, id);
	cout << "Enter patient id: "; 
	getline(cin, patientId);
	cout << "Enter doctor id: "; 
	getline(cin, doctorId);
	cout << "Enter time: "; 
	getline(cin, thoiGian);
}

void Appointment::in() const {
	cout << left
		 << setw(10) << id
		 << setw(10) << patientId
		 << setw(10) << doctorId
		 << setw(10) << thoiGian;
}

void Appointment::sumary() const {
	cout << left
		 << setw(10) << appointmentType
		 << setw(10) << id
		 << setw(10) << patientId
		 << setw(10) << doctorId
		 << setw(10) << thoiGian << endl;
}

string Appointment::getType() const {
	return appointmentType;
}

string Appointment::getID() const {
	return id;
}