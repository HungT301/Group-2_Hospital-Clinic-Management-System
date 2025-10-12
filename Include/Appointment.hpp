#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include <string>
using namespace std;

class Appointment {
protected:
	string id;
	string patientId;
	string doctorId;
	string thoiGian;

public:	
	Appointment();

	virtual void nhap();
	virtual void in() const;

	string getID() const;

	virtual ~Appointment() {}
};

#endif