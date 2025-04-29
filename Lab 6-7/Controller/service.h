#pragma once
#include "repo.h"
#include "validator.h"
#include <map>
#include <memory>

#include "notifications.h"
#include "undo_action.h"

class Service {
private:
    Repo& repo;
    Valid valid;
    Notification notifications;
    vector<std::unique_ptr<UndoAction>> undoActions;
public:
    //constructor
    explicit Service(Repo& repo, Valid valid);

    // Delete copy constructor and copy assignment operator
    Service(const Service&) = delete;
    Service& operator=(const Service&) = delete;

    //add a new locatar
    void add(int ap, const std::string& name, float area, const std::string& ap_type) ;

    //delete a locatar
    void del(int ap, const std::string& name) ;

    //modify a locatar
    void modify(int ap, const std::string& name, int,const std::string&, float, const std::string&) ;

    //get all locatari
    [[nodiscard]] vector<Locatar> getAll() const;

    //search apartment
    [[nodiscard]] Locatar search(int ap, const std::string& name) const;

    //filter by area
    [[nodiscard]] vector<Locatar> filter_area(float area) const;

    //filter by type
    [[nodiscard]] vector<Locatar> filter_type(const std::string &type) const;

    //sort by name
    [[nodiscard]] vector<Locatar> sort_name() const;

    //sort by area
    [[nodiscard]] vector<Locatar> sort_area() const;

    //sort by type and area
    [[nodiscard]] vector<Locatar> sort_type_area() const;

    //surveys the notifications
    [[nodiscard]] std::map<std::string, int> get_survey() const;

    //adds notification
    int add_notification(int ap) ;

    //clears notifications
    int clear_notifications();

    //generates random list using existing apartments
    int generate_random_notifications(int n);

    //get notifications
    [[nodiscard]] std::vector<Locatar> get_notifications() const {
        return notifications.get_notifications();
    }

    //undo function
    void undo();

    //destructor
    ~Service();
};
