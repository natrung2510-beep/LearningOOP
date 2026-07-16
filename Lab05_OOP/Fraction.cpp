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
Fraction &Fraction::operator=(const Fraction &other)
{
    if (this == &other)
        return;
    delete this->numerator;
    delete this->denominator;
    this->numerator = new int(*other.numerator);
    this->denominator = new int(*other.denominator);

    return *this;
}

// arithmetic
Fraction Fraction::operator+(const Fraction &other) const
{
    Fraction res;
    *res.numerator = (*this->numerator) * (*other.denominator) + (*this->denominator) * (*other.numerator);
    *res.denominator = (*this->denominator) * (*other.denominator);
    return res;
}
Fraction Fraction::operator-(const Fraction &other) const
{
    Fraction res;
    *res.numerator = (*this->numerator) * (*other.denominator) - (*this->denominator) * (*other.numerator);
    *res.denominator = (*this->denominator) * (*other.denominator);
    return res;
}
Fraction Fraction::operator*(const Fraction &other) const
{
    Fraction res;
    *res.numerator = (*this->numerator) * (*other.numerator);
    *res.denominator = (*this->denominator) * (*other.denominator);
    return res;
}
Fraction Fraction::operator/(const Fraction &other) const
{
    if (*other.numerator == 0)
        throw invalid_argument("Phân số chia phải khác 0!\n");

    Fraction res;
    *res.numerator = (*this->numerator) * (*other.denominator);
    *res.denominator = (*this->denominator) * (*other.numerator);
    return res;
}

// comparison
bool Fraction::operator<(const Fraction &other) const
{
    return (*this->numerator) * (*other.denominator) < (*this->denominator) * (*other.numerator);
}
bool Fraction::operator>(const Fraction &other) const
{
    return (*this->numerator) * (*other.denominator) > (*this->denominator) * (*other.numerator);
}
bool Fraction::operator<=(const Fraction &other) const
{
    return !operator>(other);
}
bool Fraction::operator>=(const Fraction &other) const
{
    return !operator<(other);
}
bool Fraction::operator==(const Fraction &other) const
{
    return (*this->numerator) * (*other.denominator) == (*this->denominator) * (*other.numerator);
}
bool Fraction::operator!=(const Fraction &other) const
{
    return !operator==(other);
}

// arithmetic assignment
Fraction &Fraction::operator+=(const Fraction &other)
{
    *this->numerator = (*this->numerator) * (*other.denominator) + (*other.numerator) * (*this->denominator);
    *this->denominator = (*this->denominator) * (*other.denominator);
    return *this;
}
Fraction &Fraction::operator-=(const Fraction &other)
{
    *this->numerator = (*this->numerator) * (*other.denominator) - (*other.numerator) * (*this->denominator);
    *this->denominator = (*this->denominator) * (*other.denominator);
    return *this;
}
Fraction &Fraction::operator*=(const Fraction &other)
{
    *this->numerator = (*this->numerator) * (*other.numerator);
    *this->denominator = (*this->denominator) * (*other.denominator);
    return *this;
}
Fraction &Fraction::operator/=(const Fraction &other)
{
    if (*other.numerator == 0)
        throw invalid_argument("Phân số chia phải khác 0!\n");

    *this->numerator = (*this->numerator) * (*other.denominator);
    *this->denominator = (*this->denominator) * (*other.numerator);
    return *this;
}

// increment
Fraction Fraction::operator++()
{
    Fraction res(*this);
    *this->numerator = (*this->numerator) + (*this->denominator);
    return res;
}
Fraction &Fraction::operator++(int) {}
// decrement
Fraction Fraction::operator--()
{
    Fraction res(*this);
    *this->numerator = (*this->numerator) - (*this->denominator);
    return res;
}
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