/**
 * @file move.cpp
 * @author DECSAI
 * @note To be implemented by students
 */
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include "player.h"
#include "move.h"
#include "language.h"

using namespace std;

Move::Move(){
    row=0;
    column=0;
    ishorizontal=true;
    letters="";
    score=0;
}
void Move::set(int r, int c, char h, const std::string& l){
    setRow(r);
    setCol(c);
    setHorizontal(h);
    setLetters(l);
}
void Move::setCol(int c){
    if (c >= 0)
        column=c;        
}
void Move::setRow(int r){
    if (r >= 0)
        row=r;
}
void Move::setHorizontal(char h){
    if (h=='h'||h=='H')
        ishorizontal=true;
    else if (h=='v'||h=='V')
        ishorizontal=false;
}
void Move::setLetters(const std::string& l){
    letters=l;
}
int Move::getCol() const{
    return column;
}
int Move::getRow() const{
    return row;
}
void Move::setScore(int s){
    score=s;
}
int Move::getScore() const{
    return score;
}
bool Move::isHorizontal() const{
    return ishorizontal;
}
string Move::getLetters() const{
    return letters;
}
int Move::findScore(const Language& l) const{
    int sco=0;
    if (l.query(letters)){
        for(int i=0; i < letters.length();i++){
            sco+=l.getScore(letters[i]);
        }
    }
    else
        sco=-1;
    
    return sco;
}
void Move::print(std::ostream& os) const{
    os << (ishorizontal? 'H':'V')<< " " << row << " " << column << " " << toUTF(letters);
}
void Move::read(std::istream& is){
    char h;
    int r,c;
    string l;
    is >> h;
    is >> r;
    is >> c;
    is >> l;
    set(r,c,h,normalizeWord(l));
}
std::istream& operator>>(std::istream& is, Move & m){
    m.read(is);
    return is;
}
std::ostream& operator<<(std::ostream& os, const Move & m){
    m.print(os);
    return os;
}