////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 2 - Operaciones con lenguajes
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo alphabet.cc: 
//    Fichero que contiene las definición de la clase alphabet y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "../include/alphabet.h"

alphabet::alphabet(void) {}

alphabet::alphabet(std::string rawAlphabet) {
  for (auto it : rawAlphabet) {
    if (it != SPACE && it != OPEN) 
      symbols.insert(it);
    else if (it == EMPTY) 
      throw sintaxError();
  }
}

// Constructor que inicializa los s´imbolos de un alfabeto
alphabet::alphabet(std::set<chain> chains) {
  for (auto optChain : chains) {
    for (auto it : optChain.getChain()) {
      if (it != EMPTY)
        symbols.insert(it);
    }
  }
}

// Destructor
alphabet::~alphabet(void) {}

// Devuelve los símbolos de un alfabeto
std::set<char> alphabet::getAlphabet(void) const {
  return symbols;
}

std::ostream& operator<<(std::ostream& os, const alphabet& printAlphabet) {
  for ( auto it : printAlphabet.getAlphabet()) os << it << SPACE;
  return os;
}
