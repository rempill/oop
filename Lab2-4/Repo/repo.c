//
// Created by kissk on 3/18/2025.
//
#include "repo.h"

#include "../Servis/servis.h"

Repository* createRepo() {
    Repository* repo = (Repository*) malloc(sizeof(Repository));
    repo->elements = createList(destroyTranzactie,copyTranzactie);
    return repo;
}

/// Functie care adauga o tranzactie
/// @param lista lista de tranzactii
/// @param tranzactie tranzactia pe care dorim sa o adaugam
/// @return
void adaugaTranzactie(Repository* repo, Tranzactie* tranzactie) {
    add(repo->elements, tranzactie);
}
/// Functie care sterge o tranzactie
/// @param lista lista de tranzactii
/// @param index indexul tranzactiei pe care dorim sa o stergem
int stergeTranzactie(Repository *lista, int index) {
    if (index < 0 || index >= lista->elements->lungime) {
        return 1 ;
    }
    rem(lista->elements,index);
    return 0;
}
/// Functie care modifica o tranzactie
/// @param lista lista de tranzactii
/// @param index indexul tranzactiei pe care dorim sa o modificam
/// @param tranzactie  tranzactia cu care dorim sa o modificam
int modificaTranzactie(Repository *lista, int index, Tranzactie* tranzactie) {
    if (index < 0 || index >= lista->elements->lungime) {
        return 1;
    }
    Tranzactie* tranz=get(lista->elements, index);
    destroyTranzactie(tranz);
    modify(lista->elements, index, tranzactie);
    return 0;
}

void destroyRepo(Repository* repo) {
    destroyList(repo->elements);
    free(repo);
}