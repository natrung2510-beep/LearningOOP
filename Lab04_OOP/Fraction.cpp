#include <iostream>
#include "Fraction.h"
#include <stdexcept>
using namespace std;

// CONSTRUCTORs
Fraction::Fraction(int num, int denom)
{
    if (denom == 0)
        throw invalid_argument("Mẫu số phải khác 0!\n");

    this->numerator = new int(num);
    this->denominator = new int(denom);
}
Fraction::Fraction(int num) : Fraction(num, 1) {}
Fraction::Fraction() : Fraction(1) {}

// OPERATIONS
// Calculation tools
Fraction Fraction::plus(const Fraction &other) const
{
    Fraction res;
    *res.denominator = (*this->denominator) * (*other.denominator);
    *res.denominator = (*this->denominator) * (*other.numerator) + (*other.denominator) * (*this->numerator);
    return res;
}
Fraction Fraction::substract(const Fraction &other) const
{
    Fraction res;
    *res.denominator = (*this->denominator) * (*other.denominator);
    *res.denominator = (*this->numerator) * (*other.denominator) - (*other.numerator) * (*this->denominator);
    return res;
}
Fraction Fraction::multiply(const Fraction &other) const
{
    Fraction res;
    *res.denominator = (*this->denominator) * (*other.denominator);
    *res.denominator = (*this->numerator) * (*other.numerator);
    return res;
}
Fraction Fraction::divide(const Fraction &other) const {}
// getter
int *Fraction::getNum() const noexcept
{
    return this->numerator;
}
int *Fraction::getDenom() const noexcept
{
    return this->denominator;
}
// setter
void Fraction::setNum(int num)
{
    *numerator = num;
}
void Fraction::setDenom(int denom)
{
    if (denom == 0)
        throw invalid_argument("Mẫu số phải khác 0!\n");

    if (denom < 0)
    {
        denom = -denom;
        *numerator = -*numerator;
    }
    *denominator = denom;
}
// Input
void Fraction::inputFraction() {}
// Output
void Fraction::output_Decimal() const {}
void Fraction::output_Fraction() const {}

// DESTRUCTOR
Fraction::~Fraction() {}