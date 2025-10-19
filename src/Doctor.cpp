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
        string schedule;
        cout << "Schedule " << i + 1 << " (e.g. Mon: Morning): ";
        getline(cin, schedule);
        schedules.push_back(schedule);
    }
}

void Doctor::in() const {
    Staff::in();
    cout << left << setw(15) << specialization << endl;
}

void Doctor::display() const {
    cout << "\n===== DOCTOR SCHEDULE =====\n";
    cout << left
         << setw(10) << staffID
         << setw(20) << name
         << setw(20) << specialization
         << endl;

    if (schedules.empty()) {
        cout << "   No schedules available.\n";
    } else {
        cout << "   Schedules: ";
        for (int i = 0; i < schedules.size(); i++) {
            cout << schedules[i];
            if (i != schedules.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    cout << string(60, '-') << endl;
}




