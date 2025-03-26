//
// Created by Mihai on 26.03.2025.
//

#include "test_validator.h"

void testValidator() {
    Tranzactie* test=createTranzactie(0,11,"Intrare","haha");
    assert(validare_Tranazctie(*test)==1);
    test->ziua=1;
    test->suma=-1;
    assert(validare_Tranazctie(*test)==2);
    test->suma=2;
    strcpy(test->tip,"Intre");
    assert(validare_Tranazctie(*test)==3);
    strcpy(test->tip,"Intrare");
    strcpy(test->descriere,"");
    assert(validare_Tranazctie(*test)==4);
    destroyTranzactie(test);
}