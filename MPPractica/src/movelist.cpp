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
#include "player.h"
#include "move.h"
#include "language.h"
#include "bag.h"
#include "movelist.h"
using namespace std;

Movelist::Movelist(){    
    moves=nullptr;
    nMove=0;
}
Movelist::Movelist(const Movelist& orig) {
    moves = nullptr;
    nMove = 0;
    copy(orig);
}

Movelist::~Movelist() {
    moves=nullptr;
    deallocate();
}
Movelist::Movelist(int nmov){     
    moves=nullptr;
    nMove=0;
    allocate(nmov);
}


Movelist& Movelist::operator=(const Movelist& orig) {
    if (this != &orig)
        copy(orig);

    return *this;
}
Move Movelist::get(int p) const{
    assert(p>=0 && p < size());
    return moves[p];
}

int Movelist::find(const Move& mov) const{
    int posicion=-1;
    
    for(int i=0;i<size();i++){
        if (get(i).getCol()==mov.getCol() && get(i).getRow()==mov.getRow()){
            if(get(i).getLetters()==mov.getLetters() && get(i).getScore()==mov.getScore()){
                posicion=i;
            }
        }
    }
    return posicion;
}

void Movelist::set(int p, const Move& m){
    assert(p >= 0 && p < size());
    moves[p]=m;
}

void Movelist::add(const Move& mov){    
    newDimension(+1);
    set(size()-1, mov);
}
void Movelist::remove(const Move& mov){
    int pos=find(mov);
    if(pos!=-1)
        remove(pos);
}
void Movelist::remove(int p){
    assert(p<size()&& p>=0);
    int position=p;
    
    for(int i=position; i < nMove-1; i++)
        set(i,get(i+1));
    newDimension(-1);
}
void Movelist:: zip(const Language& l){
    int i=0;
    while (i<size()){
        if(get(i).getLetters().length()<2 || !(l.query(get(i).getLetters())))
            remove(i);
        else
            i++;
    }
}
void Movelist::clear(){
    deallocate();
    moves=nullptr;
    nMove=0;
}
int Movelist::getScore()const{
    int sum=0, score=0;
    for(int i=0; i <size();i++){
        score=get(i).getScore();
        if(score==-1)
            return -1;
        else
            sum+=score;
    }
    return sum;
}
bool Movelist::read(std::istream &is){
    Move mov;
    char h;
    int r=0,c=0;
    string l="";
    bool res=true;
    
    do{
        is>>h>>r>>c>>l;
        if (is.eof()||(!is))
            res=false;
        else if (l!="@"){
            l=normalizeWord(l);
            mov.set(r,c,h,l);
            add(mov);
        }        
    }while(l!="@"&&res);
    return res;
    
}
void Movelist::allocate(int n){
    if(moves!=nullptr)
        deallocate();
    moves=new Move[n];
    nMove=n;
}
void Movelist::deallocate(){
    if (moves!=nullptr)
        delete[] moves;
    moves=nullptr;
    nMove=0;
}

void Movelist::copy(const Movelist& ml){
    if (moves!= nullptr)
        deallocate();
    nMove=ml.size();
    allocate(nMove);
    for (int i=0; i < nMove;i++)
        set(i,ml.get(i));
            
}

void Movelist::newDimension(int tam){
    int sice=size();
    int final_size=sice+tam;
    if(final_size>0){
        Move* temp=new Move[final_size];
        
        for(int i=0;(i<sice)&&(i<final_size);i++)
            temp[i]=get(i);
        
        deallocate();
        moves=temp;
        nMove=final_size;
    }
    else if ((final_size)==0){
        deallocate();
        moves=nullptr;
        nMove=0;
    }
    
}

bool Movelist::print(std::ostream &os,bool scores) const{
    
    bool res=true;
    for (int i=0; i<size() && res; i++) {
        get(i).print(os);
        if (scores)
            os << " ("<<get(i).getScore()<<") - ";
        else
            os << " - ";
        if (os.bad())
            res=false;
    }
    return res;
}
std::istream & operator>>(std::istream & is, Movelist & i){
    i.read(is);
    return is;
}
std::ostream & operator<<(std::ostream & os,const Movelist & i){
    i.print(os);
    return os;    
}

