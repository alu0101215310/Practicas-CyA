#include "exception.h"

class comment {
  private:
    bool type;
    std::vector<int> pos;
    std::vector<std::string> var;

  public:
    comment(void);
    comment(std::string,int,bool);
    ~comment(void);

    void addLine(std::string,int);
};

std::ostream& operator<<(std::ostream&, const comment&);
