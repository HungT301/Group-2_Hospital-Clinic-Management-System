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
	Appointment(string, string, string, string);

	void nhap();
	void in() const;
};

#endif