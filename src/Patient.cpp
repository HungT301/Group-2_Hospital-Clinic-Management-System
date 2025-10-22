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
    cout << "Enter diagnosis: ";
    getline(cin, diagnose);
}

void Patient::in() const {
    cout << left << setw(10) << patientID;
    Person::in();
    cout << left
         << setw(20) << symptom
         << setw(20) << diagnose << endl;
}

string Patient::getPatientID() const {
    return patientID;
}

json Patient::toJson() const {
    return {
        {"id", patientID},
        {"name", name},
        {"dob", DOB},
        {"gender", gender},
        {"phone", phone},
        {"symptom", symptom},
        {"diagnosis", diagnose}
    };
}

void Patient::fromJson(const json& j) {
    patientID = j.value("id", "");
    name      = j.value("name", "");
    DOB       = j.value("dob", "");
    gender    = j.value("gender", "");
    phone     = j.value("phone", "");
    symptom   = j.value("symptom", "");
    diagnose  = j.value("diagnosis", "");
}