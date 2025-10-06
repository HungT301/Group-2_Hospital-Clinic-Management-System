#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "Staff.hpp"
using namespace std;

class Doctor : public Staff {
private:
	string chuyenKhoa;
	int namKinhNghiem;
	string bangCap;

public:
	Doctor();
	Doctor(string, string, string, string, int, double, string , int, string);

	void nhap();
	void in() const;
	double tinhLuong() const;
};

#endif