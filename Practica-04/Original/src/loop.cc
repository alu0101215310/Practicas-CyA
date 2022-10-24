#include "../include/loop.h"

loop::loop (void) {};

loop::loop (std::string rawloop, int line) {
  pos = line;

  std::string word;
  std::stringstream auxLine(rawloop);

  getline(auxLine, word, OPEN);
    type = word;
    for ( auto it : type) {
      if (type.find(SPACE) != std::string::npos)
        type.erase(type.find(SPACE), 1);
    }
};

loop::~loop (void) {};

std::string loop::getType (void) const { return type; };

int loop::getPos (void) const { return pos; };

std::ostream& operator<<(std::ostream& os, const loop& printLoop) {
  os << "[ Line " << printLoop.getPos() << " ] LOOP: " << printLoop.getType();
  return os;
}
