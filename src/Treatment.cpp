#include "treatment.hpp"
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
    cout << left << setw(20) << " " << id << endl;
    cout << left << setw(20) << " " << patientId << endl;
    cout << left << setw(20) << " " << doctorId << endl;
    cout << left << setw(20) << " " << moTa << endl;
    cout << left << setw(20) << " " << fixed << setprecision(2) << cost << endl;
}

void Treatment::computeCost() const {
    cout << " " << fixed << setprecision(2) << cost << endl;
}
