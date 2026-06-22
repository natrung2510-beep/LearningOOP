#include <iostream>
#include <string>
#include "Zombie.h"
using namespace std;

float Zombie::calculateDamage(float damage) const
{
    return damage;
}
void Zombie::displayInformation() const
{
    cout << "Current zombie " << name << " information:\n";
    cout << "-Remaining HP: " << hp << '\n';
}