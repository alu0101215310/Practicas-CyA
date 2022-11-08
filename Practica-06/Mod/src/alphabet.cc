////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 6 - Simulación de Autómatas Finitos
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 8/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo alphabet.cc: 
//   Fichero que contiene las definición de la clase alphabet y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "../include/alphabet.h"

alphabet::alphabet(void) {}

// Constructor que inicializa los símbolos de un alfabeto desde un string
alphabet::alphabet(std::string rawAlphabet) {
  for (auto it : rawAlphabet) {
    if (it != SPACE) 
      symbols.insert(it);
    else if (it == EMPTY) 
      throw sintaxError();
  }
}

// Constructor que inicializa los símbolos de un alfabeto desde una cadena
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
