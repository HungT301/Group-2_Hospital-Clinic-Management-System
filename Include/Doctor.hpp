#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "Staff.hpp"
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

struct DoctorSchedule {
    string day;     
    string shifts;    
    string consultRoom;  
};

class Doctor : public Staff {
private:
	string specialization;
	vector<DoctorSchedule> schedules; // chi ghi cac thu lam viec (input : Thu 2 - Sang)

public:
	Doctor();

	void nhap();
	void in() const;
	void display() const;

	json toJson() const;
    void fromJson(const json& j);
};

#endif
