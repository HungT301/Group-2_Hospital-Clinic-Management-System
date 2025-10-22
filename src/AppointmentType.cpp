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

json CheckupAppointment::toJson() const {
    json base = Appointment::toJson();
    base["room"] = room;
    base["purpose"] = purpose;
    return base;
}

void CheckupAppointment::fromJson(const json& j) {
    Appointment::fromJson(j);
    room = j.value("room", "");
    purpose = j.value("purpose", "");
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
         << setw(15) << operationRoom
         << setw(20) << mainSurgeon << endl;
}

json SurgeryAppointment::toJson() const {
    json base = Appointment::toJson();
    base["surgeryType"] = surgeryType;
    base["operationRoom"] = operationRoom;
    base["mainSurgeon"] = mainSurgeon;
    return base;
}

void SurgeryAppointment::fromJson(const json& j) {
    Appointment::fromJson(j);
    surgeryType = j.value("surgeryType", "");
    operationRoom = j.value("operationRoom", "");
    mainSurgeon = j.value("mainSurgeon", "");
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
         << setw(15) << sessionCount
         << setw(20) << doctorName << endl;
}

json TherapyAppointment::toJson() const {
    json base = Appointment::toJson();
    base["therapyType"] = therapyType;
    base["sessionCount"] = sessionCount;
    base["doctorName"] = doctorName;
    return base;
}

void TherapyAppointment::fromJson(const json& j) {
    Appointment::fromJson(j);
    therapyType = j.value("therapyType", "");
    sessionCount = j.value("sessionCount", 0);
    doctorName = j.value("doctorName", "");
}