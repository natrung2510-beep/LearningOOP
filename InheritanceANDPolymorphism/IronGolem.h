#pragma once
#include <iostream>
#include <algorithm>
#include "Entity.h"

class IronGolem : public Entity
{
protected:
    float armor;
    float calculateDamage(float damage) const override;

public:
    IronGolem(const std::string &name, float hp, float armor) : Entity(name, hp), armor(armor)
    {
        std::cout << "A Iron golem named " << name << " is generated successfully!\n";
    }

    void displayInformation() const override;

    ~IronGolem()
    {
        std::cout << "A Iron golem named " << name << " is removed successfully!\n";
    }
};