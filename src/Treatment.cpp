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
         << setw(10) << patientId
         << setw(10) << doctorId
         << setw(20) << moTa
         << setw(15) << fixed << setprecision(2) << baseCost;
}

void Treatment::sumary() const {
    cout << left
         << setw(10) << treatmentType
         << setw(10) << id
         << setw(10) << patientId
         << setw(10) << doctorId
         << setw(15) << moTa
         << setw(10) << baseCost << endl;
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

