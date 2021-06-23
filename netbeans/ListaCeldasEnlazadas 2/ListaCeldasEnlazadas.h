/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCeldasEnlazadas.h
 * Author: acu
 *
 * Created on 31 de marzo de 2020, 17:06
 */

#ifndef LISTACELDASENLAZADAS_H
#define LISTACELDASENLAZADAS_H

struct Celda {
    double dato;
    Celda* sig;
};

void insertarPrincipioLista(Celda* &lista, double valor);
void insertarAlFinalLista(Celda* &lista, double valor);
void insertarDespuesCeldaLista(Celda* pos, double valor);
void insertarAntesCeldaLista(Celda* pos, double valor);
void borrar(Celda *pos);
void mostrarLista(Celda* lista);
void destruirLista(Celda* &lista);
#endif /* LISTACELDASENLAZADAS_H */

