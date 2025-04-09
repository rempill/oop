//
// Created by Mihai on 30.03.2025.
//

#include "console.h"

#include "tools.h"
using namespace std;

void Console::add() const {
    string name, ap_type;
    const int ap = getValidatedInt("Apartment number: ");
    cout << "Name: "; getline(cin, name);
    const float area = getValidatedFloat("Area: ");
    cout << "Apartment type: "; getline(cin, ap_type);
    service.add(ap, name, area, ap_type);
}

void Console::del() {
    string name;
    const int ap = getValidatedInt("Apartment number: ");
    cout << "Name: "; getline(cin,name);
    service.del(ap, name);
}

void Console::modify() {
    string name, new_name, ap_type, new_ap_type;
    const int ap = getValidatedInt("Apartment number: ");
    cout << "Name: "; getline(cin, name);
    const int new_ap = getValidatedInt("New apartment number: ");
    cout << "New name: "; getline(cin,new_name);
    const float new_area = getValidatedFloat("New area: ");
    cout << "New apartment type: "; getline(cin, new_ap_type);
    service.modify(ap, name, new_ap, new_name, new_area, new_ap_type);
}

void Console::printAll() const {
    for (const auto& locatar : service.getAll()) {
        cout <<"Apartment: "<<locatar.getAp() << "; Name:" << locatar.getName() << "; Area:" << locatar.getArea() << " m^2; Type:" << locatar.getApType() << endl;
    }
}

void Console::search() const {
    string name;
    const int ap = getValidatedInt("Apartment number: ");
    cout << "Name: "; getline(cin, name);
    const Locatar locatar = service.search(ap, name);
    cout << "Apartment: " << locatar.getAp() << "; Name:" << locatar.getName() << "; Area:" << locatar.getArea() << " m^2; Type:" << locatar.getApType() << endl;
}

void Console::ui_filter() const {
    cout<<"1. Filter by area\n2. Filter by type\n";
    switch (const int cmd=getValidatedInt("Select an option: "); cmd) {
        case 1: filter_area(); break;
        case 2: filter_type(); break;
        default: cout << "Invalid command!\n"; break;
    }
}

void Console::filter_area() const {
    for (const float area=getValidatedFloat("Area: "); const auto& locatar : service.filter_area(area)) {
        cout <<"Apartment: "<<locatar.getAp() << "; Name:" << locatar.getName() << "; Area:" << locatar.getArea() << " m^2; Type:" << locatar.getApType() << endl;
    }
}

void Console::filter_type() const {
    string type;
    cout << "Type: "; getline(cin, type);
    for (const auto& locatar : service.filter_type(type)) {
        cout <<"Apartment: "<<locatar.getAp() << "; Name:" << locatar.getName() << "; Area:" << locatar.getArea() << " m^2; Type:" << locatar.getApType() << endl;
    }
}

void Console::ui_sort() const {
    cout<<"1. Sort by name\n2. Sort by area\n3. Sort by type and area\n";
    switch (const int cmd=getValidatedInt("Select an option: "); cmd) {
        case 1: sort_name(); break;
        case 2: sort_area(); break;
        case 3: sort_type_area(); break;
        default: cout << "Invalid command!\n"; break;
    }
}

void Console::sort_name() const {
    for (const auto& locatar : service.sort_name()) {
        cout <<"Apartment: "<<locatar.getAp() << "; Name:" << locatar.getName() << "; Area:" << locatar.getArea() << " m^2; Type:" << locatar.getApType() << endl;
    }
}

void Console::sort_area() const {
    for (const auto& locatar : service.sort_area()) {
        cout <<"Apartment: "<<locatar.getAp() << "; Name:" << locatar.getName() << "; Area:" << locatar.getArea() << " m^2; Type:" << locatar.getApType() << endl;
    }
}

void Console::sort_type_area() const {
    for (const auto& locatar : service.sort_type_area()) {
        cout <<"Apartment: "<<locatar.getAp() << "; Name:" << locatar.getName() << "; Area:" << locatar.getArea() << " m^2; Type:" << locatar.getApType() << endl;
    }
}

void Console::run() {
    while (true) {
        cout<<"1. Add a new locatar\n2. Delete a locatar\n3. Modify a locatar\n4. Print all locatari\n5. Search apartment\n6. Filter\n7. Sort\n0. Exit\n";
        int cmd; cin >> cmd;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        try {
            switch (cmd) {
                case 1: add(); break;
                case 2: del(); break;
                case 3: modify(); break;
                case 4: printAll(); break;
                case 5: search(); break;
                case 6: ui_filter(); break;
                case 7: ui_sort(); break;
                case 0: return;
                default: cout << "Invalid command!\n"; break;
            }
        } catch (const std::exception& e) {
            cout<<e.what()<<endl;
            cin.clear();
        }
    }
}