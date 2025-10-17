#ifndef NURSE_HPP
#define NURSE_HPP

#include <Staff.hpp>
#include <vector>
using namespace std;

class Nurse : public Staff {
private:
	vector<vector<string>> onCallRooms; // phòng trực
	vector<string> shifts; // ca trực


public:
	Nurse(); // mac dinh bang 0

	void nhap();
	void in() const;

};

#endif
