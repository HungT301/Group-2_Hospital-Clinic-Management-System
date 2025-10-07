#include "Patient.hpp"

#include <iostream>
#include <string>
#include <limits>
using namespace std;

Patient::Patient() {}

void Patient::nhap() {
    Person::nhap();
    cout << "Enter symptoms: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, symptoms);

    cout << "Enter diagnosis: ";
    getline(cin, diagnosis);
}

void Patient::in() const {
    Person::in();
    cout << " " << symptoms << " " << diagnosis;
}


