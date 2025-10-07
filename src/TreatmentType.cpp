#include "TreatmentType.hpp"
#include <iostream>
using namespace std;

Medication::Medication() {}

Medication::Medication(string id, string patientId, string doctorId, string moTa, double chiPhi, int soLuong, double giaMoiDonVi)
: Treatment(id, patientId, doctorId, moTa, chiPhi), soLuong(soLuong), giaMoiDonVi(giaMoiDonVi) {}

void Medication::nhap() {
    Treatment::nhap();
    cout << "Nhap so luong thuoc: ";
    cin >> soLuong;
    cout << "Nhap gia moi don vi: ";
    cin >> giaMoiDonVi;
    cin.ignore();
}

void Medication::in() const {
    Treatment::in();
    cout << "So luong thuoc: " << soLuong << endl;
    cout << "Gia moi don vi: " << giaMoiDonVi << endl;
}

void Medication::tinhChiPhi() const {
    double tong = chiPhi + soLuong * giaMoiDonVi;
    cout << "Tong chi phi thuoc: " << tong << endl;
}

Surgery::Surgery() {}

Surgery::Surgery(string id, string patientId, string doctorId, string moTa, double chiPhi, double phiBacSi, double chiPhiThietBi)
: Treatment(id, patientId, doctorId, moTa, chiPhi),phiBacSi(phiBacSi), chiPhiThietBi(chiPhiThietBi) {}

void Surgery::nhap() {
    Treatment::nhap();
    cout << "Nhap phi bac si: ";
    cin >> phiBacSi;
    cout << "Nhap chi phi thiet bi: ";
    cin >> chiPhiThietBi;
    cin.ignore();
}

void Surgery::in() const {
    Treatment::in();
    cout << "Phi bac si: " << phiBacSi << endl;
    cout << "Chi phi thiet bi: " << chiPhiThietBi << endl;
}

void Surgery::tinhChiPhi() const {
    double tong = chiPhi + phiBacSi + chiPhiThietBi;
    cout << "Tong chi phi phau thuat: " << tong << endl;
}

Therapy::Therapy() {}

Therapy::Therapy(string id, string patientId, string doctorId, string moTa, double chiPhi, int soBuoi, double giaMoiBuoi)
: Treatment(id, patientId, doctorId, moTa, chiPhi), soBuoi(soBuoi), giaMoiBuoi(giaMoiBuoi) {}

void Therapy::nhap() {
    Treatment::nhap();
    cout << "Nhap so buoi tri lieu: ";
    cin >> soBuoi;
    cout << "Nhap gia moi buoi: ";
    cin >> giaMoiBuoi;
    cin.ignore();
}

void Therapy::in() const {
    Treatment::in();
    cout << "So buoi tri lieu: " << soBuoi << endl;
    cout << "Gia moi buoi: " << giaMoiBuoi << endl;
}

void Therapy::tinhChiPhi() const {
    double tong = chiPhi + soBuoi * giaMoiBuoi;
    cout << "Tong chi phi tri lieu: " << tong << endl;
}

