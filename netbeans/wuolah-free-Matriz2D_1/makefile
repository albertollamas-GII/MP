HOME = .
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
SRC = $(HOME)/src
LIB = $(HOME)/lib

############################################################################
############################################################################
############################################################################

all : $(BIN)/Demo-Matriz2D_1 $(LIB)/libMatriz2D_1.a 

############################################################################

$(BIN)/Demo-Matriz2D_1 : $(OBJ)/Demo-Matriz2D_1.o $(LIB)/libMatriz2D_1.a
	g++ -o $@ $^ -L$(LIB) -lMatriz2D_1 -std=c++11

$(OBJ)/Demo-Matriz2D_1.o : $(SRC)/VI_Demo-Matriz-Es.cpp $(INCLUDE)/Matriz2D_1.h
	g++ -c -o $@ $< -I$(INCLUDE) -std=c++11

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp $(INCLUDE)/Matriz2D_1.h
	g++ -c -o $@ $< -I$(INCLUDE) -std=c++11

$(LIB)/libMatriz2D_1.a : $(OBJ)/Matriz2D_1.o
	ar -rvs $@ $^
