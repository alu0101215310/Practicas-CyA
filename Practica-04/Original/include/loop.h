////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 4 - Expresiones regulares
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 25/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo loop.h: 
//    Fichero que contiene la declaración de la clase lopp y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "exception.h"

class loop {
  private:
    std::string type;
    int pos;

  public:
    loop(void);
    loop(std::string,int);
    ~loop(void);

    std::string getType(void) const;
    int getPos(void) const;  
};

std::ostream& operator<<(std::ostream&, const loop&);
