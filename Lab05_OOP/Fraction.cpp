#include <iostream>
#include <stdexcept>
#include <string>
#include "Fraction.h"
using namespace std;

// CONSTRUCTORs
Fraction::Fraction(int num, int denom)
{
    if (denom == 0)
        throw invalid_argument("Mẫu số phải khác 0!\n");

    if (denom < 0)
    {
        num = -num;
        denom = -denom;
    }

    *this->numerator = num;
    *this->denominator = denom;
}
Fraction::Fraction(int num) : Fraction(num, 1) {}
Fraction::Fraction() : Fraction(1, 1) {}
Fraction::Fraction(const Fraction &other) : Fraction(*other.numerator, *other.denominator) {}

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
Fraction::~Fraction()
{
    delete denominator;
    denominator = nullptr;
    delete numerator;
    numerator = nullptr;
}