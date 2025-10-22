#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
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

	virtual json toJson() const;
    virtual void fromJson(const json& j);
};

#endif