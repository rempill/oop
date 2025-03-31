//
// Created by Mihai on 30.03.2025.
//

#include "service.h"

#include <algorithm>

Service::Service(Repo& repo, Valid valid) : repo(repo), valid(valid) {}

void Service::add(const int ap, const std::string& name, const float area, const std::string& ap_type) const {
    Locatar locatar(ap, name, area, ap_type);
    valid.valid(locatar);
    repo.add(locatar);
}

void Service::del(const int ap, const std::string& name) {
    if (valid.valid_ap(ap).empty() && valid.valid_name(name).empty()) {
        repo.del(ap, name);
        return;
    }
    throw ValidatorError(valid.valid_ap(ap)+valid.valid_name(name));
}

void Service::modify(const int ap, const std::string& name, const int new_ap, const std::string& new_name, const float new_area, const std::string& new_ap_type) {
    Locatar locatar(new_ap, new_name, new_area, new_ap_type);
    valid.valid(locatar);
    if (valid.valid_ap(ap).empty()&& valid.valid_name(name).empty()) {
        repo.modify(ap,name,locatar);
        return;
    }
    throw ValidatorError(valid.valid_ap(ap)+valid.valid_name(name));
}

std::vector<Locatar> Service::getAll() const {
    std::vector<Locatar> locatari = repo.getAll();
    if (locatari.size()==0) {
        throw ServiceError("No locatari in the repository!\n");
    }
    return locatari;
}

Locatar Service::search(const int ap, const std::string& name) const {
    if (valid.valid_ap(ap).empty() && valid.valid_name(name).empty()) {
        const int poz = repo.search(ap, name);
        if (poz == -1) {
            throw ServiceError("Locatar not found!\n");
        }
        return repo.getAll()[poz];
    }
    throw ValidatorError(valid.valid_ap(ap)+valid.valid_name(name));
}

std::vector<Locatar> Service::filter_area(const float area) const {
    if (valid.valid_area(area).empty()) {
        std::vector<Locatar> locatari = repo.getAll();
        std::vector<Locatar> result;
        for (const auto& locatar : locatari) {
            if (locatar.getArea() == area) {
                result.push_back(locatar);
            }
        }
        if (result.empty()) {
            throw ServiceError("No locatari with the given area!\n");
        }
        return result;
    }
    throw ValidatorError(valid.valid_area(area));
}

std::vector<Locatar> Service::filter_type(const std::string& type) const {
    if (valid.valid_type(type).empty()) {
        std::vector<Locatar> locatari = repo.getAll();
        std::vector<Locatar> result;
        for (const auto& locatar : locatari) {
            if (locatar.getApType() == type) {
                result.push_back(locatar);
            }
        }
        if (result.empty()) {
            throw ServiceError("No locatari with the given type!\n");
        }
        return result;
    }
    throw ValidatorError(valid.valid_type(type));
}

std::vector<Locatar> Service::sort_name() const {
    std::vector<Locatar> locatari = repo.getAll();
    std::ranges::sort(locatari, [](const Locatar& locatar1, const Locatar& locatar2) {
        return locatar1.getName() < locatar2.getName();
    });
    return locatari;
}

std::vector<Locatar> Service::sort_area() const {
    std::vector<Locatar> locatari = repo.getAll();
    std::ranges::sort(locatari, [](const Locatar& locatar1, const Locatar& locatar2) {
        return locatar1.getArea() < locatar2.getArea();
    });
    return locatari;
}

std::vector<Locatar> Service::sort_type_area() const {
    std::vector<Locatar> locatari = repo.getAll();
    std::ranges::sort(locatari, [](const Locatar& locatar1, const Locatar& locatar2) {
        return locatar1.getApType() < locatar2.getApType() || (locatar1.getApType() == locatar2.getApType() && locatar1.getArea() < locatar2.getArea());
    });
    return locatari;
}

Service::~Service() = default;
