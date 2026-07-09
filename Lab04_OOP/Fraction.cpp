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
Fraction::Fraction(const Fraction &other) : Fraction(*other.numerator, *other.denominator) {}

// OPERATIONS
// Calculation tools
Fraction Fraction::plus(const Fraction &other) const
{
    int newDenom = (*this->denominator) * (*other.denominator);
    int newNum = (*this->denominator) * (*other.numerator) + (*other.denominator) * (*this->numerator);

    return Fraction(newNum, newDenom);
}

// Phép TRỪ
Fraction Fraction::substract(const Fraction &other) const
{
    int newDenom = (*this->denominator) * (*other.denominator);
    int newNum = (*this->numerator) * (*other.denominator) - (*other.numerator) * (*this->denominator);

    return Fraction(newNum, newDenom);
}

Fraction Fraction::multiply(const Fraction &other) const
{
    int newDenom = (*this->denominator) * (*other.denominator);
    int newNum = (*this->numerator) * (*other.numerator);

    return Fraction(newNum, newDenom);
}

Fraction Fraction::divide(const Fraction &other) const
{
    int newDenom = (*this->denominator) * (*other.numerator);
    int newNum = (*this->numerator) * (*other.denominator);

    return Fraction(newNum, newDenom);
}

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
void Fraction::inputFraction()
{
    int num, denom;
    cout << "Mời nhập tử số:";
    cin >> num;
    setNum(num);
    cout << "\nMời nhập mẫu số:";
    cin >> denom;
    setDenom(denom);
}
// Output
void Fraction::output_Decimal() const
{
    cout << "Phân số của bạn được viết dưới dạng số thập phân là: " << static_cast<float>(*numerator) / *denominator << '\n';
}
void Fraction::output_Fraction() const
{
    cout << "Phân số của bạn là: " << *numerator << "/" << *denominator << '\n';
}

// DESTRUCTOR
Fraction::~Fraction()
{
    delete numerator;
    numerator = nullptr;
    delete denominator;
    denominator = nullptr;
}