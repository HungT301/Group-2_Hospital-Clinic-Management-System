#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
using namespace std;

class Patient {
private:
	string id;
	string ten;
	string ngaysinh;
	string sdt;
	string gioiTinh;
	string trieuTrung;
	string chanDoan;

public:
	Patient();
	Patient(string, string, string, string, string, string, string);

	void nhap();
	void in() const;
	
	string getID() const;
};

#endif