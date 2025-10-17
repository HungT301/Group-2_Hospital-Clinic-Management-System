#include "Nurse.hpp"

#include <iostream>
using namespace std;

Nurse :: Nurse(){}

void Nurse :: nhap(){
  Staff::nhap();

  int numShifts;
    cout << " the number of Shifts: ";
    cin >> numShifts;
    cin.ignore();
  
  for (int i = 0; i < numShifts; i++) {
    string shift;
    cout << "Shift" << i + 1 << ": ";
    getline(cin, shift);
    shifts.push_back(shift);

    int numRooms;
    cout << " the number of Oncall Rooms: ";
    cin >> numRooms;
    cin.ignore();

    vector<string> rooms;
    for (int j = 0; j < numRooms; j++) {
        string room;
        cout << "   " << j + 1 << ": ";
        getline(cin, room);
        rooms.push_back(room);
      }
    onCallRooms.push_back(rooms);
  }
}

void Nurse :: in() const {
  Staff :: in();
  cout << endl;
  cout << "-----Schedule-----\n";
  for (int i = 0; i < shifts.size(); i++) {
    cout << "Shift: " << shifts[i] << endl;
    cout << "Oncall Room: ";
    for (const string& r : onCallRooms[i])
        cout << r << " ";
    cout << endl;
  }

}





