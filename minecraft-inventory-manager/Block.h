#pragma once
#include <iostream>
#include "Item.h"

class Block : public Item
{
public:
    // CONSTRUCTORS
    Block(int rarity, int quantity, const char *name);
    Block(const Block &other);

    // OVERRIDE
    void useItem() override;
    Item *clone() const override;
    void printInfor(std::ostream &outDevice) const override;
};