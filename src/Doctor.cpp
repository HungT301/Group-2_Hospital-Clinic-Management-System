#include "Doctor.hpp"
#include <iostream>
#include <string>
using namespace std;

Doctor::Doctor() {
    id = name = DOB = gender = "";
    phone = 0;
    chuyenKhoa = ""; 
    namKinhNghiem = 0;
    bangCap = 0;
}

Doctor::Doctor(string id, string name, string DOB, string gender, int phone, string chuyenKhoa, int namKinhNghiem, int bangCap) {
    this->id = id;
    this->name = name;
    this->DOB = DOB;
    this->gender = gender;
    this->phone = phone;
    this->chuyenKhoa = chuyenKhoa;
    this->namKinhNghiem = namKinhNghiem;
    this->bangCap = bangCap;
}

void Doctor::nhap() {
    Staff::nhap();
    cout << "enter specialization: ";
    cin.ignore();
    getline(cin, chuyenKhoa);
    cout << "enter years of experience: ";
    cin >> namKinhNghiem;
    cout << "enter number of degrees: ";
    cin >> bangCap;
}

void Doctor::in() const {
    Staff::in();
    cout << chuyenKhoa << " " << namKinhNghiem << " " << bangCap << "\n";
}

double Doctor::tinhLuong() const {
    double luongCoBan = 8000000;
    return luongCoBan + namKinhNghiem * 200000 + bangCap * 500000;
}


