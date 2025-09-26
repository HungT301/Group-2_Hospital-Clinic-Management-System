#ifdef Nurse_h
#define Nurse_h

#include <string>
using namespace std;

class Nurse{
  private:
    string name, id, catruc, phongtruc;
  public:
    Nurse();
    void in();
    void out();
    ~Nurse();
};
#endif
