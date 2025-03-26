cmake_minimum_required(VERSION 3.28)
project(Lab2_4 C)

set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
add_executable(Lab2_4 main.c
        Validator/validator_tranzacti.c
        Validator/validator_tranzacti.h
        Domeniu/list_tranzactie.c
        Domeniu/tranzactie.h
        Domeniu/list_tranzactie.h
        Repo/repo.h
        Repo/repo.c
        Erori/erors.c
        Erori/erors.h
        Servis/servis.c
        Servis/servis.h
        Consola/consola.c
        Consola/consola.h
        Teste/teste.c
        Teste/teste_domeniu.c
        Teste/teste_repo.c
        "Teste/teste servis.cpp"
        Teste/teste_domeniu.h
        Teste/teste_repo.h
        Teste/teste.h
        Teste/teste_servis.c
        Teste/teste_servis.h
        Teste/test_validator.c
        Teste/test_validator.h
        Domeniu/tranzactie.c
)
