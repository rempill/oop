//
// Created by kissk on 3/19/2025.
//
#include "teste_repo.h"

void testrsize() {
    Repository *repo = createRepo();
    List* l=repo->elements;
    assert(l->capacity == 2);
    adaugaTranzactie(repo, createTranzactie(1, 100, "Intrare", "Paris"));
    adaugaTranzactie(repo, createTranzactie(2, 100.0, "Intrare", "Paris"));
    adaugaTranzactie(repo, createTranzactie(3, 100.0, "Intrare", "Paris"));
    adaugaTranzactie(repo, createTranzactie(4, 100.0, "Intrare", "Paris"));
    adaugaTranzactie(repo, createTranzactie(5, 100.0, "Intrare", "Paris"));
    assert(l->lungime == 5);
    adaugaTranzactie(repo, createTranzactie(6, 100.0, "Intrare", "Paris"));
    assert(l->capacity == 8);
    destroyRepo(repo);
}
void runRepoTests() {
    Repository *repo= createRepo();
    List* l=repo->elements;
    Tranzactie* tranzactie=createTranzactie(12,100.0,"Intrare","Paris");
    adaugaTranzactie(repo, tranzactie);
    assert(l->lungime == 1);
    Tranzactie* traz=get(l,0);
    assert(strcmp(traz->tip, "Intrare") == 0);
    Tranzactie* new_tranzactie=createTranzactie(12,200.0,"Iesire","Paris");
    modificaTranzactie(repo,0, new_tranzactie);
    tranzactie=createTranzactie(12,100.0,"Intrare","Paris");
    adaugaTranzactie(repo, tranzactie);
    Tranzactie* tranz=get(l,0);
    assert(tranz->suma == 200.0);
    assert(strcmp(tranz->tip, "Iesire") == 0);
    assert(modificaTranzactie(repo,12, tranzactie) == 1);
    assert(strcmp(tranz->tip, "Iesire") == 0);
    assert(stergeTranzactie(repo,12)==1);
    assert(stergeTranzactie( repo,0)==0);
    assert(l->lungime == 1);
    tranz=get(l,0);
    assert(tranz->ziua == 12);
    assert(tranz->suma == 100.0);
    assert(strcmp(tranz->tip, "Intrare") == 0);
    assert(strcmp(tranz->descriere, "Paris") == 0);
    destroyRepo(repo);
    testrsize();
}