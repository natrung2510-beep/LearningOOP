#pragma once
#include <iostream>
#include "Item.h"

class Weapon : public Item
{
protected:
    float damage;

public:
    // CONSTRUCTORS
    Weapon(int rarity, int quantity, const char *name, float damage);
    Weapon(const Weapon &other);
    // OPERATIONS
    void printInfor(std::ostream &outDevice) const override;
    void useItem() override;
    Item *clone() const override;
};