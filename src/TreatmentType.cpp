#include "treatmenttype.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Medication::Medication() : Treatment() {
    soLuong = 0;
    giaMoiDonVi = 0.0;
}

Medication::Medication(string id, string patientId, string doctorId, string moTa, double cost, int soLuong, double giaMoiDonVi) : Treatment() {
    this->id = id;
    this->patientId = patientId;
    this->doctorId = doctorId;
    this->moTa = moTa;
    this->cost = cost;
    this->soLuong = soLuong;
    this->giaMoiDonVi = giaMoiDonVi;
}

void Medication::nhap() {
    Treatment::nhap();
    cout << "Enter quantity: ";
    cin >> soLuong;
    cout << "Enter price per unit: ";
    cin >> giaMoiDonVi;
    cin.ignore();
}

void Medication::in() const {
    Treatment::in();
    cout << " " << soLuong << " " << fixed << setprecision(2) << giaMoiDonVi;
}

void Medication::tinhChiPhi() const {
    double total = soLuong * giaMoiDonVi;
    cout << " " << fixed << setprecision(2) << total << endl;
}

Surgery::Surgery() : Treatment() {
    phiBacSi = 0.0;
    chiPhiThietBi = 0.0;
}

Surgery::Surgery(string id, string patientId, string doctorId, string moTa, double cost, double phiBacSi, double chiPhiThietBi) : Treatment() {
    this->id = id;
    this->patientId = patientId;
    this->doctorId = doctorId;
    this->moTa = moTa;
    this->cost = cost;
    this->phiBacSi = phiBacSi;
    this->chiPhiThietBi = chiPhiThietBi;
}

void Surgery::nhap() {
    Treatment::nhap();
    cout << "Enter doctor fee: ";
    cin >> phiBacSi;
    cout << "Enter equipment cost: ";
    cin >> chiPhiThietBi;
    cin.ignore();
}

void Surgery::in() const {
    Treatment::in();
    cout << left << setw(20) << " " << fixed << setprecision(2) << phiBacSi << endl;
    cout << left << setw(20) << " " << fixed << setprecision(2) << chiPhiThietBi << endl;
}

void Surgery::tinhChiPhi() const {
    double total = cost + phiBacSi + chiPhiThietBi;
    cout << " " << fixed << setprecision(2) << total << endl;
}

Therapy::Therapy() : Treatment() {
    soBuoi = 0;
    giaMoiBuoi = 0.0;
}

Therapy::Therapy(string id, string patientId, string doctorId, string moTa, double cost, int soBuoi, double giaMoiBuoi) : Treatment() {
    this->id = id;
    this->patientId = patientId;
    this->doctorId = doctorId;
    this->moTa = moTa;
    this->cost = cost;
    this->soBuoi = soBuoi;
    this->giaMoiBuoi = giaMoiBuoi;
}

void Therapy::nhap() {
    Treatment::nhap();
    cout << "Enter number of sessions: ";
    cin >> soBuoi;
    cout << "Enter price per session: ";
    cin >> giaMoiBuoi;
    cin.ignore();
}

void Therapy::in() const {
    Treatment::in();
    cout << left << setw(20) << " " << soBuoi << endl;
    cout << left << setw(20) << " " << fixed << setprecision(2) << giaMoiBuoi << endl;
}

void Therapy::tinhChiPhi() const {
    double total = soBuoi * giaMoiBuoi;
    cout << "Total therapy cost: " << fixed << setprecision(2) << total << endl;
}

