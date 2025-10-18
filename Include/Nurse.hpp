#ifndef NURSE_HPP
#define NURSE_HPP

#include <Staff.hpp>
#include <vector>
using namespace std;

struct ShiftInfo {
    string day;      // Thứ (Monday, Tuesday,...)
    string shifts;    // Ca (morning, evening,...)
    string oncallRooms;     // Phòng trực
}

class Nurse : public Staff {
private:
	vector<ShiftInfo> schedule;

public:
	Nurse(); // mac dinh bang 0

	void nhap();
	void in() const;
	void display() const;

};

#endif
