//
// Created by Mihai on 11.03.2025.
//
#include "test_domain.h"

void runDomainTests() {
    Offer_list* l=createOfferList();
    assert(l->length==0);
    assert(l->capacity==1000);
    assert(l->offers!=NULL);
    resize(l);
    assert(l->capacity==2000);
    destroyOfferList(l);
}