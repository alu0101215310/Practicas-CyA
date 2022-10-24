#include "../include/variable.h"

variable::variable (void) {};

variable::variable (std::string rawVariable, int line) {
  pos = line;

  std::string word;
  std::stringstream auxLine(rawVariable);

  getline(auxLine, word, SPACE);
    while (word != "int" && word != "double")
      getline(auxLine, word, SPACE);
    type = word;
  getline(auxLine, word, EQUAL);
    name = word;
    for ( auto it : name) {
      if (name.find(SPACE) != std::string::npos)
        name.erase(name.find(SPACE), 1);
    }
  getline(auxLine, word, DOTCHCOME);
    var = atoi(word.c_str());
};

variable::~variable (void) {};

std::string variable::getType (void) const { return type; }

std::string variable::getName (void) const { return name; }

int variable::getPos (void) const { return pos; }

double variable::getVar (void) const { return var; }

std::ostream& operator<<(std::ostream& os, const variable& printVariable) {
  os << "[ Line " << printVariable.getPos() << " ] " << printVariable.getType() << ": " << 
    printVariable.getName() << " = " << printVariable.getVar();
  return os;
}