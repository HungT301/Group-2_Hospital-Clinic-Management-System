#ifndef APPOINTMENTTYPE_HPP
#define APPOINTMENTTYPE_HPP

#include "Appointment.hpp"
using namespace std;

// --------------------- CheckupAppointment ---------------------
class CheckupAppointment : public Appointment {
private:
    string room;              
    string purpose;           

public:
    CheckupAppointment();

    void nhap() override;
    void in() const override;
};

// --------------------- SurgeryAppointment ---------------------
class SurgeryAppointment : public Appointment {
private:
    string surgeryType;       
    string operationRoom;     
    string mainSurgeon;       

public:
    SurgeryAppointment();

    void nhap() override;
    void in() const override;
};

// --------------------- TherapyAppointment ---------------------
class TherapyAppointment : public Appointment {
private:
    string therapyType;      
    int sessionCount;         
    string therapist;         

public:
    TherapyAppointment();

    void nhap() override;
    void in() const override;
};

#endif