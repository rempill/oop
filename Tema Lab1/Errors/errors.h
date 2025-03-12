//
// Created by Mihai on 07.03.2025.
//

#ifndef ERRORS_H
#define ERRORS_H
#pragma once
#include <stdio.h>
void validError(char* message);
//Prints a validation error message
void repoError(char* message);
//Prints a repository error message
void serviceError(char* message);
//Prints a service error message
#endif //ERRORS_H
