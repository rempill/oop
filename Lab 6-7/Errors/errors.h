#pragma once
#include <string>
#include <exception>

// Errors/errors.h
#pragma once
#include <exception>
#include <utility>
#include <string>

class BaseError : public std::exception {
protected:
    std::string message;
public:
    explicit BaseError(std::string  msg) : message(std::move(msg)) {}
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};

class RepoError : public BaseError {
public:
    explicit RepoError(const std::string& msg) : BaseError("Repo Error: " + msg) {}
};

class ValidatorError : public BaseError {
public:
    explicit ValidatorError(const std::string& msg) : BaseError("Validator Error: " + msg) {}
};

class ServiceError : public BaseError {
public:
    explicit ServiceError(const std::string& msg) : BaseError("Service Error: " + msg) {}
};