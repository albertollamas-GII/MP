/**
 * @file main.cpp
 * @author DECSAI
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
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


#define ERROR_ARGUMENTS 1
#define ERROR_OPEN 2
#define ERROR_DATA 3
#define GENERAL_ERROR 4
#define PASSWORD "MPALABRADOS-V1"


/**
 * @brief Reports an important error and exits the program
 * @param errorcode An integer representing the error detected, which is represented
 * by several symbolic constants: ERROR_ARGUMENTS, ERROR_OPEN y ERROR_DATA
 * @param errorinfo Additional information regarding the error: "" (empty string) for 
 * errors parsing the arguments to main() and, for the case of errors opening or 
 * reading/writing data, the name of the file thas has failed.
 */
void errorBreak(int errorcode, const string & errorinfo);
istream & operator>>(istream & is, Game & game);
ostream & operator<<(ostream & os, const Game & game);

/**
 * @brief Main function. 
 * @return 
 */
int main(int nargs, char * args[]) {
    Move move;
    Game game;
    int w = -1, h = -1, wait = 0, rand = 0, score = 0, fila = 0, columna = 0, pos_move = 0;
    string lang, ifilematch, ofilematch, word, open, open2;
    ifstream ifile;
    ofstream ofile;
    bool end = false;
    char c;
    bool lang_param = false, random_param = false, width_param = false, height_param = false, save_param = false;
    bool open_param = false, goodScore = true;
    /// Check arguments
    if (nargs > 11 || nargs % 2 == 0)
        errorBreak(ERROR_ARGUMENTS, "Invalid number of arguments");
    open = args[1];
    if ("-open" == open) {
        if (nargs < 2) {
            errorBreak(ERROR_ARGUMENTS, "open param");
        } else
            open_param = true;
    }

    for (int i = 0; i < nargs; i++) {
        string arg = args[i];
        if (arg == "-l") {
            lang = args[i + 1];
            lang_param = true;
            i++;
        }
        if (arg == "-w") {
            width_param = true;
            w = atoi(args[i + 1]);
            i++;
        }
        if (arg == "-h") {
            height_param = true;
            h = atoi(args[i + 1]);
            i++;
        }

        if (arg == "-r") {
            random_param = true;
            rand = atoi(args[i + 1]);
            game.random = atoi(args[i + 1]);
            i++;
        }
        if (arg == "-save") {
            save_param = true;
            ofilematch = args[i + 1];
            if (ofile.fail())
                errorBreak(ERROR_OPEN, args[i + 1]);
            i++;
        }
        if (arg == "-open") {
            ifilematch = args[i + 1];
            if (ifile.fail())
                errorBreak(ERROR_OPEN, args[i + 1]);
            i++;
        }
    }

    if (open_param && (lang_param || height_param || width_param))
        errorBreak(ERROR_ARGUMENTS, "");
    if ((!lang_param || !height_param || !width_param) && !open_param)
        errorBreak(ERROR_ARGUMENTS, "Missing arguments");
    // Process arguments

    /// load data from file, if asked to in arguments

    if (open_param) {
        ifile.open(ifilematch);
        if (ifile.fail()) {
            errorBreak(ERROR_OPEN, ifilematch);
        }
        ifile >> game;
        if (ifile.eof())
            errorBreak(ERROR_DATA, ifilematch);
        ifile.close();
    } else {
        game.language.setLanguage(lang);
        if (random_param)
            game.bag.setRandom(game.random);
        game.bag.define(game.language);
        game.player.add(toISO(game.bag.extract(MAXPLAYER)));
        game.tiles.setSize(h, w);
        game.score = 0;
    }

    // Game's main loop 
    // 1) First set the size of the window according to the size (rows & columns) of
    // the new Tiles

    game.setWindowSize();
    game.doPaint();
    game.wait = wait;

    while (!end) {
        
        // 2) Given the inner data members, it pretty-prints the screen
        game.doPaint();
        setCursorOn();
        // 3) Reads the movement from cin
        cin >> move;
        //        cout << endl << toUTF(move.getLetters()) << endl;
        setCursorOff;
        word = normalizeWord(move.getLetters());
        goodScore=true;
        if (word == "_") {
            end = true;
        }            // Checks whether the movement is valid accoring to the letters in player
        else if (game.player.isValid(word)) {
            if (game.acceptedmovements.size() == 0 && game.score == 0) {
                if (move.isHorizontal() && ((move.getCol() - 1 + move.getLetters().size() - 1) >= game.tiles.getWidth())) {
                    move.setScore(BOARD_OVERFLOW);
                    game.rejectedmovements.add(move);
                } else if (!move.isHorizontal() && ((move.getRow() - 1 + move.getLetters().size() - 1) >= game.tiles.getHeight())) {
                    move.setScore(BOARD_OVERFLOW);
                    game.rejectedmovements.add(move);
                } else {
                    move.setScore((move.findScore(game.language)));
                    if (move.getScore()<0){
                         move.setScore(NONEXISTENT_WORD);
                         game.rejectedmovements.add(move);
                    }             
                    
                }
                game.crosswords.add(move);
            } else {
                // Finds all the crosswords produced by move and inform about the reasons of rejection
                game.crosswords = game.tiles.findCrosswords(move, game.language);
            }
            for (int x = 0; x < game.crosswords.size(); x++) {
                if (game.crosswords.get(x).getScore() < 0)
                    goodScore = false;
            }

            // ^^^Checks that the crosswords are valid, that is either has a positive score
            //      or produces at least a cross with other existin letters
            if (goodScore) {
                // Once a valid move is detected, the user is asked to confirm
                // call doConfirmCrosswords()
                //    the movement. If he/she does (by pressing Y o y) then the movement
                //     is inserted in tiles and its score is calculated,
                //     otherwise, the move is just ignored
                if (game.doConfirmCrosswords("Accept movement? [Y/N]")) {
                    game.player.extract(toISO(word));
                    game.player.add(game.bag.extract(word.size()));
                    move.setScore(game.crosswords.getScore());
                    game.acceptedmovements.add(move);
                    fila = move.getRow() - 1;
                    columna = move.getCol() - 1;
                    if (!move.isHorizontal()) {
                        pos_move = 0;
                        int i = fila;
                        while (pos_move < move.getLetters().size()) {

                            while (i < game.tiles.getHeight() && game.tiles.get(i, columna) != EMPTY) {
                                i++;
                            }
                            if (i < game.tiles.getHeight())
                                game.tiles.set(i, columna, move.getLetters()[pos_move]);
                            pos_move++;
                            i++;
                        }
                    } else {
                        pos_move = 0;
                        int j = columna;
                        while (pos_move < move.getLetters().size()) {
                            while (j < game.tiles.getWidth() && game.tiles.get(fila, j) != EMPTY) {
                                j++;
                            }
                            if (j < game.tiles.getWidth())
                                game.tiles.set(fila, j, move.getLetters()[pos_move]);
                            pos_move++;
                            j++;
                        }
                    }
                }
                // If valid and accepted, computes the score and adds it
                game.score += move.getScore();
            } else {

                if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == BOARD_OVERFLOW) {
                    game.doBadCrosswords("BOARD OVERFLOW");
                    move.setScore(BOARD_OVERFLOW);
                    game.rejectedmovements.add(move);
                } else if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == NOT_FREE) {
                    game.doBadCrosswords("NOT FREE");
                    move.setScore(NOT_FREE);
                    game.rejectedmovements.add(move);
                } else if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == NONEXISTENT_WORD) {
                    game.doBadCrosswords("NONEXISTENT WORD");
                    move.setScore(NONEXISTENT_WORD);
                    game.rejectedmovements.add(move);
                } else if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == MISSING_CROSSWORDS) {
                    game.doBadCrosswords("MISSING CROSSWORDS");
                    move.setScore(MISSING_CROSSWORDS);
                    game.rejectedmovements.add(move);
                } else {
                    game.doBadCrosswords("Wrong crossword found");
                    game.rejectedmovements.add(move);
                }
            }
        } else {
            game.doBadCrosswords("INEFASIBLE WORD");
            //            game.crosswords.clear();
            game.crosswords.add(move);
            move.setScore(INFEASIBLE_WORD);
            game.rejectedmovements.add(move);
        }
        game.crosswords.clear();

    }


    // Show crosswords found
    // If it is a bad crosswords

    // call doBadCrosswords()

    // If not valid w.r.t. player

    // call doBadCrosswords()



    // End of game
    // Save file or print screen

    if (save_param) {
        ofile.open(ofilematch);
        ofile << PASSWORD << endl;
        ofile << game;
        if (!ofile) {
            errorBreak(ERROR_DATA, ofilematch);
        }
        ofile.close();
    } else {

        cout << endl << "%%%OUTPUT" << endl;
        cout << game;
    }


    return 0;
}

