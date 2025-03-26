//
// Created by Mihai on 07.03.2025.
//

#include "repo.h"

int Add(Offer offer, Offer_list* l) {
    if (l->length>=l->capacity) {
        resize(l);
    }
    int i;
    for (i=0;i<l->length;++i) {
        if (strcmp(l->offers[i].destination,offer.destination)==0 && strcmp(l->offers[i].type,offer.type)==0) {
            //repoError("\nOffer already exists\n");
            return 0;
        }
    }
    l->offers[l->length]=offer;
    l->length++;
    return 1;
}

int Update(Offer old_offer,Offer new_offer,Offer_list* l) {
    int i=0;
    for (i=0;i<l->length;++i) {
        if (strcmp(l->offers[i].destination,old_offer.destination)==0 && strcmp(l->offers[i].type,old_offer.type)==0) {
            l->offers[i]=new_offer;
            return 1;
        }
    }
    return 0;
    //repoError("\nOffer not found\n");
}

int Remove(Offer offer,Offer_list* l) {
    int i;
    for (i=0;i<l->length;++i) {
        if (strcmp(l->offers[i].destination,offer.destination)==0 && strcmp(l->offers[i].type,offer.type)==0) {
            break;
        }
    }
    if (i==l->length) {
        //repoError("\nOffer not found\n");
        return 0;
    }
    for (i;i<l->length-1;++i) {
        l->offers[i]=l->offers[i+1];
    }
    l->length--;
    return 1;
}

