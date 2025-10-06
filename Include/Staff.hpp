#ifndef STAFF_HPP
#define STAFF_HPP

#include <string>
using namespace std;

class Staff {
protected:
	string id;
	string name;
	string DOB;
	string gender;
	int phone;

public:
	Staff(); //mac dinh cac tham so =0

	void nhap();
	void in() const;

	string getID() const; // lay ID de tim kiem
};

#endif
