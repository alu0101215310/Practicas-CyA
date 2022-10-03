#include "alphabet.h"

alphabet::alphabet(std::set<char> newSymbols) {
  symbols = newSymbols;
}

alphabet::~alphabet() {}

/*
std::set<char> alphabet::getSymbols() {
  return symbols;
}

std::set<chain> alphabet::getChains() {
  return chains;
}

void alphabet::setSymbols(std::set<char> newSymbols) {
  symbols = newSymbols;
}

void alphabet::setChains(std::set<chain> newChains) {
  chains = newChains;
}
*/