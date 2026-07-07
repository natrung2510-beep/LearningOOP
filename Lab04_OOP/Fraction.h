#pragma once

class Fraction
{
private:
    int *numerator;
    int *denominator;

public:
    // CONSTRUCTORs
    Fraction(int num, int denom);
    Fraction();
    Fraction(int num);
};