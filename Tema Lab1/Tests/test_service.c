//
// Created by Mihai on 12.03.2025.
//

#include "test_service.h"
#include <tgmath.h>
#define TOLERANCE 0.0001
void runServiceTests() {
    Offer_list* l=createOfferList();
    float price,new_price;
    char departure_date[11],type[11],destination[21],new_type[11],new_destination[21],new_departure_date[11];
    price=-1.0;
    strcpy(departure_date,"01.01.2026");
    strcpy(type,"sea side");
    strcpy(destination,"Hati");
    addOffer(type,destination,departure_date,price,l);
    assert(l->length==0);//validation error caused by price
    price=11.1;
    addOffer(type,destination,departure_date,price,l);
    assert(l->length==1);
    assert(strcmp(l->offers[0].type,"sea side")==0);
    assert(strcmp(l->offers[0].destination,"Hati")==0);
    strcpy(new_type,"village");
    strcpy(new_destination,"Hati");
    strcpy(new_departure_date,"01.01.2026");
    new_price=1501.9;
    updateOffer(type,destination,new_type,new_destination,new_departure_date,new_price,l);
    assert(strcmp(l->offers[0].type,"sea side")==0);//validation error caused by type
    new_price=1502.1;
    updateOffer(type,destination,type,new_destination,new_departure_date,new_price,l);
    assert(fabs(l->offers[0].price-1502.1)<TOLERANCE);
    removeOffer(type,new_destination,l);
    assert(l->length==0);
}