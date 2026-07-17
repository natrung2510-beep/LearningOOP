#pragma once
#include <iostream>

class MyIntArray
{
private:
    int *data;
    unsigned int size;

public:
    // CONSTRUCTORs
    MyIntArray(int size = 0);
    MyIntArray(int size, int default_value);

    // OPERATORs
    // assigment
    MyIntArray &operator=(const MyIntArray &other);
    // plus
    MyIntArray operator+(const MyIntArray &other);
    // prefix increment
    MyIntArray &operator++();
    // postfix increment
    MyIntArray operator++(int);
    // input
    friend std::istream &operator>>(std::istream &in, MyIntArray &array);
    // output
    friend std::ostream &operator<<(std::ostream &out, const MyIntArray &array);
};
