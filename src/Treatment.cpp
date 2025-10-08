#include "Treatment.hpp"
#include <iostream>
using namespace std;

Treatment::Treatment() {}

void Treatment::nhap() {
    cout << "Enter Treatment ID: ";
    getline(cin, id);
    cout << "Enter Patient ID: ";
    getline(cin, patientId);
    cout << "Enter Doctor ID: ";
    getline(cin, doctorId);
    cout << "Enter Description: ";
    getline(cin, moTa);
    cout << "Enter Cost: ";
    cin >> chiPhi;
    cin.ignore();
}

void Treatment::in() const {
    cout << " " << id << endl;
    cout << " " << patientId << endl;
    cout << " " << doctorId << endl;
    cout << " " << moTa << endl;
    cout << " " << chiPhi << endl;
}

void Treatment::tinhChiPhi() const {
    cout << " " << chiPhi << endl;
}


