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
        data = new int[size];
    else
        data = nullptr;
    for (int i = 0; i < size; i++)
        data[i] = default_value;
}

// OPERATORs
// assigment
MyIntArray &MyIntArray::operator=(const MyIntArray &other) {}
// plus
MyIntArray MyIntArray::operator+(const MyIntArray &other) {}
// prefix increment
MyIntArray &MyIntArray::operator++() {}
// postfix increment
MyIntArray MyIntArray::operator++(int) {}
// input
istream &operator>>(istream &in, MyIntArray &array) {}
// output
ostream &operator<<(ostream &out, const MyIntArray &array) {}