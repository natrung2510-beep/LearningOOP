#include <iostream>
#include "Item.h"
#include <cstring>
#include <typeinfo>
#include <stdexcept>
#include <format>
using namespace std;

bool Item::operator==(const Item &other) const
{
    return (typeid(*this) == typeid(other)) && (strcmp(this->name, other.name) == 0) && (this->rarity == other.rarity);
}

Item *Item::operator+(const Item &other) const
{
    if (!(*this == other))
        throw invalid_argument("Lỗi! Không thể gộp 2 vật phẩm khác nhau!\n");

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