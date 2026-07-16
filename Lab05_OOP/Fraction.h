#pragma once
#include <iostream>
class Fraction
{
private:
    int *numerator;
    int *denominator;

public:
    // CONSTRUCTORs
    Fraction(int num, int denom);
    Fraction(int num);
    Fraction();
    Fraction(const Fraction &other);

    // OPERATORs
    // assignment
    Fraction &operator=(const Fraction &other);

    // arithmetic
    Fraction operator+(const Fraction &other) const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator*(const Fraction &other) const;
    Fraction operator/(const Fraction &other) const;

    // comparison
    bool operator<(const Fraction &other) const;
    bool operator>(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;
    bool operator>=(const Fraction &other) const;
    bool operator==(const Fraction &other) const;
    bool operator!=(const Fraction &other) const;

    // arithmetic assignment
    Fraction &operator+=(const Fraction &other);
    Fraction &operator-=(const Fraction &other);
    Fraction &operator*=(const Fraction &other);
    Fraction &operator/=(const Fraction &other);

    // increment
    Fraction operator++(int);
    Fraction &operator++();
    // decrement
    Fraction operator--(int);
    Fraction &operator--();

    // input
    friend std::istream operator>>(std::istream &in, Fraction &f);
    // output
    friend std::ostream operator<<(std::ostream &out, const Fraction &f) noexcept;

    // DESTRUCTOR
    ~Fraction();
};