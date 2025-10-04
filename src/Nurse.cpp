#include "Nurse.hpp"

#include <iotream>
#include <string>
using namespace std;

Nurse :: Nurse(){
  id = ""; name = ""; DOB =""; gender = "";
  phone=0;
  caTruc = ""; phongTruc "";
}

Nurse :: void nhap(){
  Staff::nhap();
  cout << "enter the on-call:";
  cin.ignore();
  cin >> caTruc;
  cout << "enter thr duty room:"; cin >> phongTruc;
}

Nurse :: void in() const {
  Staff :: in();
  cout << caTruc << " " << phongTruc << "\n";
}

