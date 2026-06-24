#include <iostream>
#include "Potion.h"

using namespace std;

void Potion::useItem()
{
    cout << "Uống thuốc ực ực, hồi phục năng lượng!\n";
}
Item *Potion::clone() const
{
    return new Potion(*this);
}
void Potion::printInfor(ostream &outDevice) const
{
    Item::printInfor(outDevice);
    outDevice << "]";
}
