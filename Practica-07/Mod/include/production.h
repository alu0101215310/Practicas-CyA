////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 7 - Gramática Regular a partir de un DFA
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 15/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo production.h: 
//   Fichero que contiene la declaración de la clase production y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "alphabet.h"

class production {
  private:
    std::map<std::string, std::string> pr;

  public:
    production(void);
    production(std::string, std::string);
    ~production(void);

    void update(std::string, std::string);

    std::map<std::string, std::string> getProduction(void) const;
};

std::ostream& operator<<(std::ostream&, production&);