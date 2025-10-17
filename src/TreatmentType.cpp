#include "TreatmentType.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Medication::Medication() {}

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
         << soLuong 
         << fixed << setprecision(2) << giaMoiDonVi
         << tinhChiPhi() << endl;
}

double Medication::tinhChiPhi() const {
    double total = baseCost + soLuong * giaMoiDonVi;
    return total;
}

Surgery::Surgery() : Treatment() {}

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
         << fixed << setprecision(2) << phiBacSi
         << fixed << setprecision(2) << chiPhiThietBi 
         << tinhChiPhi() << endl;
}

double Surgery::tinhChiPhi() const {
    double total = baseCost + phiBacSi + chiPhiThietBi;
    return total;
}

Therapy::Therapy() : Treatment() {}

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
         << soBuoi 
         << fixed << setprecision(2) << giaMoiBuoi 
         << tinhChiPhi() << endl;
}

double Therapy::tinhChiPhi() const {
    double total = baseCost + soBuoi * giaMoiBuoi;
    return total;
}


