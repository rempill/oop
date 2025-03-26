//
// Created by kissk on 3/18/2025.
//

#ifndef SERVI_H
#define SERVI_H
#pragma once
#include "../Repo/repo.h"
#include "../Validator/validator_tranzacti.h"
#include "../Erori/erors.h"
#include <string.h>
#include <stdlib.h>

typedef struct {
    Repository* repo;
    List* undoStack;
}Service;
/// functie care creeaza un service
/// @return service
Service* createService();

/// functie care adauga o tranzactie
/// @param lista
/// @param tranzactie
/// @return
int service_adaugaTranzactie(Service *lista, Tranzactie* tranzactie);

/// functie care sterge o tranzactie
/// @param lista
/// @param index
/// @return
int service_stergeTranzactie(Service *lista, int index);

/// functie care modifica o tranzactie
/// @param lista
/// @param index
/// @param tranzactie
/// @return
int service_modificaTranzactie(Service *lista, int index, Tranzactie* tranzactie);

/// functie care filtreaza tranzactiile in functie de tipul lor
/// @param lista
/// @param tip
/// @param listaFiltrata
void filtrate(Service *lista, char *tip, List *listaFiltrata);
void filtrate_new(Service*,int,List*);

/// functie care sorteaza tranzactiile in functie de ziua in care au fost efectuate
/// @param lista
void sortare(Service *lista);

/// functie de undo
/// @param service
void undo(Service* service);

///functie care distruge service
///@param service
void destroyService(Service* service);

#endif //SERVI_H
