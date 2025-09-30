#include <iotream>
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

Nurse::Nurse(){
  name = ""; id  = ""; catruc = ""; phongtruc = "";
}

Nurse::~Nurse(){
//code
}

void Nurse::in(){
// code block
}

void Nurse::out{
//code block
}

int main(){
//copde block
  return 0;
}
