#ifndef NURSE_HPP
#define NURSE_HPP

#include <Staff.hpp>
#include <string>
using namespace std;

class Nurse : public Staff {
private:
	string caTruc;
	string phongTruc;

public:
	Nurse(); // mac dinh bang 0

	void nhap();
	void in() const;

};

#endif
