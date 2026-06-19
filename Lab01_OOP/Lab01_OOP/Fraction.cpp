#include <iostream>
#include <string>
#include <cmath>
#include "Fraction.h"
using namespace std;

// void Fraction::inputFraction()
// {
//     cout << "Mời nhập tử số:";
//     cin >> numerator;
//     cout << "Mời nhập mẫu số:";
//     cin >> denominator;
// }
// void Fraction::outputFraction()
// {
//     cout << numerator << '/' << denominator << '\n';
// }
// void Fraction::outputDecimal()
// {
//     double output;
//     output = (double)numerator / denominator;
//     cout << output << '\n';
// }
void Fraction::simplify()
{
    int a = abs(numerator);
    int b = abs(denominator);

    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    numerator /= a;
    denominator /= a;

    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
}
// Fraction Fraction::plus(Fraction a)
// {
//     Fraction res;
//     res.numerator = numerator * a.denominator + denominator * a.numerator;
//     res.denominator = denominator * a.denominator;

//     return res;
// }
// Fraction Fraction::substract(Fraction a)
// {
//     Fraction res;
//     res.numerator = numerator * a.denominator - denominator * a.numerator;
//     res.denominator = denominator * a.denominator;

//     return res;
// }
// Fraction Fraction::multiply(Fraction a)
// {
//     Fraction res;
//     res.numerator = numerator * a.numerator;
//     res.denominator = denominator * a.denominator;

//     return res;
// }
// Fraction Fraction::divide(Fraction a)
// {
//     Fraction res;
//     res.numerator = numerator * a.denominator;
//     res.denominator = denominator * a.numerator;

//     return res;
// }
Fraction Fraction::operator+(const Fraction &other) const
{
    Fraction res;
    res.numerator = this->numerator * other.denominator + this->denominator * other.numerator;
    res.denominator = this->denominator * other.denominator;
    res.simplify();
    return res;
}
Fraction Fraction::operator-(const Fraction &other) const
{
    Fraction res;
    res.numerator = this->numerator * other.denominator - this->denominator * other.numerator;
    res.denominator = this->denominator * other.denominator;
    res.simplify();
    return res;
}
Fraction Fraction::operator*(const Fraction &other) const
{
    Fraction res;
    res.numerator = this->numerator * other.numerator;
    res.denominator = this->denominator * other.denominator;
    res.simplify();
    return res;
}
Fraction Fraction::operator/(const Fraction &other) const
{
    Fraction res;
    res.numerator = this->numerator * other.denominator;
    res.denominator = this->denominator * other.numerator;
    res.simplify();
    return res;
}
Fraction &Fraction::operator=(const Fraction &other)
{
    if (this != &other)
    {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    return *this;
}
bool Fraction::operator<(const Fraction &other) const
{
    return this->numerator * other.denominator < this->denominator * other.numerator;
}
bool Fraction::operator>(const Fraction &other) const
{
    return this->numerator * other.denominator > this->denominator * other.numerator;
}
bool Fraction::operator<=(const Fraction &other) const
{
    return this->numerator * other.denominator <= this->denominator * other.numerator;
}
bool Fraction::operator>=(const Fraction &other) const
{
    return this->numerator * other.denominator >= this->denominator * other.numerator;
}
bool Fraction::operator==(const Fraction &other) const
{
    return this->numerator * other.denominator == this->denominator * other.numerator;
}
bool Fraction::operator!=(const Fraction &other) const
{
    return this->numerator * other.denominator != this->denominator * other.numerator;
}
istream &operator>>(istream &inDevice, Fraction &f)
{
    inDevice >> f.numerator >> f.denominator;
    f.simplify();
    return inDevice;
}
ostream &operator<<(ostream &outDevice, const Fraction &f)
{
    outDevice << f.numerator << '/' << f.denominator << '\n';
    outDevice << "Viết dưới dạng thập phân: " << double(f.numerator) / f.denominator << '\n';
    return outDevice;
}
Fraction &Fraction::operator++()
{
    this->numerator += this->denominator;
    simplify();
    return *this;
}
Fraction Fraction::operator++(int)
{
    Fraction clone = *this;

    ++(*this);
    // this->numerator += this->denominator;
    // this->simplify();
    return clone;
}