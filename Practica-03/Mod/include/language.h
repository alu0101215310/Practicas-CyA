////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 3 - Calculadora de lenguajes formales
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo language.h: 
//    Fichero que contiene las definición de la clase language y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "alphabet.h"

class language {
  private:
    std::string name;
    std::set<chain> chains;
    alphabet symbols;

  public:
    language(void);
    language(std::string);
    ~language(void);

    std::string getName(void) const;
    std::set<chain> getLanguage(void) const;
    alphabet getAlphabet(void) const;

    void setChain(chain);

    language concatenate(language); 
    language join(language); 
    language intersection(language); 
    language difference(language); 
    language reverse(void); 
    language potency(int); 

    language operator+(const language&);
    language operator|(const language&);
    language operator^(const language&);
    language operator-(const language&);
    language operator/(const language&);
    language operator*(const int&);
};  

std::ostream& operator<<(std::ostream&, const language&);
