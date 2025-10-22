#ifndef TREATMENTTYPE_HPP
#define TREATMENTTYPE_HPP

#include "Treatment.hpp"
using namespace std;

// ---------------- Medication ----------------
class Medication : public Treatment {
private:
    int soLuong;
    double giaMoiDonVi;

public:
    Medication();

    void nhap() override;
    void in() const override;
    double tinhChiPhi() const override;

    json toJson() const override;
    void fromJson(const json& j) override;
};

// ---------------- Surgery ----------------
class Surgery : public Treatment {
private:
    double phiBacSi;
    double chiPhiThietBi;

public:
    Surgery();

    void nhap() override;
    void in() const override;
    double tinhChiPhi() const override;

    json toJson() const override;
    void fromJson(const json& j) override;
};

// ---------------- Therapy ----------------
class Therapy : public Treatment {
private:
    int soBuoi;
    double giaMoiBuoi;

public:
    Therapy();

    void nhap() override;
    void in() const override;
    double tinhChiPhi() const override;

    json toJson() const override;
    void fromJson(const json& j) override;
};

#endif