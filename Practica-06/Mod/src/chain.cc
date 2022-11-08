////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 6 - Simulación de Autómatas Finitos
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 8/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo chain.cc: 
//   Fichero que contiene las definición de la clase chain y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "../include/chain.h"

chain::chain(void) {}

// Constructor que transforma un string en vector de caracteres
chain::chain(std::string newChain) {
  for (auto it : newChain) 
    symbols.push_back(it);
  if (symbols[0] == EMPTY && symbols.size() != 1)
    throw sintaxError();
}

// Destructor
chain::~chain(void) {}

// Devuelve el vector de la cadena
std::vector<char> chain::getChain() const {
  return symbols;
}

std::ostream& operator<<(std::ostream& os, const chain& printChain) {
  if (printChain.getChain().empty()) 
    os << EMPTY;
  else
    for ( auto it : printChain.getChain()) os << it;
  return os;
}
