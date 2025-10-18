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
  
  for (int i = 0; i < numShifts; i++) {
    schedule s;
        cout << "\nShift " << i + 1 << ":\n";

        cout << "  Enter day: ";
        getline(cin, s.day);
        cout << "  Enter shift : ";
        getline(cin, s.shifts);
        cout << "  Enter on-call room: ";
        getline(cin, s.oncallRooms);

    schedule.push_back(s);
 }
    
void Nurse :: in() const {
    cout << left
       << setw(15) << "ID"
       << setw(15) << "Name"
       << setw(15) << "DOB"
       << setw(15) << "Gender"
       << setw(15) << "Phone" << endl;
    cout << string(70, '-') << endl;
  
    Staff :: in();
    cout << string(70, '-') << endl;
}

void Nurse :: display() const {
    cout << "\n===== NURSE SCHEDULE =====\n";
    cout << left
         << setw(12) << "Day"
         << setw(15) << "Shift"
         << setw(15) << "Oncall Room" << endl;
    cout << string(42, '-') << endl;

    for (const auto &s : schedule) {
        cout << left
             << setw(12) << s.day
             << setw(15) << s.shifts
             << setw(15) << s.oncallRooms
             << endl;
    }

    cout << string(42, '-') << endl;
}







