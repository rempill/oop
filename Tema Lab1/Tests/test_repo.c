//
// Created by Mihai on 11.03.2025.
//

#include "test_repo.h"

void runRepoTests() {
    Offer_list *l = createOfferList();
    Offer offer;
    strcpy(offer.type,"city break");
    strcpy(offer.destination,"Paris");
    strcpy(offer.departure_date,"12.12.2025");
    offer.price=100;
    Add(offer,l);
    assert(l->length==1);
    assert(strcmp(l->offers[0].type,"city break")==0);
    Add(offer,l);//offer already exists
    assert(l->length==1);
    Offer new_offer;
    strcpy(new_offer.type,"city break");
    strcpy(new_offer.destination,"Paris");
    strcpy(new_offer.departure_date,"12.12.2025");
    new_offer.price=200;
    Update(offer,new_offer,l);
    assert(l->offers[0].price==200);
    strcpy(new_offer.type,"sea side");
    Update(new_offer,offer,l);
    assert(l->offers[0].price==200); //offer not found
    strcpy(offer.type,"sea side");
    Remove(offer,l);
    assert(l->length==1);//offer not found
    strcpy(new_offer.type,"city break");
    Remove(new_offer,l);
    assert(l->length==0);
    destroyOfferList(l);
}