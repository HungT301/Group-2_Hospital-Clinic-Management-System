#ifndef TREATMENT_HPP
#define TREATMENT_HPP

#include <string>
using namespace std;

class Treatment {
protected:
	string id;
	string patientId;
	string doctorId;
	string moTa;
	double baseCost;

public:
	Treatment();

	virtual void nhap();
	virtual void in() const;
	virtual double tinhChiPhi() const;

	string getID() const;

	virtual ~Treatment() {}
};

#endif
