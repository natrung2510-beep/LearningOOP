#include <iostream>
using namespace std;

template <typename T>
class Box
{
protected:
    T item;

public:
    Box(const T &item) : item(item);

    T getItem() const
    {
        return item;
    }
};
int main()
{

    cin.get();
}