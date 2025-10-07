#include "Patient.hpp"

#include <iostream>
using namespace std;

Patient::Patient() {}

void Patient::nhap() {
    Person::nhap();
    cout << "Enter symptom: ";
    getline(cin, symptom);
    cout << "Enter diagnosi: ";
    getline(cin, diagnose);
}

void Patient::in() const {
    Person::in();
    cout << " " << symptom << " " << diagnose << endl;
}

string Patient::getPatientID() const {
    return patientID;
}
