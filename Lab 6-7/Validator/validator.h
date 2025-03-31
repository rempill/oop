#pragma once
#include <locatar.h>
#include <errors.h>
class Valid {
public:
    void valid(const Locatar&) const;
    [[nodiscard]] std::string valid_ap(int) const noexcept;
    [[nodiscard]] std::string valid_name(const std::string&) const noexcept;
    [[nodiscard]] std::string valid_area(float) const noexcept;
    [[nodiscard]] std::string valid_type(const std::string&) const noexcept;
};
