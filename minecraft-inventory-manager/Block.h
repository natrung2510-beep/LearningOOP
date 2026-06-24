#pragma once
#include <iostream>
#include "Item.h"

class Block : public Item
{
public:
    Block(int rarity, int quantity, const char *name) : Item(name, rarity, quantity) {}
    Block(const Block &other) : Item(other) {}

    void useItem() override;
    Item *clone() const override;
    void printInfor(std::ostream &outDevice) const override;
};