#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
using namespace std;

class Person{
protected:
  string name;
  string DOB;
  string gender;
  string phone;

public:
  Person();
  virtual void nhap();
  virtual void in() const;
  
  virtual ~Person() {};
};

#endif

