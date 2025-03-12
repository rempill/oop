//
// Created by Mihai on 07.03.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#pragma once
#include "Repository/repo.h"
#include "Validator/validate_offer.h"
#include "Errors/errors.h"
#include <string.h>
#include <stdlib.h>
void addOffer(char type[],char destination[],char departure_date[],float price,Offer_list* l);
//Adds an offer to the list; if the offer is invalid, it will not be added
//Input: type,destination,departure_date-strings, price-float, l-offer list
void updateOffer(char old_type[],char old_destination[],char new_type[],char new_destination[],char new_departure_date[],float new_price,Offer_list* l);
//Updates an offer from the list; if the new offer is invalid, it will not be updated
//Input: old_type,old_destination,new_type,new_destination,new_departure_date-strings, new_price-float, l-offer list
void removeOffer(char type[],char destination[],Offer_list* l);
//Removes an offer from the list
//Input: type,destination-strings, l-offer list
Offer_list* sortOffersByDestination(Offer_list* l,int asc_desc);
//Sorts the offers by destination
//Input: l-offer list, asc_desc-integer, decides if the list will be sorted ascending or descending
Offer_list* sortOffersByPrice(Offer_list* l,int asc_desc);
//Sorts the offers by price
//Input: l-offer list, asc_desc-integer, decides if the list will be sorted ascending or descending
Offer_list* filterByDestination(Offer_list* l,char destination[]);
//Filters the offers by destination
//Input: l-offer list, destination-string
Offer_list* filterByType(Offer_list* l,char type[]);
//Filters the offers by type
//Input: l-offer list, type-string
Offer_list* filterByPrice(Offer_list* l,float price);
//Filters the offers by price
//Input: l-offer list, price-float
#endif //SERVICE_H
