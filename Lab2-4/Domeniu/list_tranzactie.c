//
// Created by kissk on 3/18/2025.
//
#include "list_tranzactie.h"
/// Functie care creeaza o lista de undo
List* createList(DestroyFunc destroy, CopyFunc copy) {
    List* l=(List*)malloc(sizeof(List));
    l->lungime=0;
    l->capacity=2;
    l->elements=(TElem*) malloc(l->capacity*sizeof(TElem));
    l->destroyElement=destroy;
    l->copyElement=copy;
    return l;
}

void destroyList(List* l) {
    for (int i=0;i<l->lungime;i++) {
        l->destroyElement(l->elements[i]);
    }
    free(l->elements);
    free(l);
}

/// Functie care redimensioneaza lista de tranzactii
void resize(List* l) {
    int newCap=l->capacity*2;
    TElem* newTranzactii=(TElem *)malloc(newCap*sizeof(TElem));
    int i;
    for (i=0;i<l->lungime;i++) {
        newTranzactii[i]=l->elements[i];
    }
    free(l->elements);
    l->elements=newTranzactii;
    l->capacity=newCap;
}

void add(List* l, TElem el) {
    if (l->lungime==l->capacity) {
        resize(l);
    }
    l->elements[l->lungime++]=el;
}

void rem(List* lista,int index) {
    destroyTranzactie(lista->elements[index]);
    for (int i = index; i < lista->lungime - 1; i++) {
        lista->elements[i] = lista->elements[i + 1];
    }
    lista->lungime--;
}

void modify(List* l, int index, TElem el) {
    l->elements[index]=el;
}

TElem get(List* lista, int index) {
    return lista->elements[index];
}

List* copyList(List* l) {
    List* copy=(List*) malloc(sizeof(List));
    copy->elements=(TElem*)malloc(l->capacity*sizeof(TElem));
    for (int i=0;i<l->lungime;i++) {
        copy->elements[i]=l->copyElement(l->elements[i]);
    }
    copy->lungime=l->lungime;
    copy->capacity=l->capacity;
    copy->destroyElement=l->destroyElement;
    copy->copyElement=l->copyElement;
    return copy;
}

