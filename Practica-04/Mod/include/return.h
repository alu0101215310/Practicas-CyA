#include "exception.h"

class returnEx {
  private:
    std::string type;
    int pos;

  public:
    returnEx(void);
    returnEx(std::string,int);
    ~returnEx(void);

    std::string getType(void) const;
    int getPos(void) const;  
};

std::ostream& operator<<(std::ostream&, const returnEx&);
