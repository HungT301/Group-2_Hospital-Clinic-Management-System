#include "Staff.hpp"

#include <iostream>
using namespace std;

Staff::Staff() {}

void Staff::nhap() {
    cout << "Enter ID: ";
    getline(cin, staffID);
    Person::nhap();
}

void Staff::in() const {
    cout << "ID: " << staffID << endl;
    Person::in();
}

string Staff::getID() const {
  return staffID;
}

