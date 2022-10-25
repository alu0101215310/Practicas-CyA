////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 4 - Expresiones regulares
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 25/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo comment.cc: 
//    Fichero que contiene las definición de la clase comment y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "../include/comment.h"

comment::comment (void) {};

comment::comment (std::string rawComment, int line) {
  firstPos = line;
  var.push_back(rawComment);
};

comment::~comment (void) {};

void comment::addLine (std::string newComment) {
  var.push_back(newComment);
}

void comment::addLastPos (int end) {
  lastPos = end;
}

int comment::getFirstPos(void) const { return firstPos; }

int comment::getLastPos(void) const { return lastPos; }

std::vector<std::string> comment::getVar (void) const { return var; }

std::ostream& operator<<(std::ostream& os, const comment& printComment) {
  if (printComment.getVar().size() == 1)
    os << "[ Line " << printComment.getFirstPos() << " ] " << printComment.getVar()[0];
  else if (printComment.getLastPos() != 0)
    os << "[ Line " << printComment.getFirstPos() << " - " << printComment.getLastPos() << " ] " << "DESCRIPTION";

  return os;
}
