#Compilador de C++
CXX=g++

#Flasgs del compilador de C++
CXXFLAGS=-g

#Comando para eliminar archivos en el clean
RM=rm -rf

#Archivos cpp
SRC=main.cpp operation.cpp chain.cpp alphabet.cpp

#Directorio de los ejecutables
BIN=bin

EXT=./

#Objetos
OBJS=$(SRC:.cpp=.o)

all: program

#Compila el programa
program: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(BIN)/program

#Crea el objeto main.o
main.o: main.cc operation.o

#Crea el objeto operation.o
operation.o: operation.cc operation.h alphabet.o

#Crea el objeto alphabet.o
alphabet.o: alphabet.cc alphabet.h chain.o

#Crea el objeto cadena.o
chain.o: chain.cc chain.h

#Elimina los ejecutables y los objetos creados
clean:
	@echo "Limpiando todo..." 
	$(RM) $(BIN)/* *.o;