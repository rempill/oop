//
// Created by Mihai on 07.03.2025.
//

#ifndef VALIDATE_OFFER_H
#define VALIDATE_OFFER_H
#pragma once
#include "Domain/offer.h"
#include <string.h>
#include <stdio.h>
#include "Errors/errors.h"
int validateOffer(Offer offer);
//Validates an offer
//Input: offer- Offer
//Output: SUCCESS if the offer is valid, VALIDATION_ERROR otherwise
#endif //VALIDATE_OFFER_H
