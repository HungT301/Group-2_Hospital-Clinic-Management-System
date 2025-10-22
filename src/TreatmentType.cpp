#include "TreatmentType.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

//Medication
Medication::Medication() {
    treatmentType = "Medication";
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
    cout << left
         << setw(15) << fixed << setprecision(0) << soLuong 
         << setw(15) << fixed << setprecision(2) << giaMoiDonVi
         << setw(15) << fixed << setprecision(2) << tinhChiPhi() << endl;
}

double Medication::tinhChiPhi() const {
    double total = baseCost + soLuong * giaMoiDonVi;
    return total;
}

json Medication::toJson() const {
    json j = Treatment::toJson();
    j["quantity"] = soLuong;
    j["pricePerUnit"] = giaMoiDonVi;
    j["total"] = tinhChiPhi();
    return j;
}

void Medication::fromJson(const json& j) {
    Treatment::fromJson(j);
    soLuong = j.value("quantity", 0);
    giaMoiDonVi = j.value("pricePerUnit", 0.0);
}

//Surgery
Surgery::Surgery() {
    treatmentType = "Surgery";
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
    cout << left 
         << setw(15) << fixed << setprecision(2) << phiBacSi
         << setw(15) << fixed << setprecision(2) << chiPhiThietBi 
         << setw(15) << fixed << setprecision(2) << tinhChiPhi() << endl;
}

double Surgery::tinhChiPhi() const {
    double total = baseCost + phiBacSi + chiPhiThietBi;
    return total;
}

json Surgery::toJson() const {
    json j = Treatment::toJson();
    j["doctorFee"] = phiBacSi;
    j["equipmentCost"] = chiPhiThietBi;
    j["total"] = tinhChiPhi();
    return j;
}

void Surgery::fromJson(const json& j) {
    Treatment::fromJson(j);
    phiBacSi = j.value("doctorFee", 0.0);
    chiPhiThietBi = j.value("equipmentCost", 0.0);
}

//Therapy
Therapy::Therapy() {
    treatmentType = "Therapy";
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
    cout << left
         << setw(15) << fixed << setprecision(0) << soBuoi 
         << setw(20) << fixed << setprecision(2) << giaMoiBuoi 
         << setw(15) << fixed << setprecision(2) << tinhChiPhi() << endl;
}

double Therapy::tinhChiPhi() const {
    double total = baseCost + soBuoi * giaMoiBuoi;
    return total;
}

json Therapy::toJson() const {
    json j = Treatment::toJson();
    j["sessions"] = soBuoi;
    j["pricePerSession"] = giaMoiBuoi;
    j["total"] = tinhChiPhi();
    return j;
}

void Therapy::fromJson(const json& j) {
    Treatment::fromJson(j);
    soBuoi = j.value("sessions", 0);
    giaMoiBuoi = j.value("pricePerSession", 0.0);
}
