////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 2 - Operaciones con lenguajes
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
  std::string rawAlphabet;
  std::string rawChains;
  std::string rawChain;

  std::stringstream newLanguage(rawLanguage);
  getline(newLanguage, rawAlphabet, CLOSE);
    alphabet newAlphabet(rawAlphabet);
    symbols = newAlphabet;
  
  getline(newLanguage, rawChains, CLOSE);
    std::stringstream newChains(rawChains);
    while (getline(newChains, rawChain, SPACE)) {
      if (*rawChain.c_str() != OPEN) {
        chain newChain(rawChain);
        setChain(newChain);
      }
    }
}

// Destructor
language::~language(void) {}

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

language language::concatenate(language firstLanguage, language secondLanguage) {
  language result = firstLanguage * secondLanguage;
  return result;
}

language language::join(language firstLanguage, language secondLanguage) {
  language result = firstLanguage + secondLanguage;
  return result;
}

language language::intersection(language firstLanguage, language secondLanguage) {
  language result = firstLanguage / secondLanguage;
  return result;
}

language language::difference(language firstLanguage, language secondLanguage) {
  language result = firstLanguage - secondLanguage;
  return result;
}

language language::reverse(language optLanguage) {
  language result;
  for (auto it : optLanguage.getLanguage()) {
    chain newChain = it.reverseChain();
  std::cout << newChain << std::endl;

    result.setChain(newChain);
  }
  return result;
}

language language::potency(language optLanguage, int exp) {
  language result = optLanguage;
  for (int i = 1; i < exp; i++)
    result = result * optLanguage;

  return result;
}

language language::operator*(const language& opt) const {
  language result;  
  for (auto it1 : getLanguage()) {
    for (auto it2 : opt.getLanguage()) {
      if (!it1.getChain().empty() && !it2.getChain().empty())
        result.setChain(it1 * it2);
    }
  }
  return result;
}

language language::operator+(const language& opt) const {
  language result;
  for (auto it : getLanguage())
    result.setChain(it);
  for (auto it : opt.getLanguage())
    result.setChain(it);

  return result;
}

language language::operator/(const language& opt) const {
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

language language::operator-(const language& opt) const {
  language result;  
  bool find;
  for (auto it1 : getLanguage()) {
    find = false;
    for (auto it2 : opt.getLanguage()) {
      if ((it1) == (it2)) {
        find = true;
      }
    }
    if (!find)
      result.setChain(it1);
  }
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

language operator^(const language& optLanguage, const int& exp) {
  language result = optLanguage; 
  for (int i = 1; i < exp; i++) { 
    result = result * optLanguage;
  }
  
  return result;
}

std::ostream& operator<<(std::ostream& os, const language& printLanguage) {
  for ( auto it : printLanguage.getLanguage()) os << it << " ";
  return os;
}