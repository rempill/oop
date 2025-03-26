//
// Created by kissk on 3/18/2025.
//

#ifndef LIST_TRANZACTIE_H
#define LIST_TRANZACTIE_H
#pragma once
#include "tranzactie.h"
#include <stdlib.h>
#include <string.h>

typedef void* TElem;
typedef void (*DestroyFunc)(TElem);
typedef TElem (*CopyFunc)(TElem);

typedef struct {
    int lungime;
    int capacity;
    TElem* elements;
    DestroyFunc destroyElement;
    CopyFunc copyElement;
}List;

/// functie care creeaza o lista de undo
List* createList(DestroyFunc destroyElement, CopyFunc copyElement);

///functie care distruge lista de undo
void destroyList(List* l);

/// functie care adauga o tranzactie in lista
/// @param l, el
void add(List* l, TElem el);

///functie care sterge un element din lista
void rem(List* l,int index);

///functie care modifica o tranzactie din lista
///@param l,index,el
void modify(List* l, int index, TElem el);

///functie care returneaza un element din lista
TElem get(List* l, int index);

/// functie care copiaza o lista de tranzactii
/// @param l
List* copyList(List* l);

/// functie care redimensioneaza  o lista de  tranzactie
/// @param l
void resize(List* l);
#endif //LIST_TRANZACTIE_H
