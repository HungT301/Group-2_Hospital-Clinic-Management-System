#include "Person.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

Person::Person() {}

void Person::nhap() {
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter date of birth: ";
	getline(cin, DOB);
	cout << "Enter gender: ";
	getline(cin, gender);
	cout << "Enter phone: ";
	getline(cin, phone);
}

void Person::in() const {
	cout << left
		 << setw(15) << name
		 << setw(15) << DOB
		 << setw(15) << gender
		 << setw(15) << phone;
}
