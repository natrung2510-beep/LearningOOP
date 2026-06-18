#include <iostream>
#include "Fraction.h"
#include <windows.h>
#include <string>
using namespace std;

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Fraction f1;
    Fraction f2;

    cout << "Mời nhập phân số thứ nhất:\n";
    f1.inputFraction();
    cout << "Phân số thứ nhất là: ";
    f1.outputFraction();
    cout << '\n';

    cout << "Mời nhập phân số thứ hai:\n";
    f2.inputFraction();
    cout << "Phân số thứ hai là: ";
    f2.outputFraction();
    cout << '\n';
    cout << '\n';

    Fraction sum = f1.plus(f2);
    sum.simplify();
    cout << "Tổng của hai phân số là: ";
    sum.outputFraction();
    sum.outputDecimal();

    Fraction substraction = f1.substract(f2);
    substraction.simplify();
    cout << "Hiệu của hai phân số là: ";
    substraction.outputFraction();
    substraction.outputDecimal();

    Fraction product = f1.multiply(f2);
    product.simplify();
    cout << "Tích của hai phân số là: ";
    product.outputFraction();
    product.outputDecimal();

    Fraction quotient = f1.divide(f2);
    quotient.simplify();
    cout << "Thương của hai phân số là: ";
    quotient.outputFraction();
    quotient.outputDecimal();

    return 0;
}