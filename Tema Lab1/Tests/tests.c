//
// Created by Mihai on 11.03.2025.
//

#include "tests.h"

#include "test_validator.h"

void runTests() {
    runDomainTests();
    runValidatorTests();
    runRepoTests();
    runServiceTests();
}
