/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: alberto
 *
 * Created on 23 de mayo de 2020, 11:35
 */

#include <string>
#include <cassert>
#include <iostream>
#include <random>
#include <fstream>
#include <cmath>
#include "language.h"
#include "bag.h"
#include "player.h"
#include "move.h"
#include "movelist.h"
#include "tiles.h"
#include "window.h"
#include "AnsiTerminal.h"

using namespace std;

int main() {
    Bag bag;
    Language lang;
    Player player;
    Tiles tiles;
    Move move, move2;
    Movelist list;
    int a, b;
    int score;
    char auxi;

    ifstream file;
    file.open("data/ES_100_156.match");
    string aux;

    file >> aux;
    file >> score;
    file >> aux;
    lang.setLanguage(aux);
    file >> a >> b;
    tiles.setSize(a, b);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            file >> auxi;
            tiles.set(i, j, auxi);
        }
    }
    file >> a >> aux;
    player.add(toISO(aux));
    file >> a >> aux;
    bag.set(toISO(aux));
    while (true) {
        tiles.print(cout);
        cout << endl << player.size() << " " << toUTF(player.to_string());
        cout << endl << bag.size() << " " << toUTF(bag.to_string()) << endl;

        cin >> move;
        if (move.getLetters() == "@")
            return 0;
        cout << move << endl;
        move2 = tiles.findMaxWord(move.getRow(), move.getCol(), move.isHorizontal());
        cout << "salida findmax " << move2 << endl;

        list = tiles.findCrosswords(move, lang);

        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getScore() > 0) {
                Move moove = list.get(i);
                tiles.add(moove);
                cout << endl << " esto es  bucle " << moove;
            } else {
                cout << "error" << endl << list.get(i) << "          " << list.get(i).getScore() << endl;
            }
        }
    }

    return 0;

}

