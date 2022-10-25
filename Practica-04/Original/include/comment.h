#include "exception.h"

class comment {
  private:
    std::string type;
    int firstPos;
    int lastPos;
    std::vector<std::string> var;

  public:
    comment(void);
    comment(std::string,int);
    ~comment(void);

    void addLine(std::string);
    void addLastPos(int);

    std::string getType(void) const;
    int getFirstPos(void) const;
    int getLastPos(void) const;
    std::vector<std::string> getVar(void) const;
};

std::ostream& operator<<(std::ostream&, const comment&);
