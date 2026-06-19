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
    Fraction operator+(const Fraction &other) const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator*(const Fraction &other) const;
    Fraction operator/(const Fraction &other) const;
    Fraction &operator=(const Fraction &other);
    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator+=(const Fraction &other);
    bool operator<(const Fraction &other) const;
    bool operator>(const Fraction &other) const;
    bool operator>=(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;
    bool operator==(const Fraction &other) const;
    bool operator!=(const Fraction &other) const;
    // Fraction plus(Fraction a);
    // Fraction substract(Fraction a);
    // Fraction multiply(Fraction a);
    // Fraction divide(Fraction a);
    friend istream &operator>>(istream &inDevice, Fraction &f);
    friend ostream &operator<<(ostream &outDevice, const Fraction &f);
};
