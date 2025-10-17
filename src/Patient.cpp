#include "Patient.hpp"

#include <iostream>
#include <iomanip>
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
    cout << left << setw(10) << patientID;
    Person::in();
    cout << left
         << setw(10) << symptom
         << setw(10) << diagnose << endl;
}

string Patient::getPatientID() const {
    return patientID;
}
