////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 1 - Símbolos, alfabetos y cadenas
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 03/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo chain.h: 
//    Fichero que contiene la declaración de la clase cadena y sus métodos,
//    además de las librerías del proyecto
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <sstream>

class chain {
  private:
    std::vector<char> info; // Elementos de la cadena en formato char

  public:
    chain(std::string newInfo);
    ~chain();

    std::vector<char> getChain();
};
