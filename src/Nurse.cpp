#include "Nurse.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

Nurse :: Nurse(){}

void Nurse :: nhap(){
  Staff::nhap();

  int numShifts;
    cout << "Enter the number of Shifts: ";
    cin >> numShifts;
    cin.ignore();

  schedule.clear(); 
  
  for (int i = 0; i < numShifts; i++) {
    SCHEDULES s;
        cout << "\nShift " << i + 1 << ":\n";

        cout << "  Enter day: ";
        getline(cin, s.day);
    
        cout << "  Enter shift : ";
        getline(cin, s.shifts);
    
        cout << "  Enter on-call room: ";
        getline(cin, s.oncallRooms);

    schedule.push_back(s);
   }
}
    
void Nurse :: in() const {
   Staff :: in()
}

void Nurse :: display() const {
    for (const auto &s : schedule) {
        cout << left
             << setw(12) << s.day
             << setw(15) << s.shifts
             << setw(15) << s.oncallRooms
             << endl;
    }

    cout << string(42, '-') << endl;
}











