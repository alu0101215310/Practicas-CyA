////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 7 - Gramática Regular a partir de un DFA
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 15/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo grammar.h: 
//   Fichero que contiene la declaración de la clase grammar y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "production.h"

class grammar {
  private:
    alphabet symbols;
    std::set<std::string> nts; // Conjunto de símbolos no terminales
    std::map<std::string, production> productions;

  public:
    grammar(void);
    ~grammar(void);

    alphabet getAlphabet(void) const;
    std::set<std::string> getNTS(void) const;
    std::map<std::string, production> getProductions(void) const;

    void setAlphabet(alphabet);
    void addProduction(std::string, std::string, std::string);
    void addNT(std::string);

    void change(void);
    bool isRegular(void);
};