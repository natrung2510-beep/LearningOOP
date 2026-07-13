#include <iostream>
#include <stdexcept>
#include "Fraction.h"
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    cout << "--- 1. TEST KHỞI TẠO ---\n";
    Fraction f1;
    cout << "Mặc định: ";
    f1.output_Fraction();
    Fraction f2(5);
    cout << "1 tham số (5): ";
    f2.output_Fraction();
    Fraction f3(1, 2);
    cout << "2 tham số (1, 2): ";
    f3.output_Fraction();
    Fraction f4(f3);
    cout << "Copy từ (1/2): ";
    f4.output_Fraction();

    cout << "\n--- 2. TEST TÍNH TOÁN (a = 1/2, b = 3/4) ---\n";
    Fraction a(1, 2);
    Fraction b(3, 4);

    Fraction sum = a.plus(b);
    Fraction diff = a.substract(b);
    Fraction mul = a.multiply(b);
    Fraction div = a.divide(b);

    cout << "Cộng (a + b) = ";
    sum.output_Fraction();
    cout << "Trừ  (a - b) = ";
    diff.output_Fraction();
    cout << "Nhân (a * b) = ";
    mul.output_Fraction();
    cout << "Chia (a / b) = ";
    div.output_Fraction();

    cout << "\n--- 3. TEST XUẤT THẬP PHÂN ---\n";
    cout << "1/2 ra thập phân: ";
    a.output_Decimal();
    cout << "3/4 ra thập phân: ";
    b.output_Decimal();

    cout << "\n--- 4. TEST BẪY LỖI MẪU SỐ BẰNG 0 ---\n";
    try
    {
        Fraction fErr(5, 0);
    }
    catch (const exception &e)
    {
        cout << "=> Đã bắt được lỗi: " << e.what();
    }
}