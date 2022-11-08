////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 6 - Simulación de Autómatas Finitos
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 8/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo manager.h: 
//   Fichero que contiene la declaración de la clase manager y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "automaton.h"

class manager {
  private:
    std::set<state> visitedStates; // Estados que fueron visitados
    std::set<state> actualStates; // Estados que se están evaluando
    automaton fa; // Autómata creado
    automaton fa2;
  public:
    manager(void);
    manager(char*, char*, int);
    ~manager(void);

    bool checkChains(chain, automaton);
};
