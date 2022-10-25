////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 3 - Calculadora de lenguajes formales
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo language.cc: 
//    Fichero que contiene las definición de la clase language y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "../include/language.h"

language::language(void) {}

language::language(std::string rawLanguage) {
  std::string rawChain;
  std::string newName;

  rawLanguage.erase(rawLanguage.find(OPEN), 1);
  rawLanguage.erase(rawLanguage.find(CLOSE), 1);
  rawLanguage.erase(rawLanguage.find(EQUAL), 1);
  for ( auto it : rawLanguage) {
    if (rawLanguage.find(COME) != std::string::npos)
      rawLanguage.erase(rawLanguage.find(COME), 1);
  }

  std::stringstream newLanguage(rawLanguage);

  getline(newLanguage, newName, SPACE);
  name = newName;
  getline(newLanguage, newName, SPACE);

  while (getline(newLanguage, rawChain, SPACE)) {
    chain newChain(rawChain);
    setChain(newChain);
  }
  symbols = alphabet(chains);
}

// Destructor
language::~language(void) {}

std::string language::getName(void) const {
  return name;
}

// Devuelve los símbolos de un alfabeto
std::set<chain> language::getLanguage(void) const {
  return chains;
}

alphabet language::getAlphabet(void) const {
  return symbols;
}

void language::setChain(chain newChain) {
  chains.insert(newChain);
}

language language::concatenate(language opt) {
  language result;  
  for (auto it1 : getLanguage()) {
    for (auto it2 : opt.getLanguage()) {
      if (it1.getChain()[0] == EMPTY && it2.getChain()[0] != EMPTY)
        result.setChain(it2);
      else if (it2.getChain()[0] == EMPTY && it1.getChain()[0] != EMPTY)
        result.setChain(it1);
      else if (it1.getChain()[0] != EMPTY && it2.getChain()[0] != EMPTY)
        result.setChain(it1 * it2);
    }
  }
  return result;
}

language language::join(language opt) {
  language result;
  for (auto it : getLanguage())
    result.setChain(it);
  for (auto it : opt.getLanguage())
    result.setChain(it);

  return result;
}

language language::intersection(language opt) {
  language result;  
  for (auto it1 : getLanguage()) {
    for (auto it2 : opt.getLanguage()) {
      if ((it1) == (it2)) {
        result.setChain(it1);
      }
    }
  }
  
  return result;
}

language language::difference(language opt) {
  language result;  
  bool find;
  for (auto it1 : opt.getLanguage()) {
    find = false;
    for (auto it2 : getLanguage()) {
      if ((it1) == (it2)) {
        find = true;
      }
    }
    if (!find)
      result.setChain(it1);
  }
  
  return result;
}

language language::reverse(void) {
  language result;
  for (auto it : this->getLanguage()) {
    chain newChain = it.reverseChain();
  std::cout << newChain << std::endl;

    result.setChain(newChain);
  }
  return result;
}

language language::potency(int exp) {
  language result = *this; 
  for (int i = 1; i < exp; i++) { 
    result = result + *this;
  }
  
  return result;
}

language language::operator+(const language& opt) {
  return this->concatenate(opt);
}

language language::operator|(const language& opt) {
  return this->join(opt);
}

language language::operator^(const language& opt) {
  return this->intersection(opt);
}

language language::operator-(const language& opt) {
  return this->difference(opt);
}

language language::operator*(const int& exp) {
  return this->potency(exp);
}

std::ostream& operator<<(std::ostream& os, const language& printLanguage) {
  for ( auto it : printLanguage.getLanguage()) os << it << SPACE;
  return os;
}