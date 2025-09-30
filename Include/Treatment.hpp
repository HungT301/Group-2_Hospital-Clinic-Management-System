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
	double chiPhi;

public:
	Treatment();
	Treatment(string, string, string, string, double);

	virtual void nhap();
	virtual void in() const;

	virtual void tinhChiPhi() const;
};

#endif