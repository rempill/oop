//
// Created by kissk on 3/18/2025.
//
#include "servis.h"

Service* createService() {
    Service* service = (Service*)malloc(sizeof(Service));
    service->repo = createRepo();
    service->undoStack = createList(destroyList,copyList);
    return service;
}

/// Functie care adauga o tranzactie
/// @param lista lista de tranzactii
/// @param tranzactie tranzactia pe care dorim sa o adaugam
int service_adaugaTranzactie(Service *service, Tranzactie* tranzactie) {
    if (validare_Tranazctie(*tranzactie) == 0) {
        List* copy=copyList(service->repo->elements);
        add(service->undoStack,copy);
        adaugaTranzactie(service->repo, tranzactie);
        return 0;
    } else {
        return validare_Tranazctie(*tranzactie);
    }
}
///
int service_stergeTranzactie(Service *lista, int index) {
    int rez=  stergeTranzactie(lista->repo, index);
    if (rez==0) {
        List* copy=copyList(lista->repo->elements);
        add(lista->undoStack,copy);
    }
    return rez;
}

/// 
/// @param lista 
/// @param index 
/// @param tranzactie 
/// @return 
int service_modificaTranzactie(Service *lista, int index, Tranzactie* tranzactie) {
    int rez= modificaTranzactie(lista->repo, index, tranzactie);
    if (rez==0) {
        List* copy=copyList(lista->repo->elements);
        add(lista->undoStack,copy);
    }
    return rez;
}

/// listaFiltrata este o lista noua in care se vor adauga tranzactiile filtrate
/// @param lista 
/// @param tip 
/// @param listaFiltrata 
void filtrate(Service *service, char *tip, List *listaFiltrata) {
    List *lista = service->repo->elements;
    for (int i = 0; i < lista->lungime; i++) {
        Tranzactie* tranzactie=get(lista,i);
        if (strcmp(tranzactie->tip, tip)==0) {
            add(listaFiltrata, copyTranzactie(tranzactie));
        }
    }
}

void filtrate_new(Service* service, int zi, List* listaFiltrata) {
    List* lista=service->repo->elements;
    for (int i = 0; i < lista->lungime; i++) {
        Tranzactie* tranzactie=get(lista,i);
        if (tranzactie->ziua==zi) {
            add(listaFiltrata, copyTranzactie(tranzactie));
        }
    }
}

void sortare(Service *service) {
    List *lista = service->repo->elements;
    for (int i = 0; i < lista->lungime - 1; i++) {
        for (int j = i + 1; j < lista->lungime; j++) {
            Tranzactie* t1=get(lista,i);
            Tranzactie* t2=get(lista,j);
            if (t1->ziua > t2->ziua) {
                Tranzactie* aux=lista->elements[i];
                lista->elements[i]=lista->elements[j];
                lista->elements[j]=aux;
            }
        }
    }
}

void undo(Service* service) {
    if (service->undoStack->lungime == 0) {
        return;
    }
    List *lastList=service->undoStack->elements[service->undoStack->lungime-1];
    service->undoStack->lungime--;
    destroyList(service->repo->elements);
    service->repo->elements=lastList;
}

void destroyService(Service* service) {
    destroyRepo(service->repo);
    destroyList(service->undoStack);
    free(service);
}