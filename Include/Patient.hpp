#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
using namespace std;

class Patient {
private:
	string id;
	string name;
	string DOB;
	string Phone;
	string gender;
	string symptom;
	string diagnose;

public:
	Patient();

	void nhap();
	void in() const;
	
	string getID() const;
};

#endif
