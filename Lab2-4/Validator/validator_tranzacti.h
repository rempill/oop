//
// Created by kissk on 3/18/2025.
//

#ifndef VALIDATOR_TRANZACTI_H
#define VALIDATOR_TRANZACTI_H
#pragma once
#include "../Domeniu/tranzactie.h"
#include <string.h>
/// functie care valideaza o tranzactie
/// @param tranzactie  tranzactia pe care dorim sa o validam
/// @return 0 daca tranzactia este valida, 1 daca ziua nu este intre 1 si 31, 2 daca suma este negativa, 3 daca tipul nu este "Intrare" sau "Iesire", 4 daca descrierea este vida
int validare_Tranazctie(Tranzactie tranzactie);
#endif //VALIDATOR_TRANZACTI_H
