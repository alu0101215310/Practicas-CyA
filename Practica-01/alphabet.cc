#include "alphabet.h"

alphabet::alphabet(std::set<char> newSymbols) {
  symbols = newSymbols;
}

alphabet::~alphabet() {}

std::set<char> alphabet::getSymbols() {
  return symbols;
}