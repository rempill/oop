//
// Created by Mihai on 29.03.2025.
//

#pragma once
#include "locatar.h"
#include "linked_list.h"
#include <errors.h>
class Repo {
private:
    LinkedList <Locatar> locatari;
public:
    //constructor
    Repo() = default;
    explicit Repo(const LinkedList<Locatar>& locatari);

    //getter
    LinkedList<Locatar> getAll();

    //add a new locatar
    void add(const Locatar&);

    //delete a locatar
    void del(int ap, const std::string& name);

    //modify a locatar
    void modify(int ap, const std::string& name, const Locatar&) const;

    //search apartment
    [[nodiscard]] LinkedList<Locatar>::iterator search(int ap, const std::string &name) const;

    //destructor
    ~Repo()=default;
};
