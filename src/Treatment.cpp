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
    cout << id << " " << patientId << " " << doctorId << " " << moTa << " " << fixed << setprecision(2) << tinhChiPhi();
}

double Treatment::tinhChiPhi() const {
    return baseCost;
}

