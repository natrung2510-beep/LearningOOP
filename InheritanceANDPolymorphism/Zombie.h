#pragma once
#include <iostream>
#include "Entity.h"

class Zombie : public Entity
{
protected:
    float calculateDamage(float damage) const override;

public:
    Zombie(const std::string &name, float hp) : Entity(name, hp)
    {
        std::cout << "A Zombie named " << name << " is generated successfully!\n";
    }

    void displayInformation() const override;
    ~Zombie()
    {
        std::cout << "A Zombie named " << name << " is removed successfully!\n";
    }
};