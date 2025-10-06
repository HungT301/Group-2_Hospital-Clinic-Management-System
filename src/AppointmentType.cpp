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
    cout << "Room: " << room << endl;
    cout << "Purpose: " << purpose << endl;
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
    cout << "Surgery type: " << surgeryType << endl;
    cout << "Operation room: " << operationRoom << endl;
    cout << "Main surgeon: " << mainSurgeon << endl;
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
    cout << "Therapy type: " << therapyType << endl;
    cout << "Session count: " << sessionCount << endl;
    cout << "Doctor name: " << doctorName << endl;
}