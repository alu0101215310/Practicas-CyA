#include "chain.h"

class alphabet {
  private:
    std::set<char> symbols;

  public:
    alphabet(std::set<char>);
    ~alphabet();

    std::set<char> getSymbols();
};
