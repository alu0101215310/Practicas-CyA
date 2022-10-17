////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 2 - Operaciones con lenguajes
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo chain.h: 
//    Fichero que contiene la declaración de la clase cadena y sus métodos,
//    además de las librerías del proyecto
////////////////////////////////////////////////////////////////////////////////

#include "exception.h"

const char EQUAL = '=';
const char EMPTY = '&';
const char SPACE = ' ';
const char COME = ',';
const char OPEN = '{';
const char CLOSE = '}';
const std::string BOTH = "{}";

class chain {
  private:
    std::vector<char> symbols; // Elementos de la cadena en formato char

  public:
    chain(void);
    chain(std::vector<char>);
    chain(std::string newChain);
    ~chain(void);

    std::vector<char> getChain(void) const;

    bool operator<(const chain&) const;
    bool operator==(const chain&) const;
    chain operator*(const chain&) const;

    chain reverseChain(void);
};

std::ostream& operator<<(std::ostream&, const chain&);
