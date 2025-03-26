//
// Created by Mihai on 23.03.2025.
//

#ifndef ERRORS_H
#define ERRORS_H
#pragma once
typedef enum {
    SUCCESS=0,
    INVALID_TYPE=1,
    INVALID_DESTINATION=2,
    INVALID_DATE=4,
    INVALID_PRICE=8,
    REPO_ERROR=16,
    VALIDATION_ERROR=32
}Error;
#endif //ERRORS_H
