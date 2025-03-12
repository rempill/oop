//
// Created by Mihai on 07.03.2025.
//

#include "validate_offer.h"

int validateOffer(Offer offer) {
    char errors[1000]="Validation errors:";
    if (strlen(offer.type)==0) {
        strcat(errors,"Type cannot be empty; ");
    }
    if (strlen(offer.destination)==0) {
        strcat(errors,"Destination cannot be empty; ");
    }
    if (strlen(offer.departure_date)==0) {
        strcat(errors,"Departure date cannot be empty; ");
    }
    if (offer.price<=0.0) {
        strcat(errors,"Price must be a positive nr; ");
    }
    int day=0,month=0,year=0;
    if (sscanf(offer.departure_date,"%d.%d.%d",&day,&month,&year)!=3) {
        strcat(errors,"Date must be in the format dd.mm.yyyy; ");
    }
    if (day<1 || day>31) {
        strcat(errors,"Day must be between 1 and 31; ");
    }
    if (month<1 || month>12) {
        strcat(errors,"Month must be between 1 and 12; ");
    }
    if (year<2025) {
        strcat(errors,"Year must be greater than 2025; ");
    }
    if (strcmp(offer.type,"city break") && strcmp(offer.type,"mountain") && strcmp(offer.type,"sea side")) {
        strcat(errors,"Type must be city break, sea side or mountain; ");
    }
    if (strcmp(errors,"Validation errors:")) {
        printf("%s\n",errors);
        return 1;
    }
    return 0;
}