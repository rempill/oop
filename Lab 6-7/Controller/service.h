#pragma once
#include "repo.h"
#include "validator.h"

class Service {
private:
    Repo& repo;
    Valid valid;
public:
    //constructor
    explicit Service(Repo& repo, Valid valid);

    //add a new locatar
    void add(int ap, const std::string& name, float area, const std::string& ap_type) const;

    //delete a locatar
    void del(int ap, const std::string& name);

    //modify a locatar
    void modify(int ap, const std::string& name, int,const std::string&, float, const std::string&);

    //get all locatari
    LinkedList<Locatar> getAll() const;

    //search apartment
    Locatar search(int ap, const std::string& name) const;

    //filter by area
    LinkedList<Locatar> filter_area(float area) const;

    //filter by type
    LinkedList<Locatar> filter_type(const std::string &type) const;

    //sort by name
    LinkedList<Locatar> sort_name() const;

    //sort by area
    LinkedList<Locatar> sort_area() const;

    //sort by type and area
    LinkedList<Locatar> sort_type_area() const;

    //destructor
    ~Service();
};