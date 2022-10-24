#include "exception.h"

class variable {
  private:
    std::string type;
    std::string name;
    int pos;
    double var;

  public:
    variable(void);
    variable(std::string,int);
    ~variable(void);
  
    std::string getType(void) const;
    std::string getName(void) const;
    int getPos(void) const;
    double getVar(void) const;

};

std::ostream& operator<<(std::ostream&, const variable&);
