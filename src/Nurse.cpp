#include "Nurse.hpp"

#include <iostream>
#include <iomanip>
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

  string allShifts;
  for (int i = 0; i < shifts.size(); i++) {
    allShifts += shifts[i];
    if (i != shifts.size() - 1) allShifts += ", ";
  }

  string allRooms;
  for (int i = 0; i < onCallRooms.size(); i++) {
    allRooms += "[";
    for (int j = 0; j < onCallRooms[i].size(); j++) {
      allRooms += onCallRooms[i][j];
      if (j != onCallRooms[i].size() - 1) allRooms += ", ";
    }
      allRooms += "]";
      if (i != onCallRooms.size() - 1) allRooms += " ";
    }

    cout << left
         << setw(25) << allShifts
         << setw(50) << allRooms << endl;
}






