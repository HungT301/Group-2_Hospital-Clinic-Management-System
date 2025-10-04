#include "Doctor.hpp"
#include <iostream>
#include <string>
using namespace std;

Doctor::Doctor() : Staff() {
    chuyenKhoa = "";
    namKinhNghiem = 0;
    bangCap = "";
}

Doctor::Doctor(string id, string name, string DOB, string gender, 
               int phone, double salary, string chuyenKhoa, int namKinhNghiem, string bangCap) 
               : Staff(id, name, DOB, gender, phone) 
{
    this->chuyenKhoa = chuyenKhoa;
    this->namKinhNghiem = namKinhNghiem;
    this->bangCap = bangCap;
}

void Doctor::nhap() {
    Staff::nhap();

    cin.ignore();
    cout << "Nhap chuyen khoa: ";
    getline(cin, chuyenKhoa);
    cout << "Nhap so nam kinh nghiem: ";
    cin >> namKinhNghiem;
    cin.ignore();
    cout << "Nhap bang cap: ";
    getline(cin, bangCap);
}

void Doctor::in() const {
    Staff::in();

    cout << "Chuyen khoa: " << chuyenKhoa << endl;
    cout << "Nam kinh nghiem: " << namKinhNghiem << endl;
    cout << "Bang cap: " << bangCap << endl;
    cout << "Luong: " << tinhLuong() << endl;
}

double Doctor::tinhLuong() const {
    double luongCoBan = 8000000; 
    return luongCoBan + namKinhNghiem * 200000 + bangCap * 500000;
}

