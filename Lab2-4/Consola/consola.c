//
// Created by kissk on 3/18/2025.
//
#include "consola.h"
/// Functie care afiseaza meniul
/// @param
void meniu() {
    printf("1. Adauga tranzactie\n");
    printf("2. Afiseaza tranzactii\n");
    printf("3. Sterge tranzactie\n");
    printf("4. Modifica tranzactie\n");
    printf("5. Filtrare typ\n");
    printf("6. Filtrare zi\n");
    printf("7. Sortare\n");
    printf("8. Undo\n");
}
/// functionalitate de adaugare a unei tranzactii
/// @param lista lista de tranzactii
void ui_adaugaTranzactie(Service *service) {
    int ziua;
    float suma;
    char* tip=(char*)malloc(20);
    char* descriere=(char*)malloc(20);
    printf("Introduceti ziua: ");
    scanf("%d", &ziua);
    printf("Introduceti suma: ");
    scanf("%f", &suma);
    printf("Introduceti tipul: ");
    scanf("%s", tip);
    printf("Introduceti descrierea: ");
    scanf("%s", descriere);
    Tranzactie* tranzactie=createTranzactie(ziua,suma,tip,descriere);
    if (service_adaugaTranzactie(service, tranzactie) == 0) {
        printf("Tranzactie adaugata cu succes!\n");
    } else {
        printf("Tranzactie nu a putut fi adaugata!\n");
        if (service_adaugaTranzactie(service, tranzactie) == 1) {
            printf("Ziua trebuie sa fie intre 1 si 31!\n");
        } else if (service_adaugaTranzactie(service, tranzactie) == 2) {
            printf("Suma trebuie sa fie pozitiva!\n");
        } else if (service_adaugaTranzactie(service, tranzactie) == 3) {
            printf("Tipul trebuie sa fie 'Intrare' sau 'Iesire'!\n");
        } else if (service_adaugaTranzactie(service, tranzactie) == 4) {
            printf("Descrierea nu poate fi vida!\n");
        }
        destroyTranzactie(tranzactie);
    }
    free(tip);
    free(descriere);
}
void ui_afiseazaTranzactii(Service *service) {
    List* elements=service->repo->elements;
    for (int i = 0; i < elements->lungime; i++) {
        Tranzactie* lista=get(elements,i);
        printf("%d: Ziua: %d, Suma: %.2f, Tip: %s, Descriere: %s\n",i,
               lista->ziua, lista->suma,
               lista->tip, lista->descriere);
    }
}

///
/// @param lista lista de tranzactii
void ui_stergeTranzactie(Service *service) {
    ui_afiseazaTranzactii(service);
    int nr;
    printf("Introduceti indexul tranzactiei pe care doriti sa o stergeti: ");
    scanf("%d", &nr);
    if (service_stergeTranzactie(service, nr)==0) {
        printf("Tranzactie stearsa cu succes!\n");
    } else {
        printf("Tranzactie nu a putut fi stearsa!\n");
    }
}
///Functionalitate de modificare a unei tranzactii
/// @param lista
void ui_modificaTranzactie(Service *service) {
    ui_afiseazaTranzactii(service);
    int nr;
    printf("Introduceti indexul tranzactiei pe care doriti sa o modificati: ");
    scanf("%d", &nr);
    int zi; float sum; char* tip=(char*)malloc(20),*desc=(char*)malloc(20);
    printf("Introduceti ziua: ");
    scanf("%d", &zi);
    printf("Introduceti suma: ");
    scanf("%f", &sum);
    printf("Introduceti tipul: ");
    scanf("%s", tip);
    printf("Introduceti descrierea: ");
    scanf("%s", desc);
    Tranzactie* tranzactie=createTranzactie(zi,sum,tip,desc);
    if (service_modificaTranzactie(service, nr, tranzactie) == 0) {
        printf("Tranzactie modificata cu succes!\n");
    } else {
        destroyTranzactie(tranzactie);
        printf("Tranzactie nu a putut fi modificata!\n");
    }
    free(tip);
    free(desc);
}
///Functionalitate de filtrare a tranzactiilor
///@param lista
void ui_filtrare(Service *lista) {
    List *listaFiltrata=createList(destroyTranzactie,copyTranzactie);
    char tip[20];
    printf("Introduceti tipul: ");
    scanf("%s", &tip);
    filtrate(lista, tip, listaFiltrata);

    for (int i = 0; i < listaFiltrata->lungime; i++) {
        Tranzactie* tranzactie=get(listaFiltrata,i);
        printf("%d: Ziua: %d, Suma: %.2f, Tip: %s, Descriere: %s\n",i,
               tranzactie->ziua, tranzactie->suma,
               tranzactie->tip, tranzactie->descriere);
    }
    destroyList(listaFiltrata);
}

void ui_filtrare_new(Service* service) {
    List *listaFiltrata=createList(destroyTranzactie,copyTranzactie);
    int zi;
    printf("Introduceti ziua: ");
    scanf("%d",&zi);
    filtrate_new(service,zi,listaFiltrata);
    for (int i = 0; i < listaFiltrata->lungime; i++) {
        Tranzactie* tranzactie=get(listaFiltrata,i);
        printf("%d: Ziua: %d, Suma: %.2f, Tip: %s, Descriere: %s\n",i,
               tranzactie->ziua, tranzactie->suma,
               tranzactie->tip, tranzactie->descriere);
    }
    destroyList(listaFiltrata);
}


///Functionaliate de sortare
void ui_sortare(Service *service) {
    sortare(service);
    ui_afiseazaTranzactii(service);
}

void ui_undo(Service *service) {
    undo(service);
}

void runn(Service *service) {
    char comanda[3];

    while (1) {
        meniu();
        printf("Introduceti comanda: ");
        scanf("%s", &comanda);
        if (strcmp(comanda, "1") == 0) {
            ui_adaugaTranzactie(service);
        } else if (strcmp(comanda, "2") == 0) {
            ui_afiseazaTranzactii(service);
        } else if (strcmp(comanda, "3") == 0) {
            ui_stergeTranzactie(service);
        } else if (strcmp(comanda, "4") == 0) {
            ui_modificaTranzactie(service);
        } else if (strcmp(comanda, "5") == 0) {
            ui_filtrare(service);
        } else if (strcmp(comanda,"6")==0) {
            ui_filtrare_new(service);
        } else if (strcmp(comanda,"7")==0) {
            ui_sortare(service);
        } else if (strcmp(comanda, "8") == 0) {
            ui_undo(service);
        } else {
            break;
        }
    }
}