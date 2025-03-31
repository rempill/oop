#pragma once
#include <service.h>
#include <iostream>
#include <limits>
#include <ios>
class Console {
    friend class Service;
private:
    Service service;

    //add a new locatar
    void add();

    //delete a locatar
    void del();

    //modify a locatar
    void modify();

    //print all locatari
    void printAll();

    //search apartment
    void search();

    //filter by area
    void filter_area();

    //filter by type
    void filter_type();

    //sort by name
    void sort_name();

    //sort by area
    void sort_area();

    //sort by type and area
    void sort_type_area();

    //runs filter
    void ui_filter();

    //runs sort
    void ui_sort();
public:
    //constructor
    explicit Console(const Service& service) : service(service) {}

    //runs console
    void run();
};


