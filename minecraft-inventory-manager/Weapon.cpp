#include <iostream>
#include "Weapon.h"
using namespace std;
// OVERRIDE
void Weapon::useItem()
{
    cout << name << " gây ra " << damage << " sát thương!\n";
}
Item *Weapon::clone() const
{
    return new Weapon(*this);
}
void Weapon::printInfor(ostream &outDevice) const
{
    Item::printInfor(outDevice);
    outDevice << " | ST: " << this->damage << "]";
}
// CONSTRUCTORS
Weapon::Weapon(int rarity, int quantity, const char *name, float damage) : Item(name, rarity, quantity)
{
    this->damage = damage;
}
Weapon::Weapon(const Weapon &other) : Item(other)
{
    this->damage = other.damage;
}