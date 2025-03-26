//
// Created by kissk on 3/19/2025.
//
#include "teste_domeniu.h"

void testCreateList() {
    List* lista = createList(destroyList,copyList);
    assert(lista != NULL);
    assert(lista->lungime == 0);
    assert(lista->capacity == 2);
    assert(lista->elements != NULL);
    resize(lista);
    assert(lista->capacity == 4);
    destroyList(lista);
}

void ruleazaTesteCreateList() {
    testCreateList();
}