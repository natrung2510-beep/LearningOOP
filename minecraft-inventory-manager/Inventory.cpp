#include <iostream>
#include <cstring>
#include "Inventory.h"
#include "Item.h"
#include <algorithm>
using namespace std;

// CONSTRUCTORS
Inventory::Inventory(const Inventory &other)
{
    this->capacity = other.capacity;
    this->count = other.count;

    this->slot = new Item *[this->capacity]
    { nullptr };
    for (int i = 0; i < this->capacity; i++)
        this->slot[i] = (other.slot[i]) ? other.slot[i]->clone() : nullptr;
}
// DESTRUCTOR
Inventory::~Inventory()
{
    for (int i = 0; i < this->capacity; i++)
        delete this->slot[i];
    delete[] this->slot;
    this->slot = nullptr;
}
// OPERATORS
Inventory &Inventory::operator=(const Inventory &other)
{
    if (this != &other)
    {
        for (int i = 0; i < this->capacity; i++)
            delete this->slot[i];
        delete[] this->slot;

        this->capacity = other.capacity;
        this->count = other.count;

        this->slot = new Item *[this->capacity]
        { nullptr };
        for (int i = 0; i < this->capacity; i++)
            this->slot[i] = (other.slot[i]) ? other.slot[i]->clone() : nullptr;
    }

    return *this;
}
