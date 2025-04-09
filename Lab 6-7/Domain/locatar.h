#pragma once
#include <string>
#include <iostream>
class Locatar {
private:
    int ap;
    float area;
    std::string name, ap_type;
public:
    //constructor
    Locatar();
    Locatar(int ap, std::string name, float area, std::string ap_type);

    //assignment operator
    Locatar& operator=(const Locatar& locatar);

    //equality operator
    bool operator==(const Locatar& locatar) const noexcept;

    //copy constructor
    Locatar(const Locatar& locatar);

    //getters
    [[nodiscard]] int getAp() const;
    [[nodiscard]] float getArea() const;
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] const std::string& getApType() const;

    //setters
    void setAp(int ap);
    void setArea(float area);
    void setName(const std::string& name);
    void setApType(const std::string& ap_type);

    //destructor
    ~Locatar();
};