//
// Created by Mihai on 30.03.2025.
//

#include "service.h"

#include <algorithm>
#include <random>

using std::ranges::copy_if;
using std::ranges::sort;
Service::Service(Repo& repo, Valid valid) : repo(repo), valid(valid) {}

void Service::add(const int ap, const std::string& name, const float area, const std::string& ap_type) {
    Locatar locatar(ap, name, area, ap_type);
    valid.valid(locatar);
    repo.add(locatar);
    undoActions.push_back(std::make_unique<UndoAdd>(repo, locatar));
}

void Service::del(const int ap, const std::string& name) {
    if (valid.valid_ap(ap).empty() && valid.valid_name(name).empty()) {
        Locatar locatar=repo.search(ap, name);
        repo.del(ap, name);
        undoActions.push_back(std::make_unique<UndoDel>(repo, locatar));
        return;
    }
    throw ValidatorError(valid.valid_ap(ap)+valid.valid_name(name));
}

void Service::modify(const int ap, const std::string& name, const int new_ap, const std::string& new_name, const float new_area, const std::string& new_ap_type) {
    Locatar locatar(new_ap, new_name, new_area, new_ap_type);
    valid.valid(locatar);
    if (valid.valid_ap(ap).empty()&& valid.valid_name(name).empty()) {
        Locatar old_locatar=repo.search(ap, name);
        repo.modify(ap,name,locatar);
        undoActions.push_back(std::make_unique<UndoModify>(repo, old_locatar, new_ap, new_name));
        return;
    }
    throw ValidatorError(valid.valid_ap(ap)+valid.valid_name(name));
}

vector<Locatar> Service::getAll() const {
    vector<Locatar> locatari = repo.getAll();
    if (locatari.empty()) {
        throw ServiceError("No locatari in the repository!\n");
    }
    return locatari;
}

Locatar Service::search(const int ap, const std::string& name) const {
    if (valid.valid_ap(ap).empty() && valid.valid_name(name).empty()) {
        return repo.search(ap, name);
    }
    throw ValidatorError(valid.valid_ap(ap)+valid.valid_name(name));
}

vector<Locatar> Service::filter_area(const float area) const {
    if (valid.valid_area(area).empty()) {
            vector<Locatar> filtered;
            copy_if(repo.getAll(),
            std::back_inserter(filtered), [area](const Locatar& locatar) {
                return locatar.getArea() == area;
            });
        if (filtered.empty()) {
            throw ServiceError("No locatari with the given area!\n");
        }
        return filtered;
    }
    throw ValidatorError(valid.valid_area(area));
}

vector<Locatar> Service::filter_type(const std::string& type) const {
    if (valid.valid_type(type).empty()) {
        vector<Locatar> result;
        copy_if(repo.getAll(),std::back_inserter(result), [type](const Locatar& locatar) {
            return locatar.getApType() == type;
        });
        if (result.empty()) {
            throw ServiceError("No locatari with the given type!\n");
        }
        return result;
    }
    throw ValidatorError(valid.valid_type(type));
}

vector<Locatar> Service::sort_name() const {
    vector<Locatar> sorted = repo.getAll();
    sort(sorted, [](const Locatar& a, const Locatar& b) {
        return a.getName() < b.getName();
    });
    return sorted;
}

vector<Locatar> Service::sort_area() const {
    vector<Locatar> sorted = repo.getAll();
    sort(sorted,[](const Locatar& a, const Locatar& b) {
        return a.getArea() < b.getArea();
    });
    return sorted;
}

vector<Locatar> Service::sort_type_area() const {
    vector<Locatar> sorted = repo.getAll();
    sort(sorted,[](const Locatar& a, const Locatar& b) {
        if (a.getApType() == b.getApType()) {
            return a.getArea() < b.getArea();
        }
        return a.getApType() < b.getApType();
    });
    return sorted;
}

std::map<std::string,int> Service::get_survey() const{
    auto const locatari= repo.getAll();
    std::map<std::string,int> result;
    for (const auto& locatar : locatari) {
        result[locatar.getApType()]++;
    }
    return result;
}

int Service::add_notification(int ap) {
    auto locatari=repo.getAll();
    auto it=std::ranges::find_if(locatari,[ap](const Locatar& locatar) {
        return locatar.getAp() == ap;
    });
    if (it!=locatari.end()) {
        notifications.add_notification(*it);
        return notifications.size();
    }
    throw ServiceError("Locatar not found!\n");
}

int Service::clear_notifications() {
    return notifications.clear_notifications();
}

int Service::generate_random_notifications(const int n) {
    auto locatari=repo.getAll();
    if (locatari.empty()) {
        throw ServiceError("No apartments in the repository!\n");
    }
    if (n > locatari.size()) {
        throw ServiceError("Not enough apartments in the repository!\n");
    }
    return notifications.generate_random_notifications(locatari, n);
}

void Service::undo() {
    if (undoActions.empty()) {
        throw ServiceError("There are no more actions!\n");
    }
    UndoAction* act=undoActions.back().get();
    act->doUndo();
    undoActions.pop_back();
}

Service::~Service() = default;
