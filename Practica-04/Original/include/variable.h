////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 4 - Expresiones regulares
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 25/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo variable.h: 
//    Fichero que contiene la declaración de la clase variable y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "exception.h"

class variable {
  private:
    std::string type;
    std::string name;
    int pos;
    double var;

  public:
    variable(void);
    variable(std::string,int);
    ~variable(void);
  
    std::string getType(void) const;
    std::string getName(void) const;
    int getPos(void) const;
    double getVar(void) const;

};

std::ostream& operator<<(std::ostream&, const variable&);
