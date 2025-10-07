#include "Treatment.hpp"
#include <iostream>
using namespace std;

Treatment::Treatment() {}

Treatment::Treatment(string id, string patientId, string doctorId, string moTa, double chiPhi)
    : id(id),
      patientId(patientId),
      doctorId(doctorId),
      moTa(moTa),
      chiPhi(chiPhi) {}

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
    cout << "Treatment ID: " << id << endl;
    cout << "Patient ID: " << patientId << endl;
    cout << "Doctor ID: " << doctorId << endl;
    cout << "Description: " << moTa << endl;
    cout << "Cost: " << chiPhi << endl;
}

void Treatment::tinhChiPhi() const {
    cout << "Total cost of treatment: " << chiPhi << endl;
}
