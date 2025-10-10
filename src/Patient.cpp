#include "Patient.hpp"

#include <iostream>
using namespace std;

Patient::Patient() {}

void Patient::nhap() {
    cout << "Enter patient id: ";
    getline(cin, patientID);
    Person::nhap();
    cout << "Enter symptom: ";
    getline(cin, symptom);
    cout << "Enter diagnosi: ";
    getline(cin, diagnose);
}

void Patient::in() const {
    cout << patientID << " ";
    Person::in();
    cout << " " << symptom << " " << diagnose << endl;
}

string Patient::getPatientID() const {
    return patientID;
}
