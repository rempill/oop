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
    int add1=addOffer(type,destination,departure_date,price,l);
    assert(l->length==0 && add1&INVALID_PRICE && add1&VALIDATION_ERROR);//validation error caused by price
    price=11.1;
    addOffer(type,destination,departure_date,price,l);
    int add2=addOffer(type,destination,departure_date,price,l);
    assert(l->length==1 && add2&REPO_ERROR);//repo error caused by duplicate
    assert(strcmp(l->offers[0].type,"sea side")==0);
    assert(strcmp(l->offers[0].destination,"Hati")==0);
    strcpy(new_type,"village");
    strcpy(new_destination,"Hati");
    strcpy(new_departure_date,"01.01.2026");
    new_price=1501.9;
    int upd1=updateOffer(type,destination,new_type,new_destination,new_departure_date,new_price,l);
    assert(strcmp(l->offers[0].type,"sea side")==0 && upd1&INVALID_TYPE && upd1&VALIDATION_ERROR);//validation error caused by type
    int upd2=updateOffer(new_type,destination,type,new_destination,new_departure_date,new_price,l);
    assert(upd2&REPO_ERROR);//repo error caused by non-existent offer
    new_price=1502.1;
    updateOffer(type,destination,type,new_destination,new_departure_date,new_price,l);
    assert(fabs(l->offers[0].price-1502.1)<TOLERANCE);
    strcpy(destination,"Bahamas");
    price=1111.1;
    addOffer(type,destination,departure_date,price,l);
    removeOffer(type,new_destination,l);
    removeOffer(type,destination,l);
    assert(l->length==0);
    int rm1=removeOffer(type,new_destination,l);
    assert(rm1&REPO_ERROR);//repo error caused by non-existent offer
    addOffer("sea side","Hati","01.01.2026",11.1,l);
    addOffer("mountain","Caman","05.11.2027",1000.0,l);
    addOffer("mountain","Olia","11.01.2025",115.5,l);
    Offer_list* sorted=createOfferList();
    sortOffersByPrice(l,0,sorted);
    assert(fabs(sorted->offers[0].price-11.1)<TOLERANCE);
    assert(fabs(sorted->offers[1].price-115.5)<TOLERANCE);
    assert(fabs(sorted->offers[2].price-1000.0)<TOLERANCE);
    sortOffersByPrice(l,1,sorted);
    assert(fabs(sorted->offers[0].price-1000.0)<TOLERANCE);
    assert(fabs(sorted->offers[1].price-115.5)<TOLERANCE);
    assert(fabs(sorted->offers[2].price-11.1)<TOLERANCE);
    sortOffersByDestination(l,0,sorted);
    assert(strcmp(sorted->offers[0].destination,"Caman")==0);
    assert(strcmp(sorted->offers[1].destination,"Hati")==0);
    assert(strcmp(sorted->offers[2].destination,"Olia")==0);
    sortOffersByDestination(l,1,sorted);
    assert(strcmp(sorted->offers[0].destination,"Olia")==0);
    assert(strcmp(sorted->offers[1].destination,"Hati")==0);
    assert(strcmp(sorted->offers[2].destination,"Caman")==0);
    Offer_list* filtered=createOfferList();
    filterByDestination(l,"Hati",filtered);
    assert(filtered->length==1);
    assert(strcmp(filtered->offers[0].destination,"Hati")==0);
    filterByType(l,"mountain",filtered);
    assert(filtered->length==2);
    assert(strcmp(filtered->offers[0].type,"mountain")==0);
    assert(strcmp(filtered->offers[1].type,"mountain")==0);
    filterByPrice(l,1000.0,filtered);
    assert(filtered->length==1);
    assert(fabs(filtered->offers[0].price-1000.0)<TOLERANCE);
    destroyOfferList(l);
    destroyOfferList(sorted);
    destroyOfferList(filtered);
}