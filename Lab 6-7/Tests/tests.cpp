#include <stdexcept>
#include "tests.h"

void Tests::test() {
    test_domain();
    test_repo();
    test_service();
    test_validator();
    test_notification();
}

void Tests::test_domain() {
    auto locatar=Locatar();
    assert(locatar.getAp()==0);
    assert(locatar.getArea()==0.0);
    assert(locatar.getName().empty());
    assert(locatar.getApType().empty());
    locatar.setAp(1);
    locatar.setArea(1.0);
    locatar.setName("Mihai");
    locatar.setApType("1 camera");
    assert(locatar.getAp()==1);
    assert(locatar.getArea()==1.0);
    assert(locatar.getName()=="Mihai");
    assert(locatar.getApType()=="1 camera");
    auto locatar2=Locatar(1, "Mihai", 1.0, "1 camera");
    assert(locatar==locatar2);
    auto locatar3=Locatar(locatar); //called cpy constructor here
    assert(locatar==locatar3);
    auto locatar4=Locatar();
    locatar4=locatar;
    assert(locatar==locatar4);
}

void Tests::test_validator() {
    constexpr auto valid=Valid();
    auto locatar=Locatar(1, "Mihai", 11.1, "1 camera");
    try {
        valid.valid(locatar);
        assert(true);
    } catch (const ValidatorError&) {
        assert(false);
    }
    assert(valid.valid_ap(1).empty());
    assert(valid.valid_name("Mihai").empty());
    assert(valid.valid_area(11.1).empty());
    assert(valid.valid_type("1 camera").empty());
    locatar=Locatar(-1, "Mihai1", 1.0, "1 camera1");
    try {
        valid.valid(locatar);
        assert(false);
    } catch (const ValidatorError&) {
        assert(true);
    }
    }

void Tests::test_repo() {
    auto repo=Repo();
    assert(repo.getAll().empty());
    auto locatar=Locatar(1, "Mihai", 11.1, "1 camera");
    repo.add(locatar);
    assert(repo.getAll().size()==1);
    // assert(repo.getAll()[0]==locatar);
    // auto locatar1=Locatar(2, "Dani", 25, "penthouse");
    // repo.add(locatar1);
    // assert(repo.getAll().size()==2);
    // try {
    //     repo.add(locatar);
    //     assert(false);
    // } catch (const RepoError&) {
    //     assert(true);
    // }
    // assert(repo.search(1,"Mihai")==0);
    // assert(repo.search(3,"Dani")==-1);
    // auto locatar3=Locatar(3, "Draxem", 50, "3 camere");
    // try {
    //     repo.modify(5, "Mihai", locatar3);
    //     assert(false);
    // } catch (const RepoError&) {
    //     assert(true);
    // }
    // repo.modify(1, "Mihai", locatar3);
    // assert(repo.getAll()[0]==locatar3);
    // repo.del(3, "Draxem");
    // assert(repo.getAll().size()==1);
    // try {
    //     repo.del(3,    "Draxem");
    //     assert(false);
    // } catch (const RepoError&) {
    //     assert(true);
    // }
}

