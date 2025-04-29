//
// Created by Mihai on 29.03.2025.
//
#include "repo.h"
using namespace std;
Repo::Repo(const vector<Locatar>& locatari) {
    this->locatari = locatari;
}

vector<Locatar> Repo::getAll(){
    return this->locatari;
}

void Repo::add(const Locatar& locatar){
    try {
     auto found=search(locatar.getAp(),locatar.getName());
    } catch (const RepoError&) {
        this->locatari.push_back(locatar);
        return;
    }
    throw RepoError("Locatar already exists!");
}

void Repo::del(const int ap, const std::string& name) {
    auto const inSize= this->locatari.size();
    auto it=ranges::remove_if(this->locatari, [ap, name](const Locatar& locatar) {
        return locatar.getAp() == ap && locatar.getName() == name;
    });
    this->locatari.erase(it.begin(), this->locatari.end());
    if (this->locatari.size() == inSize) {
        throw RepoError("Locatar not found!");
    }
}

Locatar Repo::search(const int ap, const std::string& name) const {
    const auto it= ranges::find_if(this->locatari, [ap,name](const Locatar& locatar) {
        return locatar.getAp() == ap && locatar.getName() == name;
    });

    if (it!=this->locatari.end()) {
        return *it;
    }

    throw RepoError("Locatar not found!");
}

void Repo::modify(const int ap, const std::string& name, const Locatar& locatar) {
    auto it= ranges::find_if(this->locatari, [ap,name](const Locatar& locatar) {
        return locatar.getAp() == ap && locatar.getName() == name;
    });
    if (it!=this->locatari.end()) {
        *it=locatar;
    } else {
        throw RepoError("Locatar not found!");
    }
}
