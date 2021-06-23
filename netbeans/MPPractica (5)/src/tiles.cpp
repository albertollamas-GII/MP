/**
 * @file movelist.cpp
 * @author DECSAI
 * @note To be implemented by students
 * @warning Complete the code
 *  */

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <cassert>
#include "wordlist.h"
#include "player.h"
#include "move.h"
#include "language.h"
#include "bag.h"
#include "movelist.h"
#include "tiles.h"

using namespace std;

Tiles::Tiles() {
    cell = nullptr;
    rows = 0;
    columns = 0;
}

Tiles::Tiles(int r, int c) {
    cell = nullptr;
    allocate(r, c);
}

Tiles::Tiles(const Tiles& orig) {
    cell = nullptr;
    copy(orig);
}

void Tiles::allocate(int r, int c) {
    if (cell != nullptr)
        deallocate();
    rows = r;
    columns = c;
    cell = new char*[r];
    for (int i = 0; i < r; i++)
        cell[i] = new char[c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cell[i][j] = EMPTY;
}

Tiles::~Tiles() {
    deallocate();
}

void Tiles::copy(const Tiles& t) {
    if (cell != nullptr)
        deallocate();
    rows = t.getHeight();
    columns = t.getWidth();

    char **copy = new char*[rows];
    for (int i = 0; i < rows; i++)
        copy[i] = new char[columns];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            copy[i][j] = t.get(i, j);
    cell = copy;
}

void Tiles::deallocate() {
    for (int i = 0; i < rows; i++) {
        if (cell[i] != nullptr) {
            delete[] cell[i];
            cell[i] = nullptr;
        }
    }
    delete[] cell;
    cell = nullptr;
    rows = 0;
    columns = 0;
}

Tiles& Tiles::operator=(const Tiles& orig) {
    if (this != &orig)
        copy(orig);

    return *this;
}

char Tiles::get(int r, int c) const {
    assert(r >= 0 && r < getHeight());
    assert(c >= 0 && c < getWidth());
    return cell[r][c];
}

int Tiles::getHeight() const {
    return rows;
}

int Tiles::getWidth() const {
    return columns;
}

void Tiles::print(std::ostream& os) const {
    os << getHeight() << " " << getWidth() << endl;
    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getWidth(); j++) {
            os << toUTF(get(i, j))<< " ";
        }
        os << endl;
    }
    os << endl;

}

void Tiles::add(const Move& m) {
    if (m.isHorizontal()) {
        for (int i = 0; i < m.getLetters().size(); i++) {
            if (m.getCol() + i - 1 >= 0 && m.getCol() + i - 1 < getWidth()) {
                if (m.getRow() - 1 >= 0 && m.getRow() - 1 < getHeight()) {
                    set(m.getRow() - 1, m.getCol() + i - 1, m.getLetters()[i]);
                }
            }
        }
    } else {
        for (int i = 0; i < m.getLetters().size(); i++) {
            if (m.getCol() - 1 >= 0 && m.getCol() - 1 < getWidth()) {
                if (m.getRow() + i - 1 >= 0 && m.getRow() + i - 1 < getHeight()) {
                    set(m.getRow() + i - 1, m.getCol() - 1, m.getLetters()[i]);
                }
            }
        }
    }
    
    //    if (!m.isHorizontal()) {
    //        int i = 0, j = 0;
    //        while (i < m.getLetters().size() && (j + m.getRow()) <= getHeight()) {
    //            if (get(m.getRow() + j, m.getCol()) == EMPTY) {
    //                set(m.getRow() + j - 1, m.getCol() - 1, m.getLetters()[i]);
    //                i++;
    //            }
    //            j++;
    //        }
    //    } else {
    //        int i = 0, j = 0;
    //        while (i < m.getLetters().size() && (j + m.getCol()) <= getWidth()) {
    //            if (get(m.getRow(), m.getCol() + j) == EMPTY) {
    //                set(m.getRow() - 1, m.getCol() + j - 1, m.getLetters()[i]);
    //                i++;
    //            }
    //            j++;
    //        }
    //    }
}

