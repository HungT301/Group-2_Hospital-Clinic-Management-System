#include "Nurse.hpp"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

Nurse :: Nurse(){
 // cái này constructor t chưa biết sửa như nào m sửa cho t  nhá!!!
}

void Nurse :: nhap(){
  Staff::nhap();

  int numShifts;
    cout << "Nhap so luong ca lam: ";
    cin >> numShifts;
    cin.ignore(); 

    for (int i = 0; i < numShifts; i++) {
        string shift;
        cout << "  Nhap ca lam thu " << i + 1 << ": ";
        getline(cin, shift);
        shifts.push_back(shift);
    }

    int numRooms;
    cout << "Nhap so luong phong truc: ";
    cin >> numRooms;
    cin.ignore();

    for (int i = 0; i < numRooms; i++) {
        string room;
        cout << "  Nhap phong truc thu " << i + 1 << ": ";
        getline(cin, room);
        onCallRooms.push_back(room);
    }
}

void Nurse :: in() const {
  Staff :: in();
  cout << "Cac ca lam:\n";
  for (const string& s : shifts){
    cout << "  - " << s << endl;
  };
  
  cout << "Phong truc:\n";
  for (const string& r : onCallRooms){
        cout << "  - " << r << endl;
  }
}




