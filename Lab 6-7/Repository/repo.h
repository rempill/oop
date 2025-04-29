//
// Created by Mihai on 29.03.2025.
//

#pragma once
#include "locatar.h"
//#include "linked_list.h"
#include <vector>
#include <errors.h>
#include <algorithm>
using std::vector;
class Repo {
private:
    vector <Locatar> locatari;
public:
    //constructor
    Repo() = default;
    explicit Repo(const vector<Locatar>& locatari);

    //getter
    vector<Locatar> getAll();

    //add a new locatar
    void add(const Locatar&);

    //delete a locatar
    void del(int ap, const std::string& name);

    //modify a locatar
    void modify(int ap, const std::string& name, const Locatar&);

    //search apartment
    [[nodiscard]] Locatar search(int ap, const std::string &name) const;

    //destructor
    ~Repo()=default;
};
