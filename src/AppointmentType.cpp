#include "AppointmentType.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

//CheckupAppointment
CheckupAppointment::CheckupAppointment() {
    appointmentType = "Checkup";
}

void CheckupAppointment::nhap() {
    Appointment::nhap();
    cout << "Enter room: ";
    getline(cin, room);
    cout << "Enter purpose: ";
    getline(cin, purpose);
}

void CheckupAppointment::in() const {
    Appointment::in();
    cout << left
         << setw(10) << room
         << setw(20) << purpose << endl;
}

//SurgeryAppointment
SurgeryAppointment::SurgeryAppointment() {
    appointmentType = "Surgery";
}

void SurgeryAppointment::nhap() {
    Appointment::nhap();
    cout << "Enter surgery type: ";
    getline(cin, surgeryType);
    cout << "Enter operation room: ";
    getline(cin, operationRoom);
    cout << "Enter main surgeon: ";
    getline(cin, mainSurgeon);
}

void SurgeryAppointment::in() const {
    Appointment::in();
    cout << left
         << setw(15) << surgeryType
         << setw(10) << operationRoom
         << setw(20) << mainSurgeon << endl;
}

//TherapyAppointment
TherapyAppointment::TherapyAppointment() {
    appointmentType = "Therapy";
}

void TherapyAppointment::nhap() {
    Appointment::nhap();
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
    cout << left
         << setw(15) << therapyType
         << setw(10) << sessionCount
         << setw(20) << doctorName << endl;
}