#pragma once
#include <cstring>
#include <iostream>

class Item
{
protected:
    char *name;
    int rarity;
    int quantity;

public:
    Item(const char *name, int rarity, int quantity)
    {
        this->rarity = rarity;
        this->quantity = quantity;

        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    Item(const Item &other)
    {
        this->rarity = other.rarity;
        this->quantity = other.quantity;
        this->name = new char[strlen(name) + 1];
        strcpy(other.name, this->name);
    }
    virtual void useItem() = 0;
    virtual Item *clone() const = 0;

    virtual ~Item()
    {
        delete[] name;
    }
};