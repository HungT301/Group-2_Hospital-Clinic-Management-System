#include "Nurse.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

Nurse :: Nurse(){}

void Nurse :: nhap(){
  Staff::nhap();

  int numShifts;
    cout << "Enter the number of Shifts: ";
    cin >> numShifts;
    cin.ignore();

  schedule.clear(); 
  
  for (int i = 0; i < numShifts; i++) {
    NurseSchedule s;
        cout << "\nShift " << i + 1 << ":\n";

        cout << "  Enter day: ";
        getline(cin, s.day);
    
        cout << "  Enter shift : ";
        getline(cin, s.shifts);
    
        cout << "  Enter on-call room: ";
        getline(cin, s.oncallRooms);

    schedule.push_back(s);
   }
}
    
void Nurse :: in() const {
   Staff :: in();
   cout << endl;
}

void Nurse :: display() const {
    for (const auto &s : schedule) {
        cout << left
             << setw(12) << s.day
             << setw(15) << s.shifts
             << setw(15) << s.oncallRooms
             << endl;
    }
}

json Nurse::toJson() const {
    json jSchedule = json::array();
    for (const auto& s : schedule) {
        jSchedule.push_back({
            {"day", s.day},
            {"shift", s.shifts},
            {"oncallRoom", s.oncallRooms}
        });
    }

    return {
        {"id", staffID},      
        {"name", name},
        {"dob", DOB},
        {"gender", gender},
        {"phone", phone},
        {"schedule", jSchedule}
    };
}

void Nurse::fromJson(const json& j) {
    staffID   = j.value("id", "");
    name      = j.value("name", "");
    DOB       = j.value("dob", "");
    gender    = j.value("gender", "");
    phone     = j.value("phone", "");

    schedule.clear();
    if (j.contains("schedule")) {
        for (auto& s : j["schedule"]) {
            NurseSchedule n;
            n.day = s.value("day", "");
            n.shifts = s.value("shift", "");
            n.oncallRooms = s.value("oncallRoom", "");
            schedule.push_back(n);
        }
    }
}
