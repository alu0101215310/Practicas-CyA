#include "chain.h"

chain::chain(std::string newInfo) {
  for (auto it : newInfo) {
    info.push_back(it);
  }
}

chain::~chain() {}

std::vector<char> chain::getChain() {
  return info;
}
/*
std::string chain::getInfo() {
  return info;
}

std::set<char> chain::getSymbols() {
  return symbols;
}

void chain::setSymbols(std::set<char> newSymbols) {
  symbols = newSymbols;
}
*/

std::ostream& operator<<(std::ostream& os, const chain& chain) {
  os << chain;
	
	return os;
}