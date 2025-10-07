#include "Nurse.hpp"

#include <iostream>
#include <string>
using namespace std;

Nurse :: Nurse(){
  id = ""; name = ""; DOB =""; gender = "";
  phone=0;
  shift = ""; oncallroom = "";
}

void Nurse :: nhap(){
  Staff::nhap();
  cout << "enter the shift:";
  cin.ignore();
  cin >> shift;
  cout << "enter the on-call room:"; cin >> oncallroom;
}

void Nurse :: in() const {
  Staff :: in();
  cout << shift << " " << oncallroom << "\n";
}




