#ifndef TREATMENT_HPP
#define TREATMENT_HPP

#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

class Treatment {
protected:
	string id;
	string patientId;
	string doctorId;
	string moTa;
	double baseCost;
	string treatmentType;

public:
	Treatment();

	virtual void nhap();
	virtual void in() const;
	virtual double tinhChiPhi() const;
	void sumary() const;

	string getType() const;
	string getID() const;

	virtual ~Treatment() {}

	virtual json toJson() const;    
    virtual void fromJson(const json& j); 
};

#endif
