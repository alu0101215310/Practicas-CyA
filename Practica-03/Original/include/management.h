////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 2 - Operaciones con lenguajes
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo operation.h: 
//    Fichero que contiene la declaración de la clase operation y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "language.h"

// Representa una calculadora que se hará cargo del análisis
// y representación de los datos pasados al programa
class management{
  private:
    std::ifstream inputFile; // Fichero de entrada
    std::vector<language> languagesFile; // Conjunto de cadenas

  public:
    management(void);
    management(char*);
    ~management(void);

    void init(char*);
    void algorithm(std::string); 
    bool checkOperand(std::string);
    language findLanguage(std::string);
    void write(std::string, language);
};