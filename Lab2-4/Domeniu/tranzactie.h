//
// Created by kissk on 3/18/2025.
//

#ifndef TRANZACTIE_H
#define TRANZACTIE_H
typedef struct {
    int ziua;
    float suma;
    char* tip;
    char* descriere;
} Tranzactie;
/// functie care creeaza o tranzactie
/// @param zi, sum, tip, desc
/// @ret tranzactie
Tranzactie* createTranzactie(int,float,char*,char*);

/// functie care distruge o tranzactie
/// @param t
void destroyTranzactie(Tranzactie* t);

/// functie care copiaza o tranzactie
/// @param t
/// @ret copy
Tranzactie* copyTranzactie(Tranzactie* t);

#endif //TRANZACTIE_H
