////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 4 - Expresiones regulares
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 25/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo exception.h: 
//    Fichero que contiene las diferentes excepciones que puede da el programa
//    junto a las librerias y diferentes tipos de variables
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <exception>
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

const char SPACE = ' ';
const char EQUAL = '=';
const char DOTCHCOME = ';';
const char OPEN = '(';

const std::string INT = "int";
const std::string DOUBLE = "double";

#pragma once

class fileError : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "ERROR! Han habido errores con un fichero!";
    }
};