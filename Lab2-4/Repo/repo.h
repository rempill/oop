//
// Created by kissk on 3/18/2025.
//

#ifndef REPO_H
#define REPO_H
#pragma once

#include "../Domeniu/list_tranzactie.h"
 #include "../Erori/erors.h"

typedef struct {
 List* elements;
}Repository;

Repository* createRepo();

void destroyRepo(Repository* repo);

/// functie care adauga o tranzactie
/// @param lista
/// @param tranzactie
void adaugaTranzactie(Repository *repo, Tranzactie* tranzactie) ;
///functie care sterge o tranzactie
/// @param lista
/// @param index
int stergeTranzactie(Repository *lista, int index);

/// functie care modifica o tranzactie
/// @param lista
/// @param index  tranzactiei care vrea sa fie modificata
/// @param tranzactie tranzactia cu care vrem sa inlocuim tranzactia de la index
/// @return
int modificaTranzactie(Repository *lista, int index, Tranzactie* tranzactie);
#endif //REPO_H
