////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 6 - Simulación de Autómatas Finitos
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 8/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo chain.h: 
//   Fichero que contiene la declaración de la clase chain y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "exception.h"

const char EMPTY = '&';
const char SPACE = ' ';

class chain {
  private:
    std::vector<char> symbols; // Elementos de la cadena en formato char

  public:
    chain(void);
    chain(std::string);
    ~chain(void);

    std::vector<char> getChain(void) const;
};

std::ostream& operator<<(std::ostream&, const chain&);