#include "TreatmentType.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

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
         << setw(10) << soLuong 
         << setw(15) << fixed << setprecision(2) << giaMoiDonVi
         << setw(15) << tinhChiPhi() << endl;
}

double Medication::tinhChiPhi() const {
    double total = baseCost + soLuong * giaMoiDonVi;
    return total;
}

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
         << setw(15) << tinhChiPhi() << endl;
}

double Surgery::tinhChiPhi() const {
    double total = baseCost + phiBacSi + chiPhiThietBi;
    return total;
}

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
         << setw(10) << soBuoi 
         << setw(15) << fixed << setprecision(2) << giaMoiBuoi 
         << setw(15) << tinhChiPhi() << endl;
}

double Therapy::tinhChiPhi() const {
    double total = baseCost + soBuoi * giaMoiBuoi;
    return total;
}


