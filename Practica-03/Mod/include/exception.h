////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 2 - Operaciones con lenguajes
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo exception.h: 
//    Fichero que contiene las diferentes excepciones que puede da el programa
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <exception>
#include <stack>

class fileError : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "ERROR! Han habido errores con un fichero!";
    }
};

class sintaxError : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "ERROR! Han habido errores de sintaxis!";
    }
};

class operandError : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "ERROR! Han habido errores de sintaxis!";
    }
};
