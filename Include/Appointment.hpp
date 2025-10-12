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
	string appointmentType;

public:	
	Appointment();

	virtual void nhap();
	virtual void in() const;
	void sumary() const;

	string getType() const;
	string getID() const;

	virtual ~Appointment() {}
};

#endif