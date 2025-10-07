#include "Person.hpp"

#include <iostream>
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
	cout << name << " " << DOB << " " << gender << " " << phone;
}