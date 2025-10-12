#include "Appointment.hpp"

#include <iostream>
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
	cout << id << " " << patientId << " " << doctorId << " " << thoiGian;
}

string Appointment::getID() const {
	return id;
}