////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 3 - Calculadora de lenguajes formales
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo alphabet.h: 
//    Fichero que contiene la declaración de la clase alphabet y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "chain.h"

class alphabet {
  private:
    std::set<char> symbols; // Conjuntos de símbolos de un alfabeto

  public:
    alphabet(void);
    alphabet(std::string);
    alphabet(std::set<chain>);
    ~alphabet(void);

    std::set<char> getAlphabet(void) const;
};

std::ostream& operator<<(std::ostream&, const alphabet&);
