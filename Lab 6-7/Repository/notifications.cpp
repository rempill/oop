#include "notifications.h"


int Notification::add_notification(const Locatar &locatar) {
    notifications.push_back(locatar);
    return static_cast<int>(notifications.size());
}

int Notification::clear_notifications() {
    notifications.clear();
    return static_cast<int>(notifications.size());
}

int Notification::generate_random_notifications(std::vector<Locatar>& locatari,const int n) {
    notifications.clear();
    std::vector<int> indices(locatari.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::ranges::shuffle(indices, std::mt19937(std::random_device()()));
    for (int i = 0; i < n; ++i) {
        notifications.push_back(locatari[indices[i]]);
    }
    return static_cast<int>(notifications.size());
}