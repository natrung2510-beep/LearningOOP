#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Box
{
protected:
    T item;

public:
    Box(const T &item);

    T getItem() const;

    friend ostream &operator<<(ostream &outDevice, const Box<T> &item);
};

template <typename T>
ostream &operator<<(ostream &outDevice, const Box<T> &b)
{
    outDevice << "The treasure includes: " << b.item << '\n';
    return outDevice;
}

template <typename T>
Box<T>::Box(const T &item) : item(item) {}

template <typename T>
T Box<T>::getItem() const
{
    return item;
}

template <typename T>
class MagicBox : public Box<T>
{
public:
    MagicBox(const T &item) : Box(T) {}
    void showItem();
    {
        cout << "The treasure includes: " << this->item << '\n';
    }

    friend ostream &operator<<(ostream &outDevice, const MagicBox<T> &item);
};

template <typename T>
void MagicBox<T>::showItem()
{
    cout << "The treasure includes: " << this->item << '\n';
}

template <typename T>
ostream &operator<<(ostream &outDevice, const MagicBox<T> &mb)
{
    outDevice << "The treasure includes: " << mb.item << '\n';
    return outDevice;
}
int main()
{
    Box<int> pocket(5e6);
    MagicBox<string> treasure("Gomu Gomu no Mi");
    cout << pocket;
    cout << treasure;
    cin.get();
}