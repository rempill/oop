//
// Created by Mihai on 30.03.2025.
//

#include "validator.h"

#include <algorithm>

void Valid::valid(const Locatar& locatar) const {
    std::string errors;
    errors+=valid_ap(locatar.getAp())+valid_name(locatar.getName())+valid_area(locatar.getArea())+valid_type(locatar.getApType());
    if (!errors.empty()) {
        throw ValidatorError(errors);
    }
}

std::string Valid::valid_ap(const int ap) const noexcept {
    if (ap<=0) {
        return "Apartment number must be a positive integer!\n";
    }
    return "";
}

std::string Valid::valid_name(const std::string& name) const noexcept {
    if (!name.empty() && std::ranges::all_of(name, [](char c) { return isalpha(c) || c == ' '; })) {
        return "";
    }
    return "Name must contain only letters and spaces!\n";
}

std::string Valid::valid_area(const float area) const noexcept {
    if (area<11.0){
        return "Area must be greater than 11.0 m^2!\n";
    }
    return "";
}

std::string Valid::valid_type(const std::string& ap_type) const noexcept {
    if (ap_type == "1 camera" || ap_type == "2 camere" || ap_type == "3 camere" || ap_type == "4 camere" || ap_type == "5 camere" || ap_type == "penthouse") {
        return "";
    }
    return "Apartment type must be 1 camera, 2 camere, 3 camere, 4 camere, 5 camere or penthouse!\n";
}

