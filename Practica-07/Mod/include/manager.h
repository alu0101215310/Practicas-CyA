////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 7 - Gramática Regular a partir de un DFA
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 15/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo manager.h: 
//   Fichero que contiene la declaración de la clase manager y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "automaton.h"

class manager {
  private:
    automaton fa; // Autómata creado
    grammar gra;
  public:
    manager(void);
    manager(char*, char*);
    ~manager(void);

    void write(char*);
};
