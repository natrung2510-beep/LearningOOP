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
    Fraction(const Fraction &other);

    // OPERATIONS
    // Calculation tools
    Fraction plus(const Fraction &other) const;
    Fraction substract(const Fraction &other) const;
    Fraction multiply(const Fraction &other) const;
    Fraction divide(const Fraction &other) const;
    // getter
    int getNum() const noexcept;
    int getDenom() const noexcept;
    // setter
    void setNum(int num);
    void setDenom(int denom);
    // Input
    void inputFraction();
    // Output
    void output_Decimal() const noexcept;
    void output_Fraction() const noexcept;

    // DESTRUCTOR
    ~Fraction();
};