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
