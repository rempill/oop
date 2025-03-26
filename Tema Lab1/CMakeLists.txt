cmake_minimum_required(VERSION 3.28)
project(Tema_Lab1 C)

set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
include_directories(${CMAKE_SOURCE_DIR})

add_executable(Tema_Lab1 main.c
        Domain/offer.h
        Domain/offer_list.h
        Repository/repo.h
        Repository/repo.c
        Domain/offer_list.c
        Errors/errors.h
        Validator/validate_offer.h
        Validator/validate_offer.c
        Controller/service.h
        Controller/service.c
        Ui/console.h
        Ui/console.c
        Tests/test_domain.h
        Tests/test_domain.c
        Tests/tests.c
        Tests/tests.h
        Tests/test_repo.c
        Tests/test_repo.h
        Tests/test_service.c
        Tests/test_service.h
        Errors/errors.h
        Tests/test_validator.c
        Tests/test_validator.h)
