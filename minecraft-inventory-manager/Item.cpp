#include <iostream>
#include "Item.h"
#include <cstring>
#include <typeinfo>
#include <stdexcept>
#include <format>
using namespace std;
// OPERATOR OVERLOADINGS
bool Item::operator==(const Item &other) const
{
    return (typeid(*this) == typeid(other)) && (strcmp(this->name, other.name) == 0) && (this->rarity == other.rarity);
}

Item *Item::operator+(Item &other) const
{
    if (!(*this == other))
        throw invalid_argument("Lỗi! Không thể gộp 2 vật phẩm khác nhau!\n");

    if (other.quantity + this->quantity > this->maxStack)
        throw runtime_error("Stack Overflow!\n");

    Item *newItem = this->clone();
    newItem->quantity += other.quantity;
    return newItem;
}
void Item::printInfor(ostream &outDevice) const
{
    outDevice << "[" << this->name << " | Hiếm: "
              << this->rarity << " | SL: " << this->quantity;
}
ostream &operator<<(ostream &outDevice, const Item &other)
{
    other.printInfor(outDevice);
    return outDevice;
}
bool Item::operator<(const Item &other) const
{
    if (this->rarity != other.rarity)
        return this->rarity > other.rarity;
    return this->quantity > other.quantity;
}
// CONSTRUCTORS
Item::Item(const char *name, int rarity, int quantity, int maxStack)
{
    this->rarity = rarity;
    this->quantity = quantity;
    this->maxStack = maxStack;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
Item::Item(const Item &other)
{
    this->rarity = other.rarity;
    this->quantity = other.quantity;
    this->maxStack = maxStack;
    this->name = new char[strlen(other.name) + 1];
    strcpy(other.name, this->name);
}
// OPERATIONS

int Item::getQuantity() const
{
    return quantity;
}
int Item::getMaxStack() const
{
    return maxStack;
}
void Item::setQuantity(int newVal)
{
    if (newVal < 0)
        newVal = 0;
    else if (newVal > this->maxStack)
        newVal = this->maxStack;
    this->quantity = newVal;
}
char *Item::getName() const
{
    return this->name;
}
