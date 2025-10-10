#include "Treatment.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Treatment::Treatment() {
    id = "";
    patientId = "";
    doctorId = "";
    moTa = "";
    cost = 0.0;
}

void Treatment::nhap() {
    cout << "Enter treatment ID: ";
    getline(cin, id);
    cout << "Enter patient ID: ";
    getline(cin, patientId);
    cout << "Enter doctor ID: ";
    getline(cin, doctorId);
    cout << "Enter treatment description: ";
    getline(cin, moTa);
    cout << "Enter cost: ";
    cin >> cost;
    cin.ignore();
}

void Treatment::in() const {
    cout << id << " " << patientId << " " << doctorId << " " << moTa << " " << fixed << setprecision(2) << cost;
}

void Treatment::computeCost() const {
    cout << " " << fixed << setprecision(2) << cost << endl;
}

