#include "Patient.hpp"
#include <iostream>

using namespace std;

Patient::Patient() {}

Patient::Patient(string id, string ten, string ngaysinh, string sdt,
                 string gioiTinh, string trieuChung, string chanDoan) {
    this->id = id;
    this->ten = ten;
    this->ngaysinh = ngaysinh;
    this->sdt = sdt;
    this->gioiTinh = gioiTinh;
    this->trieuChung = trieuChung;
    this->chanDoan = chanDoan;
}

void Patient::nhap() {
    cout << "Enter patient ID: ";
    getline(cin, id);

    cout << "Enter name: ";
    getline(cin, ten);

    cout << "Enter date of birth: ";
    getline(cin, ngaysinh);

    cout << "Enter phone number: ";
    getline(cin, sdt);

    cout << "Enter gender: ";
    getline(cin, gioiTinh);

    cout << "Enter symptoms: ";
    getline(cin, trieuChung);

    cout << "Enter diagnosis: ";
    getline(cin, chanDoan);
}

void Patient::in() const {
    cout << "\n--- PATIENT INFORMATION ---\n";
    cout << "ID: " << id << endl;
    cout << "Name: " << ten << endl;
    cout << "Date of birth: " << ngaysinh << endl;
    cout << "Phone: " << sdt << endl;
    cout << "Gender: " << gioiTinh << endl;
    cout << "Symptoms: " << trieuChung << endl;
    cout << "Diagnosis: " << chanDoan << endl;
}

string Patient::getID() const {
    return id;
}

