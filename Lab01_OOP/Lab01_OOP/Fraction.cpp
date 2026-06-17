#include <iostream>
#include <string>
#include <cmath>
#include "Fraction.h"
using namespace std;

void Fraction::inputFraction()
{
    cout << "Mời nhập tử số:";
    cin >> numerator;
    cout << "Mời nhập mẫu số:";
    cin >> denominator;
}
void Fraction::outputFraction()
{
    cout << numerator << '/' << denominator << '\n';
}
void Fraction::outputDecimal()
{
    double output;
    output = (double)numerator / denominator;
    cout << output << '\n';
}
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
}
Fraction Fraction::plus(Fraction a)
{
    Fraction res;
    res.numerator = numerator * a.denominator + denominator * a.numerator;
    res.denominator = denominator * a.denominator;

    return res;
}
Fraction Fraction::substract(Fraction a)
{
    Fraction res;
    res.numerator = numerator * a.denominator - denominator * a.numerator;
    res.denominator = denominator * a.denominator;

    return res;
}
Fraction Fraction::multiply(Fraction a)
{
    Fraction res;
    res.numerator = numerator * a.numerator;
    res.denominator = denominator * a.denominator;

    return res;
}
Fraction Fraction::divide(Fraction a)
{
    Fraction res;
    res.numerator = numerator * a.denominator;
    res.denominator = denominator * a.numerator;

    return res;
}