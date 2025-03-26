//
// Created by kissk on 3/19/2025.
//
#include "teste_servis.h"
void runServiceTests() {
    Service *service = createService();
    undo(service);
    List* l=service->repo->elements;
    Tranzactie* tranzactie=createTranzactie(12,100,"Intrare","Paris");
    assert(service_adaugaTranzactie(service, tranzactie)==0);
    assert(l->lungime == 1);
    strcpy(tranzactie->tip, "Inte");
    assert(service_adaugaTranzactie(service, tranzactie)==3);
    strcpy(tranzactie->tip, "Intrare");
    Tranzactie* new_tranzactie=createTranzactie(13,200,"Iesire","Paris");
    assert(service_modificaTranzactie(service,0, new_tranzactie)==0);
    Tranzactie* tranzac=get(l,0);
    assert(tranzac->suma == 200.0);
    assert(service_stergeTranzactie(service,0)==0);
    assert(l->lungime == 0);


    List *listaFiltrata = createList(destroyTranzactie,copyTranzactie);
    filtrate(service, "Intrare", listaFiltrata);
    assert(listaFiltrata->lungime == 0); // No "Intrare" transactions after deletion
    destroyList(listaFiltrata);

    Tranzactie* t1=createTranzactie(15,150.0,"Intrare","Test1");
    Tranzactie* t2=createTranzactie(10,100.0,"Intrare","Test2");
    Tranzactie* t3=createTranzactie(20,200.0,"Intrare","Test3");
    service_adaugaTranzactie(service, t1);
    service_adaugaTranzactie(service, t2);
    service_adaugaTranzactie(service, t3);
    sortare(service);
    Tranzactie* tes1=get(l,0);
    Tranzactie* tes2=get(l,1);
    Tranzactie* tes3=get(l,2);
    assert(tes1->ziua == 10);
    assert(tes2->ziua == 15);
    assert(tes3->ziua == 20);
    List* listaFiltrata1 = createList(destroyTranzactie,copyTranzactie);
    filtrate(service, "Intrare", listaFiltrata1);
    assert(listaFiltrata1->lungime == 3);
    tes1=get(l,1);
    assert(tes1->ziua == 15);
    destroyList(listaFiltrata1);
    List* listaFiltrata2 = createList(destroyTranzactie,copyTranzactie);
    filtrate_new(service, 15,listaFiltrata2);
    Tranzactie* filtest=get(listaFiltrata2,0);
    assert(filtest->ziua == 15);
    assert(listaFiltrata2->lungime==1);
    // Test undo
    undo(service);
    l=service->repo->elements;
    assert(l->lungime == 2);
    undo(service);
    l=service->repo->elements;
    assert(l->lungime == 1);
    undo(service);

    destroyService(service);
    destroyList(listaFiltrata2);
}