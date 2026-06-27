#include <iostream>
using namespace std;

template <typename T>
class Box
{
protected:
    T item;

public:
    Box(const T &item);

    T getItem() const;
};

template <typename T>
Box<T>::Box(const T &item) : item(item);

template <typename T>
T Box<T>::getItem() const
{
    return item;
}

int main()
{

    cin.get();
}