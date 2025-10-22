#include "Doctor.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

Doctor::Doctor() {}

void Doctor::nhap() {
    Staff::nhap(); 

    cout << "Enter specialization: ";
    getline(cin, specialization);

    int numSchedules;
    cout << "Enter the number of schedules: ";
    cin >> numSchedules;
    cin.ignore();

    schedules.clear();

    for (int i = 0; i < numSchedules; i++) {
        DoctorSchedule s;
        cout << "\nSchedule " << i + 1 << ":\n";

        cout << "  Enter day: ";
        getline(cin, s.day);

        cout << "  Enter shift: ";
        getline(cin, s.shifts);

        cout << "  Enter consultation room: ";
        getline(cin, s.consultRoom);

        schedules.push_back(s);
    }
}

void Doctor::in() const {
    Staff::in(); 
    cout << left << setw(20) << specialization << endl;
}

void Doctor::display() const {
    for (const auto &s : schedules) {
        cout << left
             << setw(12) << s.day
             << setw(15) << s.shifts
             << setw(15) << s.consultRoom
             << endl;
    }
}

json Doctor::toJson() const {
    json jSchedules = json::array();
    for (const auto& s : schedules) {
        jSchedules.push_back({
            {"day", s.day},
            {"shift", s.shifts},
            {"consultRoom", s.consultRoom}
        });
    }

    return {
        {"id", staffID},        
        {"name", name},
        {"dob", DOB},
        {"gender", gender},
        {"phone", phone},
        {"specialization", specialization},
        {"schedules", jSchedules}
    };
}

void Doctor::fromJson(const json& j) {
    staffID       = j.value("id", "");
    name          = j.value("name", "");
    DOB           = j.value("dob", "");
    gender        = j.value("gender", "");
    phone         = j.value("phone", "");
    specialization = j.value("specialization", "");

    schedules.clear();
    if (j.contains("schedules")) {
        for (auto& s : j["schedules"]) {
            DoctorSchedule d;
            d.day = s.value("day", "");
            d.shifts = s.value("shift", "");
            d.consultRoom = s.value("consultRoom", "");
            schedules.push_back(d);
        }
    }
}