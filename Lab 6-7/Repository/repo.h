//
// Created by Mihai on 29.03.2025.
//

#pragma once
#include "locatar.h"
#include <vector>
#include <errors.h>
class Repo {
private:
    std::vector<Locatar> locatari;
public:
    //constructor
    Repo() = default;
    explicit Repo(const std::vector<Locatar>& locatari);

    //getter
    std::vector<Locatar> getAll();

    //add a new locatar
    void add(const Locatar&);

    //delete a locatar
    void del(int ap, std::string name);

    //modify a locatar
    void modify(int ap, const std::string& name, const Locatar&);

    //search apartment
    int search(int ap, std::string name) const;

    //destructor
    ~Repo();
};
