//
// Created by Mihai on 07.03.2025.
//

#include "validate_offer.h"

int validateOffer(Offer offer) {
    Error err=SUCCESS;
    if (!strlen(offer.type) ||( strcmp(offer.type,"city break") && strcmp(offer.type,"mountain") && strcmp(offer.type,"sea side"))) {
        err|=INVALID_TYPE;
    }
    if (!strlen(offer.destination)) {
       err|=INVALID_DESTINATION;
    }
    int day=0,month=0,year=0;
    if (!strlen(offer.departure_date) || sscanf(offer.departure_date,"%d.%d.%d",&day,&month,&year)!=3) {
        err|=INVALID_DATE;
    }
    if (offer.price<=0.0) {
        err|=INVALID_PRICE;
    }
    if (day<1 || day>31 || month<1 || month>12 || year<2025 && !(err&INVALID_DATE)) {
        err|=INVALID_DATE;
    }
    if (err!=SUCCESS) {
        err|=VALIDATION_ERROR;
        return err;
    }
    return SUCCESS;
}