////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 4 - Expresiones regulares
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 25/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo loop.cc: 
//    Fichero que contiene las definición de la clase loop y sus métodos
////////////////////////////////////////////////////////////////////////////////

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
