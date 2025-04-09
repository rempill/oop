#pragma once
#include "service.h"
#include <iostream>
#include <limits>
#include <ios>
class Console {
    friend class Service;
private:
    Service service;

    //add a new locatar
    void add() const;

    //delete a locatar
    void del();

    //modify a locatar
    void modify();

    //print all locatari
    void printAll() const;

    //search apartment
    void search() const;

    //filter by area
    void filter_area() const;

    //filter by type
    void filter_type() const;

    //sort by name
    void sort_name() const;

    //sort by area
    void sort_area() const;

    //sort by type and area
    void sort_type_area() const;

    //runs filter
    void ui_filter() const;

    //runs sort
    void ui_sort() const;
public:
    //constructor
    explicit Console(const Service& service) : service(service) {}

    //runs console
    void run();
};


