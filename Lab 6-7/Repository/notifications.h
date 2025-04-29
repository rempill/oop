#pragma once
#include "locatar.h"
#include "errors.h"
#include <random>
#include <algorithm>
#include <vector>
class Notification {
private:
    std::vector<Locatar> notifications;
public:
    Notification() = default;

    //adds notification
    int add_notification(const Locatar &);

    //clears notifications
    int clear_notifications();

    //generates random list using existing apartments
    int generate_random_notifications(std::vector<Locatar>&,int);

    //get notifications
    [[nodiscard]] const std::vector<Locatar>& get_notifications() const {
        return notifications;
    }

    //returns size
    [[nodiscard]] int size() const {
        return static_cast<int>(notifications.size());
    }
};