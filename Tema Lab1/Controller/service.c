//
// Created by Mihai on 07.03.2025.
//

#include "service.h"
#define COMPARE(a,b) ((a>b)-(a<b))
int comparePrice(const void *a, const void *b) {
    Offer* tempa=(Offer*)a;
    Offer* tempb=(Offer*)b;
    return COMPARE(tempa->price,tempb->price);
}

int comparePriceDesc(const void *a, const void *b) {
    Offer* tempa=(Offer*)a;
    Offer* tempb=(Offer*)b;
    return COMPARE(tempb->price,tempa->price);
}

int compareDestination(const void *a, const void *b) {
    Offer* tempa=(Offer*)a;
    Offer* tempb=(Offer*)b;
    return strcmp(tempa->destination, tempb->destination);
}

int compareDestinationDesc(const void *a, const void *b) {
    Offer* tempa=(Offer*)a;
    Offer* tempb=(Offer*)b;
    return strcmp(tempb->destination, tempa->destination);
}

void addOffer(char type[],char destination[],char departure_date[],float price,Offer_list* l) {
    Offer offer;
    strcpy(offer.type,type);
    strcpy(offer.destination,destination);
    strcpy(offer.departure_date,departure_date);
    offer.price=price;
    if (validateOffer(offer)) {
        return;
    }
    Add(offer,l);
}

void updateOffer(char old_type[],char old_destination[],char new_type[],char new_destination[],char new_departure_date[],float new_price,Offer_list* l) {
    Offer old_offer;
    strcpy(old_offer.type,old_type);
    strcpy(old_offer.destination,old_destination);
    Offer new_offer;
    strcpy(new_offer.type,new_type);
    strcpy(new_offer.destination,new_destination);
    strcpy(new_offer.departure_date,new_departure_date);
    new_offer.price=new_price;
    if (validateOffer(new_offer)==1) {
        return;
    }
    Update(old_offer,new_offer,l);
}

void removeOffer(char type[],char destination[],Offer_list* l) {
    Offer offer;
    strcpy(offer.type,type);
    strcpy(offer.destination,destination);
    Remove(offer,l);
}

Offer_list* sortOffersByPrice(Offer_list* l,int asc_desc) {
    Offer_list* sorted=malloc(sizeof(Offer_list));
    sorted->offers=malloc(sizeof(Offer)*l->length);
    sorted->capacity=l->capacity;
    for (int i=0;i<l->length;i++) {
        sorted->offers[i]=l->offers[i];
    }
    sorted->length=l->length;
    if (asc_desc) {
       qsort(sorted->offers,sorted->length, sizeof(Offer), comparePriceDesc);
    }
    else {
        qsort(sorted->offers,sorted->length, sizeof(Offer), comparePrice);
    }
    return sorted;
}

Offer_list* sortOffersByDestination(Offer_list* l,int asc_desc) {
    Offer_list* sorted=malloc(sizeof(Offer_list));
    sorted->offers=malloc(sizeof(Offer)*l->length);
    sorted->capacity=l->capacity;
    for (int i=0;i<l->length;i++) {
        sorted->offers[i]=l->offers[i];
    }
    sorted->length=l->length;
    if (asc_desc) {
        qsort(sorted->offers,sorted->length, sizeof(Offer), compareDestinationDesc);
    }
    else {
        qsort(sorted->offers,sorted->length, sizeof(Offer), compareDestination);
    }
    return sorted;
}

Offer_list* filterByDestination(Offer_list* l,char destination[]) {
    Offer_list* filtered=malloc(sizeof(Offer_list));
    filtered->offers=malloc(l->length*sizeof(Offer));
    filtered->length=l->length;
    filtered->capacity=l->capacity;
    int j=0;
    for (int i=0;i<l->length;++i) {
        if (!strcmp(destination,l->offers[i].destination)) {
            filtered->offers[j]=l->offers[i];
            j++;
        }
    }
    filtered->length=j;
    return filtered;
}

Offer_list* filterByType(Offer_list* l,char type[]) {
    Offer_list* filtered=malloc(sizeof(Offer_list));
    filtered->offers=malloc(l->length*sizeof(Offer));
    filtered->length=l->length;
    filtered->capacity=l->capacity;
    int j=0;
    for (int i=0;i<l->length;++i) {
        if (!strcmp(type,l->offers[i].type)) {
            filtered->offers[j]=l->offers[i];
            j++;
        }
    }
    filtered->length=j;
    return filtered;
}

Offer_list* filterByPrice(Offer_list* l,float price) {
    Offer_list* filtered=malloc(sizeof(Offer_list));
    filtered->offers=malloc(l->length*sizeof(Offer));
    filtered->length=l->length;
    filtered->capacity=l->capacity;
    int j=0;
    for (int i=0;i<l->length;++i) {
        if (l->offers[i].price==price) {
            filtered->offers[j]=l->offers[i];
            j++;
        }
    }
    filtered->length=j;
    return filtered;
}