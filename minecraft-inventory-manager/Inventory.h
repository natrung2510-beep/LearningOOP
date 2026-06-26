#include "Item.h"

class Inventory
{
protected:
    Item **slot;
    int capacity;
    int count;

    void quickSort(int low, int high);

public:
    // CONSTRUCTORS
    Inventory(const Inventory &other);
    Inventory(int capacity);
    Inventory();
    // OPERATIONS
    Item *addItem(Item *item);
    void removeItem(int idx);
    void sortInventory();

    Item **getSlot() const;
    // OPERATORS
    Inventory &operator=(const Inventory &other);
    friend std::ostream &operator<<(ostream &outDevice, const Inventory &inv);
    // DESTRUCTORS
    ~Inventory();
};