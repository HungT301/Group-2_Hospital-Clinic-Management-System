#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "Staff.hpp"
#include <vector>
using namespace std;

class Doctor : public Staff {
private:
	string specialization;
	vector<string> schedules; // chi ghi cac thu lam viec (input : Thu 2 - Sang)

public:
	Doctor();

	void nhap();
	void in() const;
	void display() const;
};

#endif