ostream & operator<<(ostream & os, const Game & game) {
    // To implement
    os << game.score << endl << game.language.getLanguage() << endl;
    game.tiles.print(os);
    os << game.player.size() << " " << toUTF(game.player.to_string()) << endl;
    os << game.bag.size() << " " << toUTF(game.bag.to_string()) << endl;

    return os;
}

istream & operator>>(istream & is, Game & game) {
    // To implement
    string palabraMagica, lang, noUsar, playing, bagg;

    int hu;
    is >> palabraMagica;
    if (palabraMagica != PASSWORD) {
        errorBreak(ERROR_DATA, "");
    }
    is >> game.score >> lang;
    if (is.eof())
        return is;
    game.language.setLanguage(lang);
    is >> game.tiles;
    is >> noUsar;
    is >> playing;
    if (is.eof())
        return is;
    game.player.add(toISO(playing));
    is >> noUsar >> bagg;
    if (is.eof())
        return is;
    game.bag.set(toISO(bagg));

    return is;



}

void errorBreak(int errorcode, const string & errordata) {
    cerr << endl << "%%%OUTPUT" << endl;
    switch (errorcode) {
        case ERROR_ARGUMENTS:
            cerr << "Error in call. Please use either:" << endl;
            cerr << "-l <language> -w <width> -h <height> [-r <randomnumber> -save <matchfile>]" << endl;
            cerr << "-open <matchfile> [-save <matchfile>]" << endl;
            break;
        case ERROR_OPEN:
            cerr << "Error opening file " << errordata << endl;
            break;
        case ERROR_DATA:
            cerr << "Data error in file " << errordata << endl;
            break;
        case GENERAL_ERROR:
            cerr << "Error: " << errordata << endl;
            break;
    }
    std::exit(1);
}