bool Tiles::read(std::istream& is) {
    int r = 0, c = 0;
    is >> r >> c;
    setSize(r, c);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            is >> cell[i][j];
            if (is.eof()) {
                return false;
            }
        }
    }
    return true;
}

void Tiles::set(int r, int c, char l) {
    assert(r >= 0 && r < getHeight());
    assert(c >= 0 && c < getWidth());
    cell[r][c] = l;
}

void Tiles::setSize(int r, int c) {
    deallocate();
    allocate(r, c);
}

Move Tiles::findMaxWord(int r, int c, bool hrz) const {
    Move maxmove;
    string Maxword = "";
    int columnaDer = c - 1, filaUp = r - 1, columnaIzq = c - 1, filaDown = r - 1;
    char character = '\0';
    int posicion_inicial = 0, posicion_final = 0, fila = r - 1, columna = c - 1;
    bool posicionLibre = false;
    assert(c - 1 >= 0 && c - 1 < getWidth());
    assert(r - 1 >= 0 && r - 1 < getHeight());

    if (hrz) {
        posicion_final = getWidth();
        columnaIzq = c - 1;
        columnaDer = c - 1;
        //miro hacia la izquierda para ver donde empezsar
        while (columnaIzq >= 0 && !posicionLibre) {
            character = get(fila, columnaIzq);
            if (character == EMPTY) {
                posicion_inicial = columnaIzq + 1;
                columnaIzq--;
                posicionLibre = true;
            } else if (columnaIzq==0){
                posicion_inicial=columnaIzq;
                posicionLibre=true;
            }else {
                posicionLibre = false;
                columnaIzq--;
            }
        }
        posicionLibre = false;
        //miro hacia la derecha para ver donde acabo
        while (columnaDer < getWidth() && !posicionLibre) {
            character = get(fila, columnaDer);
            if (character == EMPTY) {
                posicion_final = columnaDer - 1;
                columnaDer++;
                posicionLibre = true;
            }else if (columnaDer==getWidth()-1){
                posicion_final=columnaDer;
                posicionLibre=true;
            } else {
                posicionLibre = false;
                columnaDer++;
            }
        }


        for (int i = posicion_inicial; i <= posicion_final; i++) {
            Maxword.push_back(get(r - 1, i));
        }

        maxmove.set(r, posicion_inicial + 1, 'H', Maxword);
    } else {
        filaUp = r - 1;
        filaDown = r - 1;
        posicion_final = getHeight();
        //miro hacia arriba para ver donde empiezo 
        while (filaUp >= 0 && !posicionLibre) {
            character = get(filaUp, columna);
            if (character == EMPTY) {
                posicion_inicial = filaUp + 1;
                filaUp--;
                posicionLibre = true;
            } else if (filaUp==0){
                posicion_inicial=filaUp;
                posicionLibre=true;
            }else {
                posicionLibre = false;
                filaUp--;
            }
        }
        posicionLibre = false;
        //miro hacia abajo para ver donde acabo
        while (filaDown < getHeight() && !posicionLibre) {
            character = get(filaDown, columna);
            if (character == EMPTY) {
                posicion_final = filaDown - 1;
                filaDown++;
                posicionLibre = true;
            } else if (filaDown==getHeight()-1){
                posicion_final=filaDown;
                posicionLibre=true;
            }else {
                posicionLibre = false;
                filaDown++;
            }
        }



        for (int i = posicion_inicial; i <= posicion_final; i++) {
            Maxword.push_back(get(i, c - 1));
        }

        maxmove.set(posicion_inicial + 1, c, 'V', Maxword);
    }
    return maxmove;
}

