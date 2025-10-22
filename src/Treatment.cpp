#include "Treatment.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Treatment::Treatment() {}

void Treatment::nhap() {
    cout << "Enter treatment ID: ";
    getline(cin, id);
    cout << "Enter patient ID: ";
    getline(cin, patientId);
    cout << "Enter doctor ID: ";
    getline(cin, doctorId);
    cout << "Enter treatment description: ";
    getline(cin, moTa);
    cout << "Enter base cost: ";
    cin >> baseCost;
    cin.ignore();
}

void Treatment::in() const {
    cout << left
         << setw(10) << id
         << setw(15) << patientId
         << setw(15) << doctorId
         << setw(20) << moTa
         << setw(15) << fixed << setprecision(2) << baseCost;
}

void Treatment::sumary() const {
    cout << left
         << setw(15) << treatmentType
         << setw(10) << id
         << setw(15) << patientId
         << setw(15) << doctorId
         << setw(20) << moTa
         << setw(15) << baseCost << endl;
}

string Treatment::getType() const {
    return treatmentType;
}

string Treatment::getID() const {
    return id;
}

double Treatment::tinhChiPhi() const {
    return baseCost;
}

json Treatment::toJson() const {
    return {
        {"type", treatmentType},
        {"id", id},
        {"patientId", patientId},
        {"doctorId", doctorId},
        {"description", moTa},
        {"baseCost", baseCost}
    };
}

void Treatment::fromJson(const json& j) {
    treatmentType = j.value("type", "");
    id = j.value("id", "");
    patientId = j.value("patientId", "");
    doctorId = j.value("doctorId", "");
    moTa = j.value("description", "");
    baseCost = j.value("baseCost", 0.0);
}