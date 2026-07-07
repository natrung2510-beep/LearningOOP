#include <iostream>
#include "Fraction.h"
using namespace std;

// CONSTRUCTORs
Fraction::Fraction(int num, int denom) {}
Fraction::Fraction() {}
Fraction::Fraction(int num) {}

// OPERATIONS
// Calculation tools
Fraction Fraction::plus(const Fraction &other) const {}
Fraction Fraction::substract(const Fraction &other) const {}
Fraction Fraction::multiply(const Fraction &other) const {}
Fraction Fraction::divide(const Fraction &other) const {}
// getter
int Fraction::getNum() const noexcept {}
int Fraction::getDenom() const noexcept {}
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