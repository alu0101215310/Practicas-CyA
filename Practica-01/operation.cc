#include "operation.h"

operation::operation(char* argv[]) {
  input.open(argv[1]);
  output.open(argv[2]);
  code = atoi(argv[3]);
}

operation::~operation() {}

void operation::init () {
  std::string line;
  std::string symbol;
  while (getline(input, line)) {
    std::stringstream auxLine(line);
    std::set<char> auxSet;
    while (getline(auxLine, symbol, ' ')) {
      auxSet.insert(*symbol.c_str());
    }
    if (auxSet.size() == 1) {
      auxSet.erase(*symbol.c_str());
      for (auto it : symbol) {
        auxSet.insert(it);
      }
    }
    language.push_back(chain(symbol));
  }
  switch (code) {
    case 1:
      lenght();
      break;
    case 2:
      reverse();
      break;
    case 3:
      preffix();
      break;
    case 4:
      suffix();
      break;
    case 5:
      subchain();
      break;
    default:
      break;
  }
}

void operation::lenght() {
  for (auto it : language) {
    output << it.getChain().size() << std::endl;
  }
}

void operation::reverse() {
  for (auto it : language) {
    for (int i = it.getChain().size() - 1; i >= 0; i--) {
      output << it.getChain()[i];
    }
    output << std::endl;
  }
}

void operation::preffix() {
  int counter = 0;
  for (auto it : language) {
    if (it.getChain()[0] != '&') output << "& ";
    while (counter < it.getChain().size()) {
      for (int i = 0; i <= counter; i++) {
        output << it.getChain()[i];
      }
      output << " ";
      counter++;
    }
    output << std::endl;
    counter = 0;
  }
}

void operation::suffix() {
  int counter;
  for (auto it : language) {
    if (it.getChain()[0] != '&') output << "& ";
    counter = it.getChain().size() - 1;
    while (counter >= 0) {
      for (int i = counter; i < it.getChain().size(); i++) {
        output << it.getChain()[i];
      }
      output << " ";
      counter--;
    }
    output << std::endl;
  }
}

void operation::subchain() {
  for (auto it : language) {
    for (int i = 0; i < it.getChain().size(); i++) {
      int counter = i;
      while (counter < it.getChain().size()) {
        for (int j = i; j <= counter; j++) {
          output << it.getChain()[j];
        }
        output << " ";
        counter++;
      }
    }
    output << std::endl; 
  }  
}

