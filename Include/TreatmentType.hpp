#ifndef TREATMENTTYPE_HPP
#define TREATMENTTYPE_HPP

#include<Treatment.hpp>
using namespace std;

// ---------------- Medication ----------------
class Medication : public Treatment {
private:
    int soLuong;
    double giaMoiDonVi;

public:
    Medication();
    Medication(string, string, string, string, double, int, double);

    void nhap();
    void in() const;
    void tinhChiPhi() const;
};

// ---------------- Surgery ----------------
class Surgery : public Treatment {
private:
    double phiBacSi;
    double chiPhiThietBi;

public:
    Surgery();
    Surgery(string, string, string, string, double, double, double);

    void nhap();
    void in() const;
    void tinhChiPhi() const;
};

// ---------------- Therapy ----------------
class Therapy : public Treatment {
private:
    int soBuoi;
    double giaMoiBuoi;

public:
    Therapy();
    Therapy(string, string, string, string, double, int, double);

    void nhap();
    void in() const;
    void tinhChiPhi() const;
};

#endif