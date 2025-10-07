#include "Patient.hpp"
#include <iostream>

using namespace std;

Patient::Patient() {}

Patient::Patient(string id, string name, string DOB, string phone,
                 string gender, string symptoms, string diagnosis) {
    this->id = id;
    this->name = name;
    this->DOB = DOB;
    this->phone = phone;
    this->gender = gender;
    this->symptoms = symptoms;
    this->diagnosis = diagnosis;
}

void Patient::nhap() {
    cout << "Enter patient ID: ";
    getline(cin, id);

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter date of birth: ";
    getline(cin, DOB);

    cout << "Enter phone: ";
    getline(cin, phone);

    cout << "Enter gender: ";
    getline(cin, gender);

    cout << "Enter symptoms: ";
    getline(cin, symptoms);

    cout << "Enter diagnosis: ";
    getline(cin, diagnosis);
}

void Patient::in() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Date of birth: " << DOB << endl;
    cout << "Phone: " << phone << endl;
    cout << "Gender: " << gender << endl;
    cout << "Symptoms: " << symptoms << endl;
    cout << "Diagnosis: " << diagnosis << endl;
}

string Patient::getID() const {
    return id;
}

