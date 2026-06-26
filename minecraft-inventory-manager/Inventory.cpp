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
Inventory::Inventory(int capacity)
{
    this->capacity = capacity;
    this->count = 0;
    this->slot = new Item *[this->capacity]
    { nullptr };
}
Inventory::Inventory() : Inventory(10) {}
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
void Inventory::removeItem(int idx)
{
    if (idx < 0 || idx > this->capacity)
    {
        cout << "Index không hợp lệ!\n";
        return;
    }

    if (!this->slot[idx])
    {
        cout << "Slot " << idx << " trống, không có gì để xoá\n";
        return;
    }

    delete this->slot[idx];
    this->slot[idx] = nullptr;
    this->count--;

    cout << "Đã xoá vật phẩm thành công tại ô " << idx << '\n';
}
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

void Inventory::quickSort(int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    int len = high - low + 1;

    if (*slot[high] < *slot[low])
        swap(slot[high], slot[low]);
    if (*slot[high] < *slot[mid])
        swap(slot[high], slot[mid]);
    if (*slot[mid] < *slot[low])
        swap(slot[mid], slot[low]);

    if (len == 3)
        return;

    auto pivot = slot[mid];
    swap(slot[mid], slot[high - 1]);

    int i = low;
    int j = high - 1;
    while (true)
    {
        while (*slot[++i] < *pivot)
            ;
        while (!(*slot[--j] < *pivot))
            ;

        if (i >= j)
            break;

        swap(slot[i], slot[j]);
    }
    swap(slot[high - 1], slot[i]);

    quickSort(low, i - 1);
    quickSort(i + 1, high);
}
void Inventory::sortInventory()
{
    if (this->count <= 1)
        return;

    Item **temp = new Item *[this->count];
    int j = 0;
    for (int i = 0; i < this->capacity; i++)
    {
        if (this->slot[i])
            temp[j++] = this->slot[i];
    }

    for (int i = 0; i < this->count; i++)
        this->slot[i] = temp[i];
    for (int i = this->count; i < this->capacity; i++)
        this->slot[i] = nullptr;

    quickSort(0, this->count - 1);

    delete[] temp;
    temp = nullptr;
}
Item **Inventory::getSlot() const
{
    return this->slot;
}