//
// Created by Mihai on 07.03.2025.
//

#include "console.h"

void clearBuffer(char* buffer) {
    if (strchr(buffer, '\n') == NULL) {
        while (getchar() != '\n');
    }
}

void printMenu() {
    printf("1. Add offer\n");
    printf("2. Update offer\n");
    printf("3. Remove offer\n");
    printf("4. Sort offers\n");
    printf("5. Filter offers\n");
    printf("6. Print offers\n");
    printf("7. Exit\n");
}

void printOffers(Offer_list *l) {
    int i;
    for (i=0;i<l->length;++i) {
        printf("Type: %s, Destination: %s, Departure date: %s, Price: %.2f\n",l->offers[i].type,l->offers[i].destination,l->offers[i].departure_date,l->offers[i].price);
    }
}

void inputFloat(char message[],float* price) {
    int invalid=1;
    char input[10];
    while (invalid) {
        printf("%s",message);
        fgets(input,10,stdin);
        clearBuffer(input);
        if (sscanf(input,"%f",price)==1) {
            invalid=0;
        }
        else {
            printf("Invalid input\n");
        }
    }
}

void addOfferUi(Offer_list *l) {
    char type[12],destination[22],departure_date[12];
    float price;
    printf("Type:");
    fgets(type, 12, stdin);
    clearBuffer(type);
    type[strlen(type)-1]='\0';
    printf("Destination:");
    fgets(destination, 22, stdin);
    clearBuffer(destination);
    destination[strlen(destination)-1]='\0';
    printf("Departure date:");
    fgets(departure_date, 12, stdin);
    clearBuffer(departure_date);
    departure_date[strlen(departure_date)-1]='\0';
    inputFloat("Price:",&price);
    addOffer(type,destination,departure_date,price,l);
}

void updateOfferUi(Offer_list *l) {
    char old_type[12], old_destination[22], new_type[12], new_destination[22], new_departure_date[12];
    float new_price;

    printf("Old type:");
    fgets(old_type, sizeof(old_type), stdin);
    old_type[strcspn(old_type, "\n")] = '\0';
    clearBuffer(old_type);
    printf("Old destination:");
    fgets(old_destination, sizeof(old_destination), stdin);
    old_destination[strcspn(old_destination, "\n")] = '\0';
    clearBuffer(old_destination);
    printf("New type:");
    fgets(new_type, sizeof(new_type), stdin);
    new_type[strcspn(new_type, "\n")] = '\0';
    clearBuffer(new_type);
    printf("New destination:");
    fgets(new_destination, sizeof(new_destination), stdin);
    new_destination[strcspn(new_destination, "\n")] = '\0';
    clearBuffer(new_destination);
    printf("New departure date:");
    fgets(new_departure_date, sizeof(new_departure_date), stdin);
    new_departure_date[strcspn(new_departure_date, "\n")] = '\0';
    clearBuffer(new_departure_date);
    inputFloat("New price:",&new_price);
    updateOffer(old_type, old_destination, new_type, new_destination, new_departure_date, new_price, l);

}

void removeOfferUi(Offer_list *l) {
    char type[12],destination[22];
    printf("Type:");
    fgets(type, sizeof(type), stdin);
    type[strcspn(type, "\n")] = '\0';
    clearBuffer(type);
    printf("Destination:");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = '\0';
    clearBuffer(destination);
    removeOffer(type,destination,l);
}

void sortOfferMenu(Offer_list *l) {
    char* command[2];
    char* asc_desc[1];
    printf("1. Sort by price\n");
    printf("2. Sort by destination\n");
    scanf("%s",command);
    clearBuffer(command);
    printf("1. Ascending\n2. Descending\n");
    scanf("%s",asc_desc);
    clearBuffer(asc_desc);
    Offer_list* sorted=NULL;
    if (!strcmp(command,"1")) {
        sorted=sortOffersByPrice(l,strcmp(asc_desc,"1"));
        printOffers(sorted);
        destroyOfferList(sorted);
    }
    else if (!strcmp(command,"2")) {
        sorted=sortOffersByDestination(l,strcmp(asc_desc,"1"));
        printOffers(sorted);
        destroyOfferList(sorted);
    }
    else {
        printf("Invalid command\n");
    }
}

void filterOfferMenu(Offer_list *l) {
    char* command[2];
    printf("1. Filter by destination\n2. Filter by type\n3. Filter by price\n");
    scanf("%s",command);
    clearBuffer(command);
    Offer_list* filtered=NULL;
    if (!strcmp(command,"1")) {
        char destination[22];
        printf("Destination:");
        fgets(destination, sizeof(destination), stdin);
        destination[strcspn(destination, "\n")] = '\0';
        clearBuffer(destination);
        filtered=filterByDestination(l,destination);
        printOffers(filtered);
        destroyOfferList(filtered);
    }
    else if (!strcmp(command,"2")) {
        char type[12];
        printf("Type:");
        fgets(type, sizeof(type), stdin);
        type[strcspn(type, "\n")] = '\0';
        clearBuffer(type);
        filtered=filterByType(l,type);
        printOffers(filtered);
        destroyOfferList(filtered);
    }
    else if (!strcmp(command,"3")) {
        float price;
        inputFloat("Price:",&price);
        filtered=filterByPrice(l,price);
        printOffers(filtered);
        destroyOfferList(filtered);
    }
    else {
        printf("Invalid command\n");
    }
}

void run(Offer_list *l) {
    char cmd[2];
    while (1) {
        printMenu();
        printf(">>");
        scanf("%s",cmd);
        clearBuffer(cmd);
        if (!strcmp(cmd,"1")) {
            addOfferUi(l);
        }
        else if (!strcmp(cmd,"2")) {
            updateOfferUi(l);
        }
        else if (!strcmp(cmd,"3")) {
            removeOfferUi(l);
        }
        else if (!strcmp(cmd,"4")) {
            sortOfferMenu(l);
        }
        else if (!strcmp(cmd,"5")) {
            filterOfferMenu(l);
        }
        else if (!strcmp(cmd,"6")) {
            printOffers(l);
        }
        else if (!strcmp(cmd,"7")) {
            break;
        }
    }
}