#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "Person.hpp"
#include <string>
using namespace std;

class Patient : public Person {
private:
	string patientID;
	string symptom;
	string diagnose;

public:
	Patient();

	void nhap();
	void in() const;
	
	string getpatientID() const;
};

#endif
