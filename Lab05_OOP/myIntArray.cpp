#include <iostream>
#include <string>
#include "myIntArray.h"
#include <stdexcept>
using namespace std;

// CONSTRUCTORs
MyIntArray::MyIntArray(int size, int default_value)
{
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