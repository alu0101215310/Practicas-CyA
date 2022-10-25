#include "../include/return.h"

returnEx::returnEx (void) {};

returnEx::returnEx (std::string rawReturnEx, int line) {
  pos = line;

  std::string word;
  std::stringstream auxLine(rawReturnEx);

  getline(auxLine, word, SPACE);
    while (word != RETURN)
      getline(auxLine, word, SPACE);

  getline(auxLine, word, DOTCHCOME);
    while (*word.c_str() == SPACE)
      getline(auxLine, word, SPACE);
    type = word;
};

returnEx::~returnEx (void) {};

std::string returnEx::getType (void) const { return type; };

int returnEx::getPos (void) const { return pos; };

std::ostream& operator<<(std::ostream& os, const returnEx& printreturnEx) {
  os << "[ Line " << printreturnEx.getPos() << " ] return: " << printreturnEx.getType();
  return os;
}