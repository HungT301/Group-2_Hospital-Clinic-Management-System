#ifndef STAFF_HPP
#define STAFF_HPP

#include <string>
using namespace std:

class Staff {
protected:
	string id;
	string ten;
	string ngaySinh;
	string gioiTinh;
	int sdt;
	double luong;

public:
	Staff();
	Staff(string, string, string, string, int, double);

	void nhap();
	void in() const;
	double tinhLuong() const = 0;

	string getID() const;
};

#endif