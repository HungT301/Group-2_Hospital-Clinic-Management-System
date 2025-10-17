#include "Doctor.hpp"

#include <iostream>
#include <iomanip> 
using namespace std;

Doctor::Doctor() {}

void Doctor::nhap() {
    Staff::nhap();
    cout << "Enter specialization: ";
    getline(cin, specialization);

    int n;
    cout << "Enter number of working shifts: ";
    cin >> n;
    cin.ignore();

    schedules.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter schedule " << i + 1 << " (e.g. Thu 2 - Sang): ";
        getline(cin, schedules[i]);
    }
}

void Doctor::in() const {
    Staff::in();

    string allSchedules;
    for (int i = 0; i < schedules.size(); i++) {
        allSchedules += schedules[i];
        if (i != schedules.size() - 1) allSchedules += ", ";
    }

     cout << left
         << setw(18) << specialization
         << setw(40) << allSchedules << endl;
}
