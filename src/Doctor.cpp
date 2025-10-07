#include "Doctor.hpp"

#include <iostream>
#include <limits> 
using namespace std;

Doctor::Doctor() {}

void Doctor::nhap() {
    Staff::nhap();
    cout << "Enter specialization: ";
    getline(cin, specialization);

    int n;
    cout << "Enter number of working shifts: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    schedules.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter schedule " << i + 1 << " (e.g. Thu 2 - Sang): ";
        getline(cin, schedules[i]);
    }
}

void Doctor::in() const {
    Staff::in();
    cout << specialization << endl;
    for (const auto &s : schedules) {
        cout << s << " ";
    }
    cout << endl;
}



