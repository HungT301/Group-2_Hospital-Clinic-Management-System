#include "../include/AppointmentType.hpp"
#include <iostream>
using namespace std;

//CheckupAppointment
CheckupAppointment::CheckupAppointment() {}

void CheckupAppointment::nhap() {
    Appointment::nhap();
    cout << "Enter room: ";
    getline(cin, room);
    cout << "Enter purpose: ";
    getline(cin, purpose);
}

void CheckupAppointment::in() const {
    Appointment::in();
    cout << " " << room << " " << purpose << endl;
}

//SurgeryAppointment
SurgeryAppointment::SurgeryAppointment() {}

void SurgeryAppointment::nhap() {
    Appointment::nhap();
    cin.ignore();
    cout << "Enter surgery type: ";
    getline(cin, surgeryType);
    cout << "Enter operation room: ";
    getline(cin, operationRoom);
    cout << "Enter main surgeon: ";
    getline(cin, mainSurgeon);
}

void SurgeryAppointment::in() const {
    Appointment::in();
    cout << " " << surgeryType << " " << operationRoom << " " << mainSurgeon << endl;
}

//TherapyAppointment
TherapyAppointment::TherapyAppointment() {}

void TherapyAppointment::nhap() {
    Appointment::nhap();
    cin.ignore();
    cout << "Enter therapy type: ";
    getline(cin, therapyType);
    cout << "Enter session count: ";
    cin >> sessionCount;
    cin.ignore();
    cout << "Enter doctor name: ";
    getline(cin, doctorName);
}

void TherapyAppointment::in() const {
    Appointment::in();
    cin.ignore();
    cout << " " << therapyType << " " << sessionCount << " " << doctorName << endl;
}