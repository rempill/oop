//
// Created by Mihai on 26.03.2025.
//
#include "tranzactie.h"

#include <stdlib.h>
#include <string.h>

Tranzactie* createTranzactie(int zi,float sum,char* tip,char* desc) {
    Tranzactie* t = (Tranzactie*)malloc(sizeof(Tranzactie));
    if (t==NULL) {
        return NULL;
    }
    t->ziua=zi;
    t->suma=sum;
    t->tip = (char*) malloc(sizeof(char)*(strlen(tip)+1));
    strcpy(t->tip,tip);
    t->descriere = (char*) malloc(sizeof(char)*(strlen(desc)+1));
    strcpy(t->descriere,desc);
    return t;
}

void destroyTranzactie(Tranzactie* t) {
    free(t->tip);
    free(t->descriere);
    free(t);
}

Tranzactie* copyTranzactie(Tranzactie* t) {
    Tranzactie* copy=(Tranzactie*)malloc(sizeof(Tranzactie));
    if (copy==NULL) {
        return NULL;
    }
    copy->tip = (char*) malloc(sizeof(char)*(strlen(t->tip)+1));
    strcpy(copy->tip,t->tip);
    copy->descriere = (char*) malloc(sizeof(char)*(strlen(t->descriere)+1));
    strcpy(copy->descriere,t->descriere);
    copy->ziua=t->ziua;
    copy->suma=t->suma;
    return copy;
}