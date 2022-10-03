#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <sstream>

class chain {
  private:
    std::vector<char> info;

  public:
    chain(std::string newInfo);
    ~chain();

    std::vector<char> getChain();
};
