//
// Created by Mihai on 07.03.2025.
//

#ifndef REPO_H
#define REPO_H
#pragma once
#include <assert.h>
#include <string.h>
#include "Domain/offer_list.h"
int Add(Offer offer, Offer_list* l);
//Adds an offer to the list
//Input: offer-offer, l-offer list
int Update(Offer old_offer,Offer new_offer,Offer_list* l);
//Updates an offer from the list
//Input: old_offer-offer, new_offer-offer, l-offer list
int Remove(Offer offer,Offer_list* l);
//Removes an offer from the list
//Input: offer-offer, l-offer list
#endif //REPO_H
