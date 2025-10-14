#include <iostream>
#include <iomanip>
#include "Person.hpp"
#include "Staff.hpp"
#include "Doctor.hpp"
#include "Nurse.hpp"
#include "Patient.hpp"
#include "Appointment.hpp"
#include "AppointmentType.hpp"
#include "Treatment.hpp"
#include "TreatmentType.hpp"
using namespace std;

// Menu function
void menuDoctor(vector<Doctor>& doctors);
void menuNurse(vector<Nurse>& nurses);
void menuPatient(vector<Patient>& patients);
void menuAppointment(vector<Appointment*>& appointments);
void menuTreatment(vector<Treatment*>& treatments);

// Main
int main() {

    vector<Doctor> doctors;
    vector<Nurse> nurses;
    vector<Patient> patients;
    vector<Appointment*> appointments;
    vector<Treatment*> treatments;

    int choice;
    do {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Manage Doctor\n";
        cout << "2. Manage Nurse\n";
        cout << "3. Manage Patient\n";
        cout << "4. Manage Appointment\n";
        cout << "5. Manage Treatment\n";
        cout << "0. Exit.\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: menuDoctor(doctors); break;
            case 2: menuNurse(nurses); break;
            case 3: menuPatient(patients); break;
            case 4: menuAppointment(appointments); break;
            case 5: menuTreatment(treatments); break;
            case 0: cout << "Exit program.\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    for (auto p : appointments) delete p;
    for (auto t : treatments) delete t;

    return 0;
}

// Menu function deploy

// Doctor
void menuDoctor(vector<Doctor>& doctors) {}

// Nurse
void menuNurse(vector<Nurse>& nurses) {}

// Patient
void menuPatient(vector<Patient>& patient) {}

// Appointment
void menuAppointment(vector<Appointment*>& appointments) {
    int choice;

    do {
        cout << "\n===== APPOINTMENT MENU =====\n";
        cout << "1. Appointment list\n";
        cout << "2. Appointment type list\n";
        cout << "3. Add checkup appointment\n";
        cout << "4. Add surgery appointment\n";
        cout << "5. Add therapy appointment\n";
        cout << "6. Searching appointment\n";
        cout << "7. Remove appointment\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\n===== APPOINTMENT LIST =====\n";
            cout << left
                 << setw(10) << "Type"
                 << setw(10) << "ID"
                 << setw(10) << "Patient"
                 << setw(10) << "Doctor"
                 << setw(10) << "Time" << endl;
            cout << string(50, '-') << endl;

            for (auto &a : appointments) a->sumary();
        
        } else if (choice == 2) {
            cout << "\n===== CHECKUP APPOINTMENT LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(10) << "Patient"
                 << setw(10) << "Doctor"
                 << setw(10) << "Time"
                 << setw(10) << "room"
                 << setw(10) << "purpose" << endl;
            cout << string(60, '-') << endl;

            for (auto &a : appointments) {
                if (a->getType() == "Checkup") a->in();
            }

            cout << "\n===== SURGERY APPOINTMENT LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(10) << "Patient"
                 << setw(10) << "Doctor"
                 << setw(10) << "Time"
                 << setw(10) << "Type"
                 << setw(10) << "Room"
                 << setw(18) << "Surgeon" << endl;
            cout << string(78, '-') << endl;

            for (auto &a : appointments) {
                if (a->getType() == "Surgery") a->in();
            }

            cout << "\n===== THERAPY APPOINTMENT LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(10) << "Patient"
                 << setw(10) << "Doctor"
                 << setw(10) << "Time"
                 << setw(10) << "Type"
                 << setw(10) << "Session"
                 << setw(18) << "Therapist" << endl;
            cout << string(78, '-') << endl;

            for (auto &a : appointments) {
                if (a->getType() == "Therapy") a->in();
            }
        
        } else if (choice == 3) {
            Appointment* c = new CheckupAppointment();
            c->nhap();
            appointments.push_back(c);
            cout << "Adding appointment successfully!\n";
        
        } else if (choice == 4) {
            Appointment* s = new SurgeryAppointment();
            s->nhap();
            appointments.push_back(s);
            cout << "Adding appointment successfully!\n";
        
        } else if (choice == 5) {
            Appointment* t = new TherapyAppointment();
            t->nhap();
            appointments.push_back(t);
            cout << "Adding appointment successfully!\n";
        
        } else if (choice == 6) {
            bool found = false;
            string SearchID;
            cout << "Enter appointment ID to search: ";
            getline(cin, SearchID);

            for (auto &a : appointments) {
                if (a->getID() == SearchID) {
                    cout << left
                         << setw(10) << "Type"
                         << setw(10) << "ID"
                         << setw(10) << "Patient"
                         << setw(10) << "Doctor"
                         << setw(10) << "Time" << endl;
                    cout << string(50, '-') << endl;
                    a->sumary();
                    found = true;
                    break;
                }    
            }
            if (!found) cout << "Invalid appointment ID!\n";

        } else if (choice == 7) {
            string delID;
            cout << "Enter appointment ID to remove: ";
            getline(cin, delID);

            bool removed = false;
            for (auto it = appointments.begin(); it != appointments.end(); it++) {
                if ((*it)->getID() == delID) {
                    delete *it;
                    it = appointments.erase(it);
                    removed = true;
                    cout << "Appointment removed successfully!\n";
                    break;
                }
            }
            if (!removed) cout << "Invalid appointment ID!\n";
        }

    } while (choice != 0);
}

//Treatment
void menuTreatment(vector<Treatment*>& treatments) {}
