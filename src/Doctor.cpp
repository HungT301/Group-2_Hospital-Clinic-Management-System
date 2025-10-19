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
        SCHEDULES s;
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