void Tests::test_service() {
    vector<Locatar> locatars;
    auto repo=Repo(locatars);
    constexpr auto valid=Valid();
    auto service=Service(repo, valid);
    try {
        auto l=service.getAll();
        assert(false);
    } catch (const ServiceError&) {
        assert(true);
    }
    auto locatar=Locatar(1, "Mihai", 11.1, "1 camera");
    service.add(1, "Mihai", 11.1, "1 camera");
    assert(service.getAll().size()==1);
    assert(service.search(1,"Mihai")==locatar);
    auto locatar1=Locatar(2, "Dani", 25, "penthouse");
    service.add(2, "Dani", 25, "penthouse");
    assert(service.getAll().size()==2);
    try {
        service.add(1, "Mihai", 11.1, "1 camera");
        assert(false);
    } catch (const RepoError&) {
        assert(true);
    }
    assert(service.search(1, "Mihai")==locatar);
    try {
        auto l=service.search(0,"Mihai");
        assert(false);
    } catch (const ValidatorError&) {
        assert(true);
    }
    try {
        auto l=service.search(4,"Mihai");
        assert(false);
    } catch (const RepoError&) {
        assert(true);
    }
    try {
        auto l=service.filter_area(1);
        assert(false);
    } catch (const ValidatorError&) {
        assert(true);
    }
    try {
        auto l=service.filter_area(11.2);
        assert(false);
    } catch (const ServiceError&) {
        assert(true);
    }
    auto filtered=service.filter_area(25);
    assert(filtered.size()==1);
    auto it=filtered.begin();
    assert(*it==locatar1);
    try {
        auto l=service.filter_type("getout");
        assert(false);
    } catch (const ValidatorError&) {
        assert(true);
    }
    try {
        auto l=service.filter_type("4 camere");
        assert(false);
    } catch (const ServiceError&) {
        assert(true);
    }
    auto filtered1=service.filter_type("penthouse");
    assert(filtered1.size()==1);
    auto it1=filtered1.begin();
    assert(*it1==locatar1);
    auto sorted1=service.sort_area();
    assert(sorted1.size()==2);
    auto it2=sorted1.begin();
    assert(*it2==locatar);
    ++it2;
    assert(*it2==locatar1);
    auto sorted2=service.sort_name();
    assert(sorted2.size()==2);
    auto it3=sorted2.begin();
    assert(*it3==locatar1);
    ++it3;
    assert(*it3==locatar);
    auto sorted3=service.sort_type_area();
    assert(sorted3.size()==2);
    auto it4=sorted3.begin();
    assert(*it4==locatar);
    ++it4;
    assert(*it4==locatar1);
    service.del(1, "Mihai");
    assert(service.getAll().size()==1);
    try {
        service.del(1, "Mihai");
        assert(false);
    } catch (const RepoError&) {
        assert(true);
    }
    try {
        service.del(0,"Mihai)");
        assert(false);
    } catch (const ValidatorError&) {
        assert(true);
    }
    service.modify(2,"Dani",3,"Draxem",50,"3 camere");
    assert(service.search(3,"Draxem")==Locatar(3, "Draxem", 50, "3 camere"));
    try {
        service.modify(2,"Dani",3,"Draxem",50,"3 camere");
        assert(false);
    } catch (const RepoError&) {
        assert(true);
    }
    try {
        service.modify(0,"Mihai",3,"Draxem",50,"3 camere");
        assert(false);
    } catch (const ValidatorError&) {
        assert(true);
    }
    service.add(1, "Mihai", 11.1, "3 camere");
    service.add(2, "Dani", 25, "penthouse");
    auto map=service.get_survey();
    assert(map.size()==2);
    assert(map["3 camere"]==2);
    assert(map["penthouse"]==1);
}

void Tests::test_notification() {
    auto repo=Repo();
    constexpr auto valid=Valid();
    auto service=Service(repo, valid);
    assert(service.clear_notifications()==0);
    try {
        service.add_notification(-1);
        assert(false);
    } catch (const ServiceError&) {
        assert(true);
    }
    try {
        service.generate_random_notifications(5);
        assert(false);
    } catch (const ServiceError&) {
        assert(true);
    }
    service.add(1, "Mihai", 11.1, "1 camera");
    service.add(2, "Dani", 25, "penthouse");
    service.add(3, "Draxem", 50, "3 camere");
    assert(service.add_notification(1)==1);
    assert(service.add_notification(2)==2);
    assert(service.clear_notifications()==0);
    assert(service.generate_random_notifications(2)==2);
    try {
        service.add_notification(5);
        assert(false);
    } catch (const ServiceError&) {
        assert(true);
    }
    try {
        service.generate_random_notifications(5);
        assert(false);
    } catch (const ServiceError&) {
        assert(true);
    }
}