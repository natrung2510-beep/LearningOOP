#include <iostream>
#include "Block.h"
using namespace std;

// OVERRIDE
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

// CONSTRUCTORS
Block::Block(int rarity, int quantity, const char *name) : Item(name, rarity, quantity, 64) {}
Block::Block(const Block &other) : Item(other) {}
