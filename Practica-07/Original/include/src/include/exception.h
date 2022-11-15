////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 6 - Simulación de Autómatas Finitos
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 8/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo exception.h: 
//   Fichero que contiene la declaración de la clase execption y sus métodos
//   además de las librerías a usar en el proyecto
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <exception>

#pragma once

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