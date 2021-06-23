/**
 * @file player.cpp
 * @author DECSAI
 * @note To be implemented by students
 */

#include <cassert>
#include <random>
#include <algorithm>
#include "bag.h"
#include "language.h"
#include "player.h"
#include "wordlist.h"
#include <vector>
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>


///@warning complete missing #includes
/// See http://www.cplusplus.com/reference/cstring/ for details about cstrings
using namespace std;

/**
 * @brief Removes a position from a cstring
 * @param cstr The cstring
 * @param pos The position
 * @return The cstring is modified
 * @warning To be fully implemented
 */
void removeCString(char *cstr, int pos);

/**
 * @brief Sort a cstring from A to Z
 * @param cstr The cstring
 * @return The cstring is modified
 * @warning To be fully implemented
 */
void sortCString(char *cstr);

//Main methods


Player::Player() {
    clear();
}

int Player::size() const {
    return strlen(letters);
}


string Player::to_string() const {
    string str = letters;
    return str;
}


void Player::clear() {
    letters[0]='\0';
}


bool Player::isValid(const string s) const {
//    bool isValid=true;
//    bool used[7]={0};
//    
//    for(int i=0; i < s.length()&&isValid;i++){
//        bool existe=false;
//        for(int j=0; j < size()&&!existe;j++){
//            if(used[j]!=1 && letters[j]==s[i]){
//                existe=true;
//                used[j]=1;
//            }
//        }
//        if(!existe)
//            isValid=false;
//    }
    bool valido=true;
    int comp1=0,comp2=0;
    char cstring1[MAXPLAYER+1];
    char cstring2[MAXPLAYER+1];
    
    strcpy(cstring1, s.c_str());
    strcpy(cstring2, letters);
    
    sortCString(cstring1);
    sortCString(cstring2);
    
    if(strlen(cstring1)>=1){
        if(strlen(cstring1)<= strlen(cstring2)){
            while(comp1<=strlen(cstring1) && comp2 <= strlen(cstring2)){
                if(cstring1[comp1]==cstring2[comp2]){
                    comp1++;
                    comp2++;
                }
                else
                    comp2++;
            }
            if(comp2>strlen(cstring2)&&comp1<=strlen(cstring1))
                valido=false;
        }
        else
            valido=false;
    }
    else
        valido=false;
    
    return valido;
    
}


bool Player::extract(const string s){
    bool condition = true;
    if(isValid(s)){
        char auxiliar[MAXPLAYER+1];
        strcpy(auxiliar, s.c_str());
        for (int i=0; i<strlen(auxiliar); i++){
            for (int j=0; j<size()&& condition; j++){
                if(letters[j]==auxiliar[i]){
                    removeCString(letters,j);
                    condition = false;
                }
            }
            condition = true;
        }
    }
    sortCString(letters);
    return isValid(s);
}


void Player::add(string frombag){
   
    if(strlen(frombag.c_str())<=(MAXPLAYER-size())){
        strcat(letters, frombag.c_str());
    }
    sortCString(letters);
}


//funciones auxiliares


void removeCString(char *cstr, int pos){
    for (int i=pos; i<strlen(cstr); i++)
        cstr[i] = cstr[i+1];
}

void sortCString(char *cstr){
    char minimum, auxiliar;
    int position_minimum=0;
   
    for(int i=0; i<strlen(cstr); i++){
        minimum = cstr[i];
        position_minimum = i;
       
        for (int j=i+1; j<strlen(cstr); j++){
            if(cstr[j]<minimum){
                minimum = cstr[j];
                position_minimum = j;
            }
        }
       
        auxiliar = cstr[i];
        cstr[i] = cstr[position_minimum];
        cstr[position_minimum] = auxiliar;
    }
}