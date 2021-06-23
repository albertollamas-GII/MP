/**
 * @file bag.cpp
 * @author DECSAI
 * @note To be implemented by students except function shuffle()
 */
#include <cassert>
#include <random>
#include <algorithm>
#include "bag.h"
#include "language.h"
#include <vector>
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>

///@warning Fill missing #include

using namespace std;

/**
 * @brief Randomly reorders a vector of char
 * @param s Vector of char
 * @param n Number of char in the vector
 * @author DECSAI
 */
void shuffleVector(char *s, int n, int id);

/**
 * @brief Removes a position from a vector and compacts the remaining positions, 
 * thus reducing its size
 * @param s Vector of char
 * @param n Number of chars
 * @param p Position to remove
 * @warning TO BE FULLY IMPLEMENTED. 
 * @warning Check parameters const/&/* and their types
 */
void removeVector(char *s,int &n,int p);


// Main methods

Bag::Bag() {
    nletters = 0;
    id = time(NULL);
}

///@warning Implement all the methods

char Bag::get(int p) const{
    return letters[p];
}
void Bag::set(int p, char c){
    letters[p] = c;
}
void Bag::setRandom(int identifier){
    id=identifier;
}
/*
void Bag::define(const Language& lang){
    
    int numletters = 0;
    string SetOfLetters = lang.getLetterSet();
    
    for (int i=0; i < SetOfLetters.size();i++)
        set(i,SetOfLetters[i]);
    
    nletters=SetOfLetters.size();
    
    for(int i=0; i < nletters;i++){
        for(int j=0;j < lang.getFrequency(get(i));j++){
            SetOfLetters[numletters]=get(i);
            numletters++;
        }
    }
    for(int i = 0; i < numletters;i++)
        set(i,SetOfLetters[i]);
    nletters = numletters;
      
    shuffleVector(letters,nletters,id);
}*/
void Bag::define(const Language &l){
    ifstream ifile("build/bags.data");
    string mybag, mylang;
    int myrandom;
    bool found=false;

    if (!ifile) return;
    while (!ifile.eof() && !found) {
        ifile >> mylang >> myrandom >> mybag;
        if (ifile && mylang==l.getLanguage() && myrandom == this->id)
            found = true;
    }
    ifile.close();
    if (found)
        this->set(toISO(mybag));
    else
        this->set("");
}
int Bag::size() const{
    return nletters;
}
string Bag::to_string() const{
    string auxiliar = " ";
    auxiliar.resize(nletters);
    for (int i=0; i < nletters; i++)
        auxiliar[i]=get(i);
    return auxiliar;
}
void Bag::set(const std::string& s){
    for(int i=0; i < s.length();i++)
        letters[i]=s[i];
    nletters = s.length();
}
string Bag::extract(int n){
    int number = n;
    string FirstNLetters = "";
    if (number > nletters)
        number=nletters;
   
    for (int i=0; i < number;i++)
        FirstNLetters.push_back(get(i));
    for (int j=0; j <number;j++)
        removeVector(letters,nletters,0);
    return FirstNLetters;
    
}

// Auxiliary functions 

void shuffleVector(char *s, int n, int id) {
    vector <char> aux(s, s+n);
    unsigned seed = id;
    std::shuffle(aux.begin(), aux.end(), std::default_random_engine(seed));
    for (int i=0; i<n; i++)
        s[i] = aux[i];    
}
void removeVector(char *s,int &n,int p){
    for (int i=p;i<n-1;i++)
        s[i]=s[i+1];
    
    n--;
}

