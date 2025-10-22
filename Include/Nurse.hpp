#ifndef NURSE_HPP
#define NURSE_HPP

#include <Staff.hpp>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

struct NurseSchedule {
    string day;      // Thứ (Monday, Tuesday,...)
    string shifts;    // Ca (morning, evening,...)
    string oncallRooms;     // Phòng trực
};

class Nurse : public Staff {
private:
	vector<NurseSchedule> schedule;

public:
	Nurse(); // mac dinh bang 0

	void nhap();
	void in() const;
	void display() const;

	json toJson() const;
    void fromJson(const json& j);
};

#endif
