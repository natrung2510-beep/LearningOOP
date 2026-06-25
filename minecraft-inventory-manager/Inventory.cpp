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
// OPERATIONS
Item *Inventory::addItem(Item *newItem)
{
    int tombstone = -1;
    for (int i = 0; i < this->capacity; i++)
    {

        if (tombstone == -1 && !this->slot[i])
            tombstone = i;

        if (this->slot[i] && *this->slot[i] == *newItem)
        {
            int canAdd = this->slot[i]->getMaxStack() - this->slot[i]->getQuantity();
            if (canAdd > 0)
            {
                int feasible = min(canAdd, newItem->getQuantity());
                this->slot[i]->setQuantity(this->slot[i]->getQuantity() + feasible);
                newItem->setQuantity(newItem->getQuantity() - feasible);

                if (newItem->getQuantity() == 0)
                {
                    delete newItem;
                    newItem = nullptr;
                    return nullptr;
                }
            }
        }
    }
    if (tombstone != -1)
    {
        this->slot[tombstone] = newItem;
        this->count++;
        return nullptr;
    }

    cout << "[Hệ thống]: Túi đồ đầy, vật phẩm bị rớt ra ngoài!\n";
    return newItem;
}
