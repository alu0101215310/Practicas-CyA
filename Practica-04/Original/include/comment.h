////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 4 - Expresiones regulares
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 25/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo comment.h: 
//    Fichero que contiene la declaración de la clase comment y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "exception.h"

class comment {
  private:
    int firstPos;
    int lastPos;
    std::vector<std::string> var;

  public:
    comment(void);
    comment(std::string,int);
    ~comment(void);

    void addLine(std::string);
    void addLastPos(int);

    int getFirstPos(void) const;
    int getLastPos(void) const;
    std::vector<std::string> getVar(void) const;
};

std::ostream& operator<<(std::ostream&, const comment&);
