#include "chain.h"

class alphabet {
  private:
    std::set<char> symbols;

  public:
    alphabet(std::set<char>);
    ~alphabet();

/*
    std::set<char> getSymbols();
    std::set<chain> getChains();

    void setSymbols(std::set<char>);
    void setChains(std::set<chain>);

    void addChain(chain newChain);
    */
};
