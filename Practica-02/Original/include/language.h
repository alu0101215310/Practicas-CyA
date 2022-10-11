////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 2 - Operaciones con lenguajes
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
    std::set<chain> chains;
    alphabet symbols;

  public:
    language(void);
    language(std::string);
    ~language(void);

    std::set<chain> getLanguage(void) const;
    alphabet getAlphabet(void) const;

    void setChain(chain);

    language concatenate(language, language); 
    language join(language, language); 
    language intersection(language, language); 
    language difference(language, language); 
    language reverse(language); 
    language potency(language, int); 

    language operator*(const language&) const;
    language operator+(const language&) const;
    language operator/(const language&) const;
    language operator-(const language&) const;
};  

language operator^(const language&, int&);
std::ostream& operator<<(std::ostream&, const language&);
