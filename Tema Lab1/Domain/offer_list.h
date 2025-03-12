//
// Created by Mihai on 07.03.2025.
//

#ifndef OFFER_LIST_H
#define OFFER_LIST_H
#pragma once
#include "offer.h"
#include <stdlib.h>
typedef struct {
    int length;
    int capacity;
    Offer* offers;
}Offer_list;

Offer_list* createOfferList();
//Creates an offer list
void destroyOfferList(Offer_list* l);
//Destroys an offer list, freeing the memory
void resize(Offer_list* l);
//Resizes an offer list by doubling its capacity
#endif //OFFER_LIST_H
