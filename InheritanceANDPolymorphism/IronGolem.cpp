#include <iostream>
#include <string>
#include <algorithm>
#include "IronGolem.h"
using namespace std;

float IronGolem::calculateDamage(float damage) const
{
    return std::max(damage - armor, 0.0f);
}
void IronGolem::displayInformation() const
{
    cout << "Current iron golem " << name << " information:\n";
    cout << "-Remaining HP: " << hp << '\n';
}