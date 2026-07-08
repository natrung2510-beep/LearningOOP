#include <iostream>
#include "Fraction.h"
#include <stdexcept>
using namespace std;

// CONSTRUCTORs
Fraction::Fraction(int num, int denom)
{
    if (denom == 0)
    {
        denom = 1;
        throw invalid_argument("Mẫu số phải khác 0!\n");
    }
    this->numerator = new int(num);
    this->denominator = new int(denom);
}
Fraction::Fraction(int num) : Fraction(num, 1) {}
Fraction::Fraction() : Fraction(1) {}

// OPERATIONS
// Calculation tools
Fraction Fraction::plus(const Fraction &other) const {}
Fraction Fraction::substract(const Fraction &other) const {}
Fraction Fraction::multiply(const Fraction &other) const {}
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
void Fraction::setNum() {}
void Fraction::setDenom() {}
// Input
void Fraction::inputFraction() {}
// Output
void Fraction::output_Decimal() const {}
void Fraction::output_Fraction() const {}

// DESTRUCTOR
Fraction::~Fraction() {}