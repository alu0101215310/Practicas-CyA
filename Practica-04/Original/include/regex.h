////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 4 - Expresiones regulares
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 25/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo regex.h: 
//    Fichero que contiene la declaración de la clase regex y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "variable.h"
#include "comment.h"
#include "loop.h"

const std::string VAREX = "[[:s:]]*(int|double)[[:s:]]+[[:w:]]+([[:s:]]*=[[:s:]]*[[:d:]]+)*[[:s:]]*;";
const std::string LOOPEX = "[[:s:]]*(for|while)[[:s:]]*[(].*[)][[:s:]]*[{]";
const std::string MAINEX = "int[[:s:]]main[[:s:]]*[(][[:print:]]*[)][[:s:]]*[{]"; 
const std::string COMMEX = "//[[:print:]]*";
const std::string COMMEXOP = "/[*][[:print:]]*";
const std::string COMMEXCL = "[[:print:]]*[*]/";

class regex {
  private:
    std::vector<variable> variables;
    std::vector<loop> loops;
    std::vector<comment> comments;
    bool mainEx;
    comment desc;

    std::ifstream inputFile;
    std::ofstream outputFile;

  public:
    regex(void);
    regex(char*,char*);
    ~regex(void);
  
    void build(void);
    void write(std::string);
};