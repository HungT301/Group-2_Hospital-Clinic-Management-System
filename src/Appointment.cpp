#include "../include/Appointment.hpp"

#include <iostream>
using namespace std;

Appointment::Appointment() {
	id = patientId = doctorId = thoiGian = "";
}

void Appointment::nhap() {
	cout << "Enter appointment id: "; cin >> id;
	cout << "Enter patient id: "; cin >> patientId;
	cout << "Enter doctor id: "; cin >> doctorId;
	cout << "Enter time: "; cin >> thoiGian;
}

void Appointment::in() const {
	cout << "Appointment id: " << id << endl;
	cout << "Patient id: " << patientId << endl;
	cout << "Doctor id: " << doctorId << endl;
	cout << "Time: " << thoiGian << endl;
}