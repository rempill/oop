#pragma once
#include <cassert>

#include "locatar.h"
#include "repo.h"
#include "service.h"
#include "validator.h"
#include "errors.h"
#include "linked_list.h"

class Tests {
public:
    static void test();
private:
    static void test_domain();
    static void test_repo();
    static void test_service();

    static void test_validator();
};