#include <stdio.h>
#include "Consola/consola.h"
#include "Domeniu/list_tranzactie.h"
#include <stdlib.h>
#include "./Teste/teste.h"
int main(void){
    // Service* service=createService();
    // runn(service);
    // destroyService(service);
    runAllTests();
    return 0;
}

//code coverage 92% la tranzactie.c deoarece sunt 2 cazuri cu pointer NULL