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
void menuDoctor(vector<Doctor>& doctors) {
    int choice;
    do {
        cout << "\n===== DOCTOR MANAGEMENT MENU =====\n";
        cout << "1. Doctor list\n";
        cout << "2. Add new doctor\n";
        cout << "3. Search doctor by ID\n";
        cout << "4. Remove doctor\n";
        cout << "5. Update doctor information\n";
        cout << "6. Doctor schedule list\n"; 
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
            for (auto &d : doctors) d.display();

        } else if (choice == 2) {
            Doctor d;
            d.input();
            doctors.push_back(d);
            cout << "Doctor added successfully!\n";

        } else if (choice == 3) {
            string searchID;
            cout << "Enter Doctor ID to search: ";
            getline(cin, searchID);
            bool found = false;

            for (auto &d : doctors) {
                if (d.getID() == searchID) {
                    cout << "\nDoctor found:\n";
                    d.display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Doctor ID not found!\n";

        } else if (choice == 4) {
            string delID;
            cout << "Enter Doctor ID to remove: ";
            getline(cin, delID);
            bool removed = false;

            for (auto it = doctors.begin(); it != doctors.end(); it++) {
                if (it->getID() == delID) {
                    doctors.erase(it);
                    removed = true;
                    cout << "Doctor removed successfully!\n";
                    break;
                }
            }
            if (!removed) cout << "Invalid Doctor ID!\n";

        } else if (choice == 5) {
            string updateID;
            cout << "Enter Doctor ID to update: ";
            getline(cin, updateID);
            bool updated = false;

            for (auto &d : doctors) {
                if (d.getID() == updateID) {
                    cout << "Enter new information for this doctor:\n";
                    d.input();
                    cout << "Doctor updated successfully!\n";
                    updated = true;
                    break;
                }
            }
            if (!updated) cout << "Invalid Doctor ID!\n";

        } else if (choice == 6) {
            cout << "\n===== DOCTOR SCHEDULE LIST =====\n";
            cout << left
                 << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(15) << "Specialty"
                 << setw(30) << "Schedule" << endl;
            cout << string(75, '-') << endl;
            for (auto &d : doctors) d.showSchedule();
        }   
    } while (choice != 0);
}

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
void menuTreatment(vector<Treatment*>& treatments) {
    int choice;
    do {
        cout << "\n=== TREATMENT MANAGEMENT ===" << endl;
        cout << "1. Add new treatment" << endl;
        cout << "2. Display all treatments" << endl;
        cout << "3. Calculate total treatment cost" << endl;
        cout << "4. Search treatments by patient ID" << endl;
        cout << "5. Update treatment information" << endl;
        cout << "6. Delete treatment" << endl;
        cout << "7. Display treatments by type" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int type;
                cout << "Select treatment type:" << endl;
                cout << "1. Surgery" << endl;
                cout << "2. Therapy" << endl;
                cout << "3. Medication" << endl;
                cout << "Enter your choice: ";
                cin >> type;

                Treatment* newTreatment = nullptr;
                switch (type) {
                    case 1:
                        newTreatment = new Surgery();
                        break;
                    case 2:
                        newTreatment = new Therapy();
                        break;
                    case 3:
                        newTreatment = new Medication();
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }

                if (newTreatment) {
                    newTreatment->input();
                    treatments.push_back(newTreatment);
                    cout << "Treatment added successfully!" << endl;
                }
                break;
            }
            case 2: {
                if (treatments.empty()) {
                    cout << "Treatment list is empty!" << endl;
                } else {
                    cout << "\n=== ALL TREATMENTS ===" << endl;
                    for (size_t i = 0; i < treatments.size(); i++) {
                        cout << "--- Treatment " << i + 1 << " ---" << endl;
                        treatments[i]->display();
                        cout << endl;
                    }
                }
                break;
            }
            case 3: {
                double totalCost = 0;
                for (const auto& treatment : treatments) {
                    totalCost += treatment->calculateCost();
                }
                cout << "Total treatment cost: " << fixed << setprecision(2) << totalCost << " VND" << endl;
                break;
            }
            case 4: {
                string patientId;
                cout << "Enter patient ID to search: ";
                cin >> patientId;
                
                bool found = false;
                for (const auto& treatment : treatments) {
                    if (treatment->getPatientId() == patientId) {
                        treatment->display();
                        cout << endl;
                        found = true;
                    }
                }
                if (!found) {
                    cout << "No treatments found for patient ID: " << patientId << endl;
                }
                break;
            }
            case 5: {
                string treatmentId;
                cout << "Enter treatment ID to update: ";
                cin >> treatmentId;
                
                bool found = false;
                for (auto& treatment : treatments) {
                    if (treatment->getID() == treatmentId) {
                        cout << "Current treatment information:" << endl;
                        treatment->display();
                        cout << "\nEnter new information:" << endl;
                        treatment->input();
                        cout << "Treatment updated successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Treatment with ID " << treatmentId << " not found!" << endl;
                }
                break;
            }
            case 6: {
                string treatmentId;
                cout << "Enter treatment ID to delete: ";
                cin >> treatmentId;
                
                bool found = false;
                for (auto it = treatments.begin(); it != treatments.end(); ++it) {
                    if ((*it)->getID() == treatmentId) {
                        delete *it;
                        treatments.erase(it);
                        cout << "Treatment deleted successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Treatment with ID " << treatmentId << " not found!" << endl;
                }
                break;
            }
            case 7: {
                int type;
                cout << "Select treatment type to display:" << endl;
                cout << "1. Surgery" << endl;
                cout << "2. Therapy" << endl;
                cout << "3. Medication" << endl;
                cout << "Enter your choice: ";
                cin >> type;
                
                bool found = false;
                for (const auto& treatment : treatments) {
                    switch (type) {
                        case 1:
                            if (dynamic_cast<Surgery*>(treatment)) {
                                treatment->display();
                                cout << endl;
                                found = true;
                            }
                            break;
                        case 2:
                            if (dynamic_cast<Therapy*>(treatment)) {
                                treatment->display();
                                cout << endl;
                                found = true;
                            }
                            break;
                        case 3:
                            if (dynamic_cast<Medication*>(treatment)) {
                                treatment->display();
                                cout << endl;
                                found = true;
                            }
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            return;
                    }
                }
                if (!found) {
                    cout << "No treatments of selected type found!" << endl;
                }
                break;
            }
            case 0:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
        
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
        
    } while (choice != 0);
}
// In Treatment.hpp
class Treatment {
protected:
    string id;
    string patientId;
    string doctorId;
    string description;
    double baseCost;

public:
    Treatment();

    virtual void input();
    virtual void display() const;
    virtual double calculateCost() const = 0;

    string getID() const { return id; }
    string getPatientId() const { return patientId; }
    string getDoctorId() const { return doctorId; }

    virtual ~Treatment() {}
};
// Treatment.cpp
#include <iostream>
#include "Treatment.hpp"
using namespace std;

Treatment::Treatment() : baseCost(0) {}

void Treatment::input() {
    cout << "Enter treatment ID: ";
    cin >> id;
    cout << "Enter patient ID: ";
    cin >> patientId;
    cout << "Enter doctor ID: ";
    cin >> doctorId;
    cin.ignore();
    cout << "Enter description: ";
    getline(cin, description);
    cout << "Enter base cost: ";
    cin >> baseCost;
}

void Treatment::display() const {
    cout << "Treatment ID: " << id << endl;
    cout << "Patient ID: " << patientId << endl;
    cout << "Doctor ID: " << doctorId << endl;
    cout << "Description: " << description << endl;
    cout << "Base cost: " << baseCost << endl;
}


