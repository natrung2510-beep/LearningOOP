#pragma once
#include <iostream>
#include "Item.h"

class Potion : public Item
{
public:
    // CONSTRUCTORS
    Potion(int rarity, int quantity, const char *name) : Item(name, rarity, quantity) {}
    Potion(const Potion &other) : Item(other) {}
    // OVERRIDE
    void printInfor(std::ostream &outDevice) const override;
    void useItem() override;
    Item *clone() const override;
};