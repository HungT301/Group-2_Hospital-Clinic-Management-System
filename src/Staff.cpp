#include "Staff.hpp"

#include <iostream>
using namespace std;

Staff :: void nhap(){
  cout << "enter the ID:"; cin >> id;
  cout << "enter the name:"; 
  cin.ignore();
  getline(cin, name);
  cout << "enter Date Of Birth:"; cin >> DOB;
  cout << "enter the Gender:"; cin >> gender;
  cout << "enter the phone number:"; cin >> phone;
}

Staff : void in() const{
  cout << id << " " << name << " " << DOB << " " << gender << " " << phone << "\n";
}

Staff : string getID() const{
  return this->id;
}
