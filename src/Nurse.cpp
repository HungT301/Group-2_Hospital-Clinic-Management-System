#include "Nurse.hpp"

#include <iostream>
#include <string>
using namespace std;

Nurse :: Nurse(){
  id = ""; name = ""; DOB =""; gender = "";
  phone=0;
  caTruc = ""; phongTruc "";
}

void Nurse :: nhap(){
  Staff::nhap();
  cout << "enter the on-call:";
  cin.ignore();
  cin >> caTruc;
  cout << "enter thr duty room:"; cin >> phongTruc;
}

void Nurse :: in() const {
  Staff :: in();
  cout << caTruc << " " << phongTruc << "\n";
}


