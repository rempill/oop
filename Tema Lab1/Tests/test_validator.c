//
// Created by Mihai on 23.03.2025.
//
#include "test_validator.h"

void runValidatorTests() {
    Offer offer;
    strcpy(offer.type,"city break");
    strcpy(offer.destination,"Paris");
    strcpy(offer.departure_date,"12.12.2025");
    offer.price=100.0;
    assert(validateOffer(offer)==SUCCESS);
    strcpy(offer.type,"islands");
    assert(validateOffer(offer)==INVALID_TYPE+VALIDATION_ERROR);
    strcpy(offer.type,"sea side");
    strcpy(offer.destination,"");
    assert(validateOffer(offer)==INVALID_DESTINATION+VALIDATION_ERROR);
    strcpy(offer.destination,"Paris");
    strcpy(offer.departure_date,"12.13.2025");
    assert(validateOffer(offer)==INVALID_DATE+VALIDATION_ERROR);
    strcpy(offer.departure_date,"12..2025");
    assert(validateOffer(offer)==INVALID_DATE+VALIDATION_ERROR);
    strcpy(offer.departure_date,"12.12.2025");
    offer.price=-100.0;
    assert(validateOffer(offer)==INVALID_PRICE+VALIDATION_ERROR);
}