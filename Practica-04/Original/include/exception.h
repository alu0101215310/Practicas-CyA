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

#pragma once

class fileError : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "ERROR! Han habido errores con un fichero!";
    }
};