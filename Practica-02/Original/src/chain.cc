////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 2 - Operaciones con lenguajes
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo chain.cc: 
//    Fichero que contiene las definición de la clase chain y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "../include/chain.h"

chain::chain(void) {}

chain::chain(std::vector<char> newChain) : symbols(newChain) {}

// Constructor que transforma un string en vector de caracteres
chain::chain(std::string newChain) {
  if (newChain != "&")
    for (auto it : newChain) 
      symbols.push_back(it);
}

// Destructor
chain::~chain(void) {}

// Devuelve el vector de la cadena
std::vector<char> chain::getChain() const {
  return symbols;
}

bool chain::operator<(const chain& compareChain) const {
  if (symbols < compareChain.getChain()) 
    return true;
  else 
    return false;
}

bool chain::operator==(const chain& compareChain) const {
  if (symbols == compareChain.getChain()) 
    return true;
  else 
    return false;
}

chain chain::operator*(const chain& optChain) const {
  std::vector<char> auxVector(getChain());
  std::vector<char> auxVector2(optChain.getChain());
  auxVector.insert(auxVector.end(), auxVector2.begin(), auxVector2.end());
  chain result(auxVector);

  return result; 
}

chain chain::reverseChain(void) {
  std::vector<char> auxChain;
  for (int i = getChain().size() -1; i >= 0; i--) 
    auxChain.push_back(getChain()[i]);
  chain result(auxChain);
  return result;
}

std::ostream& operator<<(std::ostream& os, const chain& printChain) {
  if (printChain.getChain().empty()) 
    os << EMPTY;
  else
    for ( auto it : printChain.getChain()) os << it;
  return os;
}
