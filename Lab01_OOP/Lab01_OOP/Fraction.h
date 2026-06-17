#pragma once

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    void inputFraction();
    void outputFraction();
    void outputDecimal();
    void simplify();
    Fraction plus(Fraction a);
    Fraction substract(Fraction a);
    Fraction multiply(Fraction a);
    Fraction divide(Fraction a);
};