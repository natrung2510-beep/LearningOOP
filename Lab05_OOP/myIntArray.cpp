#include <iostream>
#include <string>
#include "myIntArray.h"
#include <stdexcept>
#include <algorithm>
using namespace std;

// CONSTRUCTORs
MyIntArray::MyIntArray(int size, int default_value)
{
    if (size < 0)
        throw invalid_argument("Kích thước mảnng không thể là một số âm!");

    this->size = size;
    if (size > 0)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = default_value;
    }
    else
        data = nullptr;
}
MyIntArray::MyIntArray(const MyIntArray &other)
{
    this->size = other.size;
    this->data = new int[other.size];
    for (int i = 0; i < other.size; i++)
        this->data[i] = other.data[i];
}

// OPERATORs
// assigment
MyIntArray &MyIntArray::operator=(const MyIntArray &other)
{
    if (this == &other)
        return *this;

    delete[] this->data;
    this->size = other.size;
    this->data = new int[other.size];
    for (int i = 0; i < other.size; i++)
        this->data[i] = other.data[i];
    return *this;
}
// plus
MyIntArray MyIntArray::operator+(const MyIntArray &other) const
{
    int minimum_size = min(this->size, other.size);
    int maximum_size = max(this->size, other.size);
    MyIntArray res(maximum_size);
    for (int i = 0; i < minimum_size; i++)
        res.data[i] = this->data[i] + other.data[i];

    if (maximum_size == minimum_size)
        return res;

    if (this->size == maximum_size)
    {
        for (int i = minimum_size; i < maximum_size; i++)
            res.data[i] = this->data[i];
    }
    else
    {
        for (int i = minimum_size; i < maximum_size; i++)
            res.data[i] = other.data[i];
    }
    return res;
}
// prefix increment
MyIntArray &MyIntArray::operator++()
{
    for (int i = 0; i < this->size; i++)
        this->data[i]++;

    return *this;
}
// postfix increment
MyIntArray MyIntArray::operator++(int)
{
    MyIntArray res(*this);
    for (int i = 0; i < this->size; i++)
        this->data[i]++;

    return res;
}
// input
istream &operator>>(istream &in, MyIntArray &array)
{
    int newSize;
    cout << "Mời nhập kích thước cho mảng:";
    in >> newSize;
    in.ignore();

    if (newSize < 0)
        throw invalid_argument("Kích thước mảnng không thể là một số âm!");

    delete[] array.data;
    array.size = newSize;

    if (array.size == 0)
    {
        cout << "Mảng hiện tại đang rỗng!\n";
        array.data = nullptr;
        return in;
    }

    array.data = new int[array.size];
    for (int i = 0; i < array.size; i++)
    {
        cout << "Mời nhập phần tử thứ " << i + 1 << ":";
        in >> array.data[i];
        in.ignore();
        cout << '\n';
    }
    return in;
}
// output
ostream &operator<<(ostream &out, const MyIntArray &array) noexcept
{
    if (array.size == 0)
    {
        out << "Mảng rỗng []\n";
        return out;
    }
    out << "Mảng hiện tại của bạn có " << array.size << "phần tử.\n";
    out << "[";
    for (int i = 0; i < array.size - 1; i++)
    {
        out << array.data[i] << ", ";
    }
    out << array.data[array.size - 1] << "]\n";
    return out;
}

// DESTRUCTOR
MyIntArray::~MyIntArray()
{
    delete[] data;
    data = nullptr;
}