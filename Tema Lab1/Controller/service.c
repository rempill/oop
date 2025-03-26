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

int addOffer(char type[],char destination[],char departure_date[],float price,Offer_list* l) {
    Offer offer;
    strcpy(offer.type,type);
    strcpy(offer.destination,destination);
    strcpy(offer.departure_date,departure_date);
    offer.price=price;
    Error err=validateOffer(offer);
    if (err!=SUCCESS) {
        return err;
    }
    int check=Add(offer,l);
    if (check) {
        return SUCCESS;
    }
    return REPO_ERROR;
}

int updateOffer(char old_type[],char old_destination[],char new_type[],char new_destination[],char new_departure_date[],float new_price,Offer_list* l) {
    Offer old_offer;
    strcpy(old_offer.type,old_type);
    strcpy(old_offer.destination,old_destination);
    Offer new_offer;
    strcpy(new_offer.type,new_type);
    strcpy(new_offer.destination,new_destination);
    strcpy(new_offer.departure_date,new_departure_date);
    new_offer.price=new_price;
    Error err=validateOffer(new_offer);
    if (err!=SUCCESS) {
        return err;
    }
    int check=Update(old_offer,new_offer,l);
    if (check) {
        return SUCCESS;
    }
    return REPO_ERROR;
}

int removeOffer(char type[],char destination[],Offer_list* l) {
    Offer offer;
    strcpy(offer.type,type);
    strcpy(offer.destination,destination);
    int check=Remove(offer,l);
    if (check) {
        return SUCCESS;
    }
    return REPO_ERROR;
}

void sortOffersByPrice(Offer_list* l,int asc_desc,Offer_list* sorted) {
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
}

void sortOffersByDestination(Offer_list* l,int asc_desc,Offer_list* sorted) {
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
}

void filterByDestination(Offer_list* l,char destination[],Offer_list* filtered) {
    int j=0;
    for (int i=0;i<l->length;++i) {
        if (!strcmp(destination,l->offers[i].destination)) {
            filtered->offers[j]=l->offers[i];
            j++;
        }
    }
    filtered->length=j;
}

void filterByType(Offer_list* l,char type[],Offer_list* filtered) {
    int j=0;
    for (int i=0;i<l->length;++i) {
        if (!strcmp(type,l->offers[i].type)) {
            filtered->offers[j]=l->offers[i];
            j++;
        }
    }
    filtered->length=j;
}

void filterByPrice(Offer_list* l,float price,Offer_list* filtered) {
    int j=0;
    for (int i=0;i<l->length;++i) {
        if (l->offers[i].price==price) {
            filtered->offers[j]=l->offers[i];
            j++;
        }
    }
    filtered->length=j;
}