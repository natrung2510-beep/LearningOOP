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

    cin >> f1;
    cout << f1;
    cin >> f2;
    cout << f2;

    // cout << "Mời nhập phân số thứ hai:\n";
    // f2.inputFraction();
    // cout << "Phân số thứ hai là: ";
    // f2.outputFraction();
    // cout << '\n';
    // cout << '\n';

    // Fraction sum = f1.plus(f2);
    Fraction sum = f1 + f2;
    cout << "Tổng của hai phân số là: ";
    cout << sum;
    // sum.outputFraction();
    // sum.outputDecimal();

    // Fraction substraction = f1.substract(f2);
    Fraction substraction = f1 - f2;
    cout << "Hiệu của hai phân số là: ";
    cout << substraction;
    // substraction.outputFraction();
    // substraction.outputDecimal();

    // Fraction product = f1.multiply(f2);
    Fraction product = f1 * f2;
    cout << "Tích của hai phân số là: ";
    cout << product;
    // product.outputFraction();
    // product.outputDecimal();

    // Fraction quotient = f1.divide(f2);
    Fraction quotient = f1 / f2;
    cout << "Thương của hai phân số là: ";
    cout << quotient;
    // quotient.outputFraction();
    // quotient.outputDecimal();

    // Comparison
    cout << "f1 > f2 ?\n";
    cout << (f1 > f2 ? "YES\n" : "NO\n");
    cout << "f1 < f2 ?\n";
    cout << (f1 < f2 ? "YES\n" : "NO\n");
    cout << "f1 >= f2 ?\n";
    cout << (f1 >= f2 ? "YES\n" : "NO\n");
    cout << "f1 <= f2 ?\n";
    cout << (f1 <= f2 ? "YES\n" : "NO\n");
    cout << "f1 == f2 ?\n";
    cout << (f1 == f2 ? "YES\n" : "NO\n");
    cout << "f1 != f2 ?\n";
    cout << (f1 != f2 ? "YES\n" : "NO\n");

    return 0;
}