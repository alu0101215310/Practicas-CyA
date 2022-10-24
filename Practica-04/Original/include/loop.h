#include "exception.h"

class loop {
  private:
    std::string type;
    int pos;

  public:
    loop(void);
    loop(std::string,int);
    ~loop(void);

    std::string getType(void) const;
    int getPos(void) const;  
};

std::ostream& operator<<(std::ostream&, const loop&);
