#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "Person.hpp"
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
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
	
	string getPatientID() const;

	json toJson() const;
    void fromJson(const json& j);
};

#endif
