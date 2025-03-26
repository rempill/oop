#include "teste.h"
void runAllTests() {
    ruleazaTesteCreateList();
    runRepoTests();
    runServiceTests();
    testValidator();
}