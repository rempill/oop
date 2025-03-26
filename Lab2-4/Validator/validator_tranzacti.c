//
// Created by kissk on 3/18/2025.
//

#include "validator_tranzacti.h"
/// functie care valideaza o tranzactie
/// aceasta functie verifica daca ziua este intre 1 si 31
/// daca suma este pozitiva
/// daca tipul este "Intrare" sau "Iesire"
/// daca descrierea nu este vida
/// @param tranzactie  tranzactia pe care dorim sa o validam
/// @return
int validare_Tranazctie(Tranzactie tranzactie) {
    if (tranzactie.ziua < 1 || tranzactie.ziua > 31) {
        return 1;
    }
    if (tranzactie.suma < 0) {
        return 2;
    }
    if (strcmp(tranzactie.tip, "Intrare") != 0 && strcmp(tranzactie.tip, "Iesire") != 0) {
        return 3;
    }
    if (strlen(tranzactie.descriere) == 0) {
        return 4;
    }
    return 0;
}