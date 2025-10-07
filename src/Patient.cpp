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