Movelist Tiles::findCrosswords(const Move &m, const Language &l) const {
    Movelist crosswords;
    Move move, auxiliar;
    Tiles tiles(*this);
    char character = '\0';
    int fila = m.getRow() - 1, columna = m.getCol() - 1, j = fila, z = columna;
    bool ocupada = true, staysInside = true;

    //Comprobacion de que esta dentro de los límites
    if (fila >= getHeight() || columna >= getWidth() || fila < 0 || columna < 0) {
        move = m;
        move.setScore(BOARD_OVERFLOW);
        crosswords.add(move);
        return crosswords;
    }

    // Compruebo que la primera posicion no esta ocupada
    if (tiles.get(fila, columna) != EMPTY) {
        move = m;
        move.setScore(NOT_FREE);
        crosswords.add(move);
        return crosswords;
    }


    //Compruebo que se mete puede entrar el move
    if (m.isHorizontal()) {
        int j = columna;
        for (int pos_move = 0; pos_move < m.getLetters().size(); pos_move++) {
            while (j < getWidth() && get(fila, j) != EMPTY)
                j++;
            if (j < getWidth())
                tiles.set(fila, j, m.getLetters()[pos_move]);
            if (j >= getWidth() && pos_move < m.getLetters().size()) {
                move = m;
                move.setScore(BOARD_OVERFLOW);
                crosswords.add(move);
                return crosswords;
            }
            j++;
        }
    } else {
        int j = fila;
        for (int pos_move = 0; pos_move < m.getLetters().size(); pos_move++) {
            while (j < getHeight() && get(j, columna) != EMPTY)
                j++;
            if (j < getHeight())
                tiles.set(j, columna, m.getLetters()[pos_move]);
            else if (j >= getHeight() && pos_move < m.getLetters().size()) {
                move = m;
                move.setScore(BOARD_OVERFLOW);
                crosswords.add(move);
                return crosswords;
            }
            j++;
        }
    }
    //Hacemos una copia nueva del tiles para calcular los cruces
    tiles.copy(*this);
    //Procedemos a aniadir la palabra cuando exista un crossword
    if (m.isHorizontal()) {
        int z = columna;
        for (int i = 0; i < m.getLetters().size(); i++) {
            while (z < getWidth() && get(fila, z) != EMPTY)
                z++;

            tiles.set(fila, z, m.getLetters()[i]);
            move = tiles.findMaxWord(m.getRow(), z + 1, !m.isHorizontal()); //Tengo que ponerlo en posicion usuario para que findMaxWord funcione correctamente           
            if (move.getLetters().size() > 1) {
                move.setScore(move.findScore(l));
                if (move.getScore() < 0) {
                    move.setScore(NONEXISTENT_WORD);
                    crosswords.add(move);
                    return crosswords;
                } else
                    crosswords.add(move);

            }
            z++;
        }

        move = tiles.findMaxWord(m.getRow(), m.getCol(), m.isHorizontal());
        move.setScore(move.findScore(l));

//        if (move.getLetters().size() > 1) {
            if (move.getScore() < 0) {
                move.setScore(NONEXISTENT_WORD);
                crosswords.add(move);
                return crosswords;
            } else
                crosswords.add(move);

//        }


    } else {
        int z = fila;
        for (int i = 0; i < m.getLetters().size(); i++) {
            while (z < getWidth() && get(z, columna) != EMPTY)
                z++;

            tiles.set(z, columna, m.getLetters()[i]);
            move = tiles.findMaxWord(z + 1, m.getCol(), !m.isHorizontal()); //Tengo que ponerlo en posicion usuario para que findMaxWord funcione correctamente
            
            
            if (move.getLetters().size() > 1) {
                move.setScore(move.findScore(l));
                if (move.getScore() < 0) {
                    move.setScore(NONEXISTENT_WORD);
                    crosswords.add(move);
                    return crosswords;
                } else
                    crosswords.add(move);

            }
            z++;
        }

        move = tiles.findMaxWord(m.getRow(), m.getCol(), m.isHorizontal());
        move.setScore(move.findScore(l));

//        if (move.getLetters().size() > 1) {
            if (move.getScore() < 0) {
                move.setScore(NONEXISTENT_WORD);
                crosswords.add(move);
                return crosswords;
            } else
                crosswords.add(move);

//        }
    }

    return crosswords;


}

istream& operator>>(istream&is, Tiles & t) {
    t.read(is);
    return is;
}
