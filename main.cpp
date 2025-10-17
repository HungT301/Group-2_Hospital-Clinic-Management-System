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
void menuDoctor(vector<Doctor*>& doctors);
void menuNurse(vector<Nurse*>& nurses);
void menuPatient(vector<Patient*>& patients);
void menuAppointment(vector<Appointment*>& appointments);
void menuTreatment(vector<Treatment*>& treatments);

// Main
int main() {

    vector<Doctor*> doctors;
    vector<Nurse*> nurses;
    vector<Patient*> patients;
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
void menuDoctor(vector<Doctor>& doctors) {
    int choice;

    do {
        cout << "\n===== DOCTOR MANAGEMENT MENU =====\n";
        cout << "1. Doctor list\n";
        cout << "2. Add new doctor\n";
        cout << "3. Search doctor by ID\n";
        cout << "4. Remove doctor\n";
        cout << "5. Update doctor information\n";
        cout << "6. Show schedule list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            cout << "\n===== DOCTOR LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(15) << "Specialty"
                 << setw(15) << "Phone"
                 << setw(15) << "Email" << endl;
            cout << string(75, '-') << endl;

            for (auto &d : doctors) d.in();

        } else if (choice == 2) {
            Doctor d;
            d.nhap();
            doctors.push_back(d);
            cout << "Doctor added successfully!\n";

        } else if (choice == 3) {
            bool found = false;
            string searchID;
            cout << "Enter Doctor ID to search: ";
            getline(cin, searchID);

            for (auto &d : doctors) {
                if (d.getID() == searchID) {
                    cout << "\n===== DOCTOR FOUND =====\n";
                    cout << left
                         << setw(10) << "ID"
                         << setw(20) << "Name"
                         << setw(15) << "Specialty"
                         << setw(15) << "Phone"
                         << setw(15) << "Email" << endl;
                    cout << string(75, '-') << endl;
                    d.in();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Doctor ID not found!\n";

        } else if (choice == 4) {
            bool removed = false;
            string delID;
            cout << "Enter Doctor ID to remove: ";
            getline(cin, delID);

            for (auto it = doctors.begin(); it != doctors.end(); ++it) {
                if (it->getID() == delID) {
                    doctors.erase(it);
                    removed = true;
                    cout << "Doctor removed successfully!\n";
                    break;
                }
            }
            if (!removed) cout << "Invalid Doctor ID!\n";

        } else if (choice == 5) {
            bool updated = false;
            string updateID;
            cout << "Enter Doctor ID to update: ";
            getline(cin, updateID);

            for (auto &d : doctors) {
                if (d.getID() == updateID) {
                    cout << "Enter new information for this doctor:\n";
                    d.nhap();
                    cout << "Doctor updated successfully!\n";
                    updated = true;
                    break;
                }
            }
            if (!updated) cout << "Invalid Doctor ID!\n";

        } else if (choice == 6) {
            cout << "\n===== DOCTOR SCHEDULE LIST =====\n";
            for (auto &d : doctors) {
                d.in();
                cout << string(50, '-') << endl;
            }
        }

    } while (choice != 0);
}

// Nurse
void menuNurse(vector<Nurse*>& nurses) {
    int choice;

    do {
        cout << "\n===== NURSE MANAGEMENT MENU =====\n";
        cout << "1. Nurse list\n";
        cout << "2. Add new nurse\n";
        cout << "3. Search nurse by ID\n";
        cout << "4. Remove nurse\n";
        cout << "5. Update nurse information\n";
        cout << "6. Show shifts & on-call rooms\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();


        if (choice == 1) {
            cout << "\n===== NURSE LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(15) << "DOB"
                 << setw(15) << "Gender"
                 << setw(15) << "Phone" << endl;
            cout << string(75, '-') << endl;

            for (auto &n : nurses) n->in();

        } else if (choice == 2) {
            Nurse n;
            n->nhap();
            nurses.push_back(n);
            cout << "Nurse added successfully!\n";

        } else if (choice == 3) {
            bool found = false;
            string searchID;
            cout << "Enter Nurse ID to search: ";
            getline(cin, searchID);

            for (auto &n : nurses) {
                if (n->getstaffID() == searchID) {
                    cout << "\n===== NURSE FOUND =====\n";
                    cout << left
                         << setw(10) << "ID"
                         << setw(20) << "Name"
                         << setw(15) << "DOB"
                         << setw(15) << "Gender"
                         << setw(15) << "Phone" << endl;
                    cout << string(75, '-') << endl;
                    n->in();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Nurse ID not found!\n";

        } else if (choice == 4) {
            bool removed = false;
            string delID;
            cout << "Enter Nurse ID to remove: ";
            getline(cin, delID);

            for (auto it = nurses.begin(); it != nurses.end(); ++it) {
                if (it->getstaffID() == delID) {
                    nurses.erase(it);
                    removed = true;
                    cout << "Nurse removed successfully!\n";
                    break;
                }
            }
            if (!removed) cout << "Invalid Nurse ID!\n";

        } else if (choice == 5) {
            bool updated = false;
            string updateID;
            cout << "Enter Nurse ID to update: ";
            getline(cin, updateID);

            for (auto &n : nurses) {
                if (n->getstaffID() == updateID) {
                    cout << "Enter new information for this nurse:\n";
                    n->nhap();
                    cout << "Nurse updated successfully!\n";
                    updated = true;
                    break;
                }
            }
            if (!updated) cout << "Invalid Nurse ID!\n";

        } else if (choice == 6) {
            cout << "\n===== NURSE SHIFTS & ON-CALL ROOMS =====\n";
            for (auto &n : nurses) {
                n->in();
                cout << string(50, '-') << endl;
            }

        }

    } while (choice != 0);
}

// Patient
void menuPatient(vector<Patient*>& patient) {}
int choice;
    do {
        cout << "\n===== PATIENT MANAGEMENT MENU =====\n";
        cout << "1. Patient list\n";
        cout << "2. Add new patient\n";
        cout << "3. Search patient by ID\n";
        cout << "4. Remove patient\n";
        cout << "5. Update patient information\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\n===== PATIENT LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(15) << "DOB"
                 << setw(10) << "Gender"
                 << setw(15) << "Phone"
                 << setw(20) << "Symptom"
                 << setw(20) << "Diagnosis" << endl;
            cout << string(110, '-') << endl;
            for (auto& p : patient) p.in();

        } else if (choice == 2) {
            Patient p;
            p.nhap();
            patients.push_back(p);
            cout << "Patient added successfully!\n";

        } else if (choice == 3) {
            string searchID;
            cout << "Enter Patient ID to search: ";
            getline(cin, searchID);
            bool found = false;

            for (auto& p : patients) {
                if (p.getPatientID() == searchID) {
                    cout << "\nPatient found:\n";
                    p.in();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Patient ID not found!\n";

        } else if (choice == 4) {
            string delID;
            cout << "Enter Patient ID to remove: ";
            getline(cin, delID);
            bool removed = false;

            for (auto it = patients.begin(); it != patients.end(); ++it) {
                if (it->getPatientID() == delID) {
                    patients.erase(it);
                    cout << "Patient removed successfully!\n";
                    removed = true;
                    break;
                }
            }
            if (!removed) cout << "Invalid Patient ID!\n";

        } else if (choice == 5) {
            string updateID;
            cout << "Enter Patient ID to update: ";
            getline(cin, updateID);
            bool updated = false;

            for (auto &p : patients) {
                if (p.getPatientID() == updateID) {
                    cout << "\nEnter new information:\n";
                    p.nhap();
                    cout << "Patient information updated successfully!\n";
                    updated = true;
                    break;
                }
            }
            if (!updated) cout << "Invalid Patient ID!\n";
        }

    } while (choice != 0);
}

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
void menuTreatment(vector<Treatment*>& treatments) {
    int choice;

    do {
        cout << "\n===== TREATMENT MENU =====\n";
        cout << "1. Treatment list\n";
        cout << "2. Treatment type list\n";
        cout << "3. Add surgery treatment\n";
        cout << "4. Add therapy treatment\n";
        cout << "5. Add medication treatment\n";
        cout << "6. Search treatment\n";
        cout << "7. Remove treatment\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\n===== TREATMENT LIST =====\n";
            cout << left
                 << setw(12) << "Type"
                 << setw(10) << "ID"
                 << setw(12) << "Patient"
                 << setw(12) << "Doctor"
                 << setw(15) << "Cost" << endl;
            cout << string(60, '-') << endl;

            for (auto &t : treatments) {
                cout << left
                     << setw(12) << t->getType()
                     << setw(10) << t->getID()
                     << setw(12) << t->getPatientId()
                     << setw(12) << t->getDoctorId()
                     << setw(15) << t->calculateCost() << endl;
            }
        
        } else if (choice == 2) {
            cout << "\n===== SURGERY TREATMENT LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(12) << "Patient"
                 << setw(12) << "Doctor"
                 << setw(15) << "Base Cost"
                 << setw(15) << "Surgery Fee"
                 << setw(15) << "Anesthesia" << endl;
            cout << string(79, '-') << endl;

            for (auto &t : treatments) {
                if (t->getType() == "Surgery") t->display();
            }

            cout << "\n===== THERAPY TREATMENT LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(12) << "Patient"
                 << setw(12) << "Doctor"
                 << setw(15) << "Base Cost"
                 << setw(15) << "Sessions"
                 << setw(15) << "Session Cost" << endl;
            cout << string(79, '-') << endl;

            for (auto &t : treatments) {
                if (t->getType() == "Therapy") t->display();
            }

            cout << "\n===== MEDICATION TREATMENT LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(12) << "Patient"
                 << setw(12) << "Doctor"
                 << setw(15) << "Medicine"
                 << setw(10) << "Quantity"
                 << setw(15) << "Unit Price" << endl;
            cout << string(74, '-') << endl;

            for (auto &t : treatments) {
                if (t->getType() == "Medication") t->display();
            }
        
        } else if (choice == 3) {
            Treatment* s = new Surgery();
            s->input();
            treatments.push_back(s);
            cout << "Adding treatment successfully!\n";
        
        } else if (choice == 4) {
            Treatment* t = new Therapy();
            t->input();
            treatments.push_back(t);
            cout << "Adding treatment successfully!\n";
        
        } else if (choice == 5) {
            Treatment* m = new Medication();
            m->input();
            treatments.push_back(m);
            cout << "Adding treatment successfully!\n";
        
        } else if (choice == 6) {
            bool found = false;
            string searchID;
            cout << "Enter treatment ID to search: ";
            getline(cin, searchID);

            for (auto &t : treatments) {
                if (t->getID() == searchID) {
                    cout << "\n===== TREATMENT DETAILS =====\n";
                    t->display();
                    found = true;
                    break;
                }    
            }
            if (!found) cout << "Invalid treatment ID!\n";

        } else if (choice == 7) {
            string delID;
            cout << "Enter treatment ID to remove: ";
            getline(cin, delID);

            bool removed = false;
            for (auto it = treatments.begin(); it != treatments.end(); it++) {
                if ((*it)->getID() == delID) {
                    delete *it;
                    it = treatments.erase(it);
                    removed = true;
                    cout << "Treatment removed successfully!\n";
                    break;
                }
            }
            if (!removed) cout << "Invalid treatment ID!\n";
        }

    } while (choice != 0);
}
