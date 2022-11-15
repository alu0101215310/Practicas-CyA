////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 7 - Gramática Regular a partir de un DFA
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 15/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo grammar.cc: 
//   Fichero que contiene las definición de la clase grammar y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "../include/grammar.h"

grammar::grammar(void) {}

grammar::~grammar(void) {}

alphabet grammar::getAlphabet(void) const {
  return symbols;
}

std::set<std::string> grammar::getNTS(void) const {
  return nts;
}

std::map<std::string, production> grammar::getProductions(void) const {
  return productions;
}

void grammar::setAlphabet(alphabet newAlphabet) {
  symbols = newAlphabet;
}

void grammar::addProduction(std::string st, std::string t, std::string nt) {
  if (!productions[st].getProduction().empty())
    productions[st].update(t, nt); // Si existe actualiza
  else 
    productions[st] = production(t, nt); // Si no lo crea
}

void grammar::addNT(std::string nt) {
  nts.insert(nt);
}