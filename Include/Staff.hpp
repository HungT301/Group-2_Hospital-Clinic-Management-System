#ifndef STAFF_HPP
#define STAFF_HPP

#include "Person.hpp"
#include <string>
using namespace std;

class Staff : public Person {
protected:
	string staffID;
public:
	Staff(); //mac dinh cac tham so =0

	void nhap();
	void in() const;

	string getstaffID() const; // lay ID de tim kiem
};

#endif
