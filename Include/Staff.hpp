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
	void in() const; // in cac thong tin co ban
	virtual void display() const; // in schedule cua nurse va doctor

	string getstaffID() const; // lay ID de tim kiem
};

#endif
