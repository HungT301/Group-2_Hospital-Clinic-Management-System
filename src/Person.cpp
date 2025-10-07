#include "Person.hpp"

#include <iostream>
using namespace std;

Person::Person() {}

Person::nhap() {
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter date of birth: ";
	getline(cin, DOB);
	cout << "Enter gender: ";
	getline(cin, gender);
	cout << "Enter phone: ";
	getline(cin, phone);
}

Person::in() {
	cout << name << " " << DOB << " " << gender << " " << phone;
}