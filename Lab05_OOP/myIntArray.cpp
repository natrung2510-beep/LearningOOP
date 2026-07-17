#include <iostream>
#include <string>
#include "myIntArray.h"
#include <stdexcept>
using namespace std;

// CONSTRUCTORs
MyIntArray::MyIntArray(int size, int default_value)
{
    if (size < 0)
        throw invalid_argument("Kích thước mảnng không thể là một số âm!");
    if (size > 0)
        data = new int[size]{default_value};
    else
        data = nullptr;
}
MyIntArray::MyIntArray(const MyIntArray &other)
{
    delete[] this->data;
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
    int newSize = other.size;
    this->data = new int[newSize];
    for (int i = 0; i < newSize; i++)
        this->data[i] = other.data[i];
    return *this;
}
// plus
MyIntArray MyIntArray::operator+(const MyIntArray &other)
{
    MyIntArray res;
    for (int i = 0; i < res.size; i++)
        res.data[i] = this->data[i] + other.data[i];

    return res;
}
// prefix increment
MyIntArray &MyIntArray::operator++() {}
// postfix increment
MyIntArray MyIntArray::operator++(int) {}
// input
istream &operator>>(istream &in, MyIntArray &array) {}
// output
ostream &operator<<(ostream &out, const MyIntArray &array) noexcept {}