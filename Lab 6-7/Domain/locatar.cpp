//
// Created by Mihai on 29.03.2025.
//

#include "locatar.h"

Locatar::Locatar()
{
    this->ap = 0;
    this->area = 0.0;
    this->name = "";
    this->ap_type = "";
}

Locatar::Locatar(const int ap, std::string name, const float area, std::string ap_type)
{
    this->ap = ap;
    this->area = area;
    this->name = std::move(name);
    this->ap_type = std::move(ap_type);
}

Locatar& Locatar::operator=(const Locatar& rhs) {
    this->ap = rhs.ap;
    this->area = rhs.area;
    this->name = rhs.name;
    this->ap_type = rhs.ap_type;
    std::cout<<"operator= called\n";
    return *this;
}

bool Locatar::operator==(const Locatar& rhs) const noexcept{
    return this->ap == rhs.ap && this->area == rhs.area && this->name == rhs.name && this->ap_type == rhs.ap_type;
}

Locatar::Locatar(const Locatar& locatar) {
    this->ap = locatar.ap;
    this->area = locatar.area;
    this->name = locatar.name;
    this->ap_type = locatar.ap_type;
    std::cout<<"copy constructor called\n";
}

int Locatar::getAp() const {
    return this->ap;
}

float Locatar::getArea() const {
    return this->area;
}

const std::string& Locatar::getName() const {
    return this->name;
}

const std::string& Locatar::getApType() const {
    return this->ap_type;
}

void Locatar::setAp(const int ap) {
    this->ap = ap;
}

void Locatar::setArea(const float area) {
    this->area = area;
}

void Locatar::setName(const std::string& name) {
    this->name = name;
}

void Locatar::setApType(const std::string& ap_type) {
    this->ap_type = ap_type;
}

Locatar::~Locatar() {
    std::cout<<"destructor called\n";
}
