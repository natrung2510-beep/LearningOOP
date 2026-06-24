#pragma once
#include <cstring>
#include <iostream>

class Item
{
protected:
    char *name;
    int rarity;
    int quantity;
    int maxStack;

public:
    // CONSTRUCTORS
    Item(const char *name, int rarity, int quantity, int maxStack);
    Item(const Item &other);

    // PVFs
    virtual void useItem() = 0;
    virtual Item *clone() const = 0;

    // VFs
    virtual void printInfor(std::ostream &outDevice) const;

    // DESTUCTORS
    virtual ~Item()
    {
        delete[] name;
    }
    // OPERATORS
    bool operator==(const Item &other) const;

    Item *operator+(Item &other) const;

    friend std::ostream &operator<<(std::ostream &outDevice, const Item &other);
};