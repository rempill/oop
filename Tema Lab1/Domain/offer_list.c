//
// Created by Mihai on 07.03.2025.
//
#include "offer_list.h"

Offer_list* createOfferList() {
    Offer_list* l=malloc(sizeof(Offer_list));
    l->length=0;
    l->capacity=1000;
    l->offers=malloc(l->capacity*sizeof(Offer));
    return l;
}

void destroyOfferList(Offer_list* l) {
    free(l->offers);
    free(l);
}

void resize(Offer_list* l) {
    int newCap=l->capacity*2;
    Offer* newOffers=malloc(newCap*sizeof(Offer));
    int i;
    for (i=0;i<l->length;i++) {
        newOffers[i]=l->offers[i];
    }
    free(l->offers);
    l->offers=newOffers;
    l->capacity=newCap;
}

