#include <iostream>
#include <vector>
#include <string>
#include <set>

class chain {
  private:
    std::vector<char> info;

  public:
    chain(std::string newInfo);
    ~chain();

    std::vector<char> getChain();
    //std::string getInfo();
    //std::set<char> getSymbols();

    //void setSymbols(std::set<char>);
    //void setInfo(std::string);
};


std::ostream& operator<<(std::ostream&, const chain&);

