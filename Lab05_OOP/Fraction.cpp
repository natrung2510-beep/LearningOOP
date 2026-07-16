#include <iostream>
#include <stdexcept>
#include <string>
#include "Fraction.h"
using namespace std;

// CONSTRUCTORs
Fraction::Fraction(int num, int denom) {}
Fraction::Fraction(int num) {}
Fraction::Fraction() {}
Fraction::Fraction(const Fraction &other) {}

// OPERATORs
// assignment
Fraction &Fraction::operator=(const Fraction &other) {}

// arithmetic
Fraction Fraction::operator+(const Fraction &other) const {}
Fraction Fraction::operator-(const Fraction &other) const {}
Fraction Fraction::operator*(const Fraction &other) const {}
Fraction Fraction::operator/(const Fraction &other) const {}

// comparison
bool Fraction::operator<(const Fraction &other) const {}
bool Fraction::operator>(const Fraction &other) const {}
bool Fraction::operator<=(const Fraction &other) const {}
bool Fraction::operator>=(const Fraction &other) const {}
bool Fraction::operator==(const Fraction &other) const {}
bool Fraction::operator!=(const Fraction &other) const {}

// arithmetic assignment
Fraction &Fraction::operator+=(const Fraction &other) {}
Fraction &Fraction::operator-=(const Fraction &other) {}
Fraction &Fraction::operator*=(const Fraction &other) {}
Fraction &Fraction::operator/=(const Fraction &other) {}

// increment
Fraction Fraction::operator++() {}
Fraction &Fraction::operator++(int) {}
// decrement
Fraction Fraction::operator--() {}
Fraction &Fraction::operator--(int) {}

// input
istream operator>>(istream &in, Fraction &f) {}
// output
ostream operator<<(ostream &out, const Fraction &f) noexcept {}

// DESTRUCTOR
Fraction::~Fraction() {}