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
    if (search(locatar.getAp(), locatar.getName()) != -1) {
        throw RepoError("Locatar already exists!");
    }
    this->locatari.push_back(locatar);
}

void Repo::del(int ap, std::string name) {
    const int poz=search(ap, name);
    if (poz == -1) {
        throw RepoError("Locatar not found!");
    }
    this->locatari.erase(this->locatari.begin() + poz);
}

int Repo::search(int ap, std::string name) const {
    for (int i = 0; i < this->locatari.size(); i++) {
        if (this->locatari[i].getAp() == ap && this->locatari[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

void Repo::modify(const int ap, const std::string& name, const Locatar& locatar) {
    const int poz = search(ap, name);
    if (poz == -1) {
        throw RepoError("Locatar not found!");
    }
    this->locatari[poz] = locatar;
}

Repo::~Repo() {
    this->locatari.clear();
}
