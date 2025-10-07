#include "Doctor.hpp"

#include <iostream>
#include <string>
using namespace std;

Doctor::Doctor() {}

void Doctor::nhap() {
    Staff::nhap();
    cout << "Enter specialization: ";
    getline(cin, specialization);
}

void Doctor::in() const {
    Staff::in();
    cout << "Specialization: " << specialization << endl;
}


