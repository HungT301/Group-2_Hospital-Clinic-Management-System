#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "Staff.hpp"
using namespace std;

class Doctor : public Staff {
private:
	string specialization;
	string schedule; // chi ghi cac thu lam viec (input : Thu 2, 3, 4, 5 - Sang)
public:
	Doctor();

	void nhap();
	void in() const;
};

#endif
