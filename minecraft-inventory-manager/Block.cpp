#include <iostream>
#include "Block.h"

using namespace std;

void Block::useItem()
{
    cout << "Đặt 1 block " << name << " xuống!\n";
}
Item *Block::clone() const
{
    return new Block(*this);
}
void Block::printInfor(ostream &outDevice) const
{
    Item::printInfor(outDevice);
    outDevice << "]";
}
