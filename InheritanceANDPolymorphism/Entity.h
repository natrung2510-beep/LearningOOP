#pragma once
#include <iostream>
#include <string>

class Entity
{
protected:
    std::string name;
    float hp;

    virtual float calculateDamage(float damage) const = 0;

public:
    Entity(const std::string &name, float hp) : name(name), hp(hp) {}

    float takeDamage(float damage);
    virtual void displayInformation() const = 0;

    virtual ~Entity()
    {
        std::cout << "Delele entity successfully!\n";
    }
};