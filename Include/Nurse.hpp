#ifndef NURSE_HPP
#define NURSE_HPP

#include <Staff.hpp>
using namespace std;

class Nurse : public Staff {
private:
	string caTruc;
	string phongTruc;

public:
	Nurse();
	Nurse(string, string, string, string, int, double, string, string);

	void nhap() override;
	void in() const override;
	double tinhLuong() const override;
};

#endif