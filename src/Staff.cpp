#include "Staff.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

Staff::Staff() {}

void Staff::nhap() {
    cout << "Enter ID: ";
    getline(cin, staffID);
    Person::nhap();
}

void Staff::in() const {
    cout << left
         << setw(15) << staffID;
    Person::in();
}

string Staff::getstaffID() const {
    return staffID;
}


