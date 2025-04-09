//
// Created by Mihai on 29.03.2025.
//
#include "repo.h"
using namespace std;
Repo::Repo(const LinkedList<Locatar>& locatari) {
    this->locatari = locatari;
}

LinkedList<Locatar> Repo::getAll(){
    return LinkedList{locatari};
}

void Repo::add(const Locatar& locatar){
    if (search(locatar.getAp(), locatar.getName()) != LinkedList<Locatar>::end()) {
        throw RepoError("Locatar already exists!");
    }
    this->locatari.push_back(locatar);
}

void Repo::del(const int ap, const std::string& name) {
    const auto it=search(ap, name);
    if (it == LinkedList<Locatar>::end()) {
        throw RepoError("Locatar not found!");
    }
    this->locatari.erase(it);
}

LinkedList<Locatar>::iterator Repo::search(const int ap, const std::string & name) const {
    for (auto it=locatari.begin(); it!=LinkedList<Locatar>::end(); ++it) {
        if (it->getName() == name && it->getAp() == ap) {
            return it;
        }
    }
    return LinkedList<Locatar>::end();
}

void Repo::modify(const int ap, const std::string& name, const Locatar& locatar) const {
    const auto it = search(ap, name);
    if (it == LinkedList<Locatar>::end()) {
        throw RepoError("Locatar not found!");
    }
    *it = locatar;
}
