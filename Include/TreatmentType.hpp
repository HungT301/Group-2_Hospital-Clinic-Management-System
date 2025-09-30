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

    void nhap() override;
    void in() const override;
    void tinhChiPhi() const override;
};

// ---------------- Surgery ----------------
class Surgery : public Treatment {
private:
    double phiBacSi;
    double chiPhiThietBi;

public:
    Surgery();
    Surgery(string, string, string, string, double, double, double);

    void nhap() override;
    void in() const override;
    void tinhChiPhi() const override;
};

// ---------------- Therapy ----------------
class Therapy : public Treatment {
private:
    int soBuoi;
    double giaMoiBuoi;

public:
    Therapy();
    Therapy(string, string, string, string, double, int, double);

    void nhap() override;
    void in() const override;
    void tinhChiPhi() const override;
};

#endif