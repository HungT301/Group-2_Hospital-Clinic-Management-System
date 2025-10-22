#include <iostream>
#include <iomanip>
#include <fstream>
#include <nlohmann/json.hpp>
#include <filesystem>
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
using json = nlohmann::json;
namespace fs = std::filesystem;

// Menu function
void menuDoctor(vector<Doctor>& doctors);
void menuNurse(vector<Nurse>& nurses);
void menuPatient(vector<Patient>& patients);
void menuAppointment(vector<Appointment*>& appointments);
void menuTreatment(vector<Treatment*>& treatments);

// Main
int main() {
    if (!fs::exists("data")) {
        fs::create_directory("data");
    }

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
void menuDoctor(vector<Doctor>& doctors) {
    int choice;

    ifstream fin("data/doctors.json");
    if (fin && fin.peek() != ifstream::traits_type::eof()) {
        json j;
        fin >> j;
        for (auto& item : j) {
            Doctor d;
            d.fromJson(item);
            doctors.push_back(d);
        }
        fin.close();
    }

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
                 << setw(12) << "ID"
                 << setw(20) << "Name"
                 << setw(15) << "DOB"
                 << setw(12) << "Gender"
                 << setw(15) << "Phone"
                 << setw(15) << "Specialty" << endl;
            cout << string(95, '-') << endl;

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
                if (d.getstaffID() == searchID) {
                    cout << "\n===== DOCTOR FOUND =====\n";
                    cout << left
                         << setw(12) << "ID"
                         << setw(20) << "Name"
                         << setw(15) << "DOB"
                         << setw(12) << "Gender"
                         << setw(15) << "Phone"
                         << setw(15) << "Specialty" << endl;
                    cout << string(95, '-') << endl;
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
                if (it->getstaffID() == delID) {
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
                if (d.getstaffID() == updateID) {
                    cout << "Enter new information for this doctor:\n";
                    d.nhap();
                    cout << "Doctor updated successfully!\n";
                    updated = true;
                    break;
                }
            }
            if (!updated) cout << "Invalid Doctor ID!\n";

        } else if (choice == 6) {
            string searchID;
            bool found = false;
            cout << "Enter Doctor ID to view schedule: ";
            getline(cin, searchID);

            for (auto &d : doctors) {
                if (d.getstaffID() == searchID) {
                    cout << "\n===== DOCTOR SCHEDULE =====\n";
                    cout << left
                         << setw(12) << "Day"
                         << setw(15) << "Shift"
                         << setw(15) << "Consult Room" << endl;
                    cout << string(42, '-') << endl;
                    d.display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Doctor ID not found!\n";
        }

    } while (choice != 0);

    json j;
    for (auto& d : doctors)
        j.push_back(d.toJson());
    ofstream fout("data/doctors.json", ios::out | ios::trunc);
    fout << setw(4) << j.dump(4);
    fout.close();
}

// Nurse
void menuNurse(vector<Nurse>& nurses) {
    int choice;

    ifstream fin("data/nurses.json");
    if (fin && fin.peek() != ifstream::traits_type::eof()) {
        json j;
        fin >> j;
        for (auto& item : j) {
            Nurse n;
            n.fromJson(item);
            nurses.push_back(n);
        }
        fin.close();
    }

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

            for (auto &n : nurses) n.in();

        } else if (choice == 2) {
            Nurse n;
            n.nhap();
            nurses.push_back(n);
            cout << "Nurse added successfully!\n";

        } else if (choice == 3) {
            bool found = false;
            string searchID;
            cout << "Enter Nurse ID to search: ";
            getline(cin, searchID);

            for (auto &n : nurses) {
                if (n.getstaffID() == searchID) {
                    cout << "\n===== NURSE FOUND =====\n";
                    cout << left
                         << setw(10) << "ID"
                         << setw(20) << "Name"
                         << setw(15) << "DOB"
                         << setw(15) << "Gender"
                         << setw(15) << "Phone" << endl;
                    cout << string(75, '-') << endl;
                    n.in();
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
                if (n.getstaffID() == updateID) {
                    cout << "Enter new information for this nurse:\n";
                    n.nhap();
                    cout << "Nurse updated successfully!\n";
                    updated = true;
                    break;
                }
            }
            if (!updated) cout << "Invalid Nurse ID!\n";

        } else if (choice == 6) {
            string searchID;
            bool found = false;
            cout << "Enter Nurse ID to view schedule: ";
            getline(cin, searchID);

            for (auto &n : nurses) {
                if (n.getstaffID() == searchID) {
                     cout << "\n===== NURSE SCHEDULE =====\n";
                     cout << left
                          << setw(12) << "Day"
                          << setw(15) << "Shift"
                          << setw(15) << "Oncall Room" << endl;
                    
                     cout << string(42, '-') << endl;
                     n.display(); 
                     found = true;
                     break;
                }
            }
            if (!found) cout << "Nurse ID not found!\n";
        }

    } while (choice != 0);

    json j;
    for (auto& n : nurses)
        j.push_back(n.toJson());
    ofstream fout("data/nurses.json", ios::out | ios::trunc);
    fout << setw(4) << j.dump(4);
    fout.close();
}

// Patient
void menuPatient(vector<Patient>& patients) {
    int choice;
    
    ifstream fin("data/patients.json");
    if (fin) {
        json j;
        fin >> j;
        for (auto& item : j)
            if (!item.is_null()) {
                Patient p;
                p.fromJson(item);
                patients.push_back(p);
            }
        fin.close();
    }

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
                 << setw(15) << "Gender"
                 << setw(15) << "Phone"
                 << setw(20) << "Symptom"
                 << setw(20) << "Diagnosis" << endl;
            cout << string(110, '-') << endl;

            for (auto& p : patients) p.in();

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

            for (auto& p : patients) {
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

    json j;
    for (auto& p : patients)
        j.push_back(p.toJson());
    ofstream fout("data/patients.json");
    fout << setw(4) << j; 
    fout.close();
}

// Appointment
void menuAppointment(vector<Appointment*>& appointments) {
    int choice;

    ifstream fin("data/appointments.json");
    if (fin && fin.peek() != ifstream::traits_type::eof()) {
        json j;
        fin >> j;
        for (auto& item : j) {
            string type = item.value("type", "");
            Appointment* a = nullptr;
            if (type == "Checkup") a = new CheckupAppointment();
            else if (type == "Surgery") a = new SurgeryAppointment();
            else if (type == "Therapy") a = new TherapyAppointment();
            else continue;

            a->fromJson(item);
            appointments.push_back(a);
        }
        fin.close();
    }

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
                 << setw(15) << "Type"
                 << setw(10) << "ID"
                 << setw(15) << "Patient"
                 << setw(15) << "Doctor"
                 << setw(15) << "Time" << endl;
            cout << string(65, '-') << endl;

            for (auto &a : appointments) a->sumary();
        
        } else if (choice == 2) {
            cout << "\n===== CHECKUP APPOINTMENT LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(15) << "Patient"
                 << setw(15) << "Doctor"
                 << setw(15) << "Time"
                 << setw(15) << "room"
                 << setw(20) << "purpose" << endl;
            cout << string(90, '-') << endl;

            for (auto &a : appointments) {
                if (a->getType() == "Checkup") a->in();
            }

            cout << "\n===== SURGERY APPOINTMENT LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(15) << "Patient"
                 << setw(15) << "Doctor"
                 << setw(15) << "Time"
                 << setw(15) << "Type"
                 << setw(15) << "Room"
                 << setw(20) << "Surgeon" << endl;
            cout << string(105, '-') << endl;

            for (auto &a : appointments) {
                if (a->getType() == "Surgery") a->in();
            }

            cout << "\n===== THERAPY APPOINTMENT LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(15) << "Patient"
                 << setw(15) << "Doctor"
                 << setw(15) << "Time"
                 << setw(15) << "Type"
                 << setw(15) << "Session"
                 << setw(20) << "Therapist" << endl;
            cout << string(105, '-') << endl;

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
                         << setw(15) << "Type"
                         << setw(10) << "ID"
                         << setw(15) << "Patient"
                         << setw(15) << "Doctor"
                         << setw(15) << "Time" << endl;
                    cout << string(70, '-') << endl;
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

    json j;
    for (auto& a : appointments)
        j.push_back(a->toJson());
    ofstream fout("data/appointments.json", ios::out | ios::trunc);
    fout << setw(4) << j.dump(4);
    fout.close();
}

//Treatment
void menuTreatment(vector<Treatment*>& treatments) {
    int choice;

    ifstream fin("data/treatments.json");
    if (fin) {
        json j; fin >> j;
        for (auto& item : j) {
            string type = item.value("type", "");
            Treatment* t = nullptr;

            if (type == "Medication") t = new Medication();
            else if (type == "Surgery") t = new Surgery();
            else if (type == "Therapy") t = new Therapy();

            if (t) {
                t->fromJson(item);
                treatments.push_back(t);
            }
        }
    fin.close();
    }

    do {
        cout << "\n===== TREATMENT MANAGEMENT MENU =====\n";
        cout << "1. Treatment list\n";
        cout << "2. Treatment list by type\n";
        cout << "3. Add Medication\n";
        cout << "4. Add Surgery\n";
        cout << "5. Add Therapy\n";
        cout << "6. Search treatment by ID\n";
        cout << "7. Remove treatment\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\n===== ALL TREATMENTS =====\n";
            cout << left
                 << setw(15) << "Type"
                 << setw(10) << "ID"
                 << setw(15) << "Patient ID"
                 << setw(15) << "Doctor ID"
                 << setw(20) << "Description"
                 << setw(15) << "Base Cost" << endl;
            cout << string(90, '-') << endl;

            for (auto &t : treatments) t->sumary();

        } else if (choice == 2) {
            cout << "\n===== MEDICATION LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(15) << "Patient ID"
                 << setw(15) << "Doctor ID"
                 << setw(20) << "Description"
                 << setw(15) << "Base cost"
                 << setw(15) << "Quantity"
                 << setw(15) << "Price/Unit"
                 << setw(15) << "Total" << endl;
            cout << string(110, '-') << endl;

            for (auto& t : treatments)
                if (t->getType() == "Medication") t->in();

            cout << "\n===== SURGERY LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(15) << "Patient ID"
                 << setw(15) << "Doctor ID"
                 << setw(20) << "Description"
                 << setw(15) << "Base cost"
                 << setw(15) << "Doctor Fee"
                 << setw(15) << "Equip. Cost"
                 << setw(15) << "Total" << endl;
            cout << string(120, '-') << endl;

            for (auto& t : treatments)
                if (t->getType() == "Surgery") t->in();

            cout << "\n===== THERAPY LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(15) << "Patient ID"
                 << setw(15) << "Doctor ID"
                 << setw(20) << "Description"
                 << setw(15) << "Base cost"
                 << setw(15) << "Sessions"
                 << setw(20) << "Price/Session"
                 << setw(15) << "Total" << endl;
            cout << string(125, '-') << endl;

            for (auto& t : treatments)
                if (t->getType() == "Therapy") t->in();

        } else if (choice == 3) {
            Treatment* m = new Medication();
            m->nhap();
            treatments.push_back(m);
            cout << "Medication added successfully!\n";

        } else if (choice == 4) {
            Treatment* s = new Surgery();
            s->nhap();
            treatments.push_back(s);
            cout << "Surgery added successfully!\n";

        } else if (choice == 5) {
            Treatment* th = new Therapy();
            th->nhap();
            treatments.push_back(th);
            cout << "Therapy added successfully!\n";

        } else if (choice == 6) {
            bool found = false;
            string searchID;
            cout << "Enter treatment ID to search: ";
            getline(cin, searchID);

            for (auto& t : treatments) {
                if (t->getID() == searchID) {
                    cout << "\n===== TREATMENT FOUND =====\n";
                    cout << left
                         << setw(15) << "Type"
                         << setw(10) << "ID"
                         << setw(15) << "Patient ID"
                         << setw(15) << "Doctor ID"
                         << setw(20) << "Description"
                         << setw(15) << "Base Cost" << endl;
                    cout << string(90, '-') << endl;
                    t->sumary();
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Invalid Treatment ID!\n";

        } else if (choice == 7) {
            string delID;
            cout << "Enter treatment ID to remove: ";
            getline(cin, delID);

            bool removed = false;
            for (auto it = treatments.begin(); it != treatments.end(); ++it) {
                if ((*it)->getID() == delID) {
                    delete *it;
                    treatments.erase(it);
                    cout << "Treatment removed successfully!\n";
                    removed = true;
                    break;
                }
            }
            if (!removed) cout << "Invalid Treatment ID!\n";
        }

    } while (choice != 0);

    json j;
    for (auto& t : treatments)
        j.push_back(t->toJson());

    ofstream fout("data/treatments.json");
    fout << setw(4) << j;
    fout.close();
}
