#include <iostream>
#include <stdexcept>
#include "Fraction.h"
#include "myIntArray.h"

using namespace std;

void testFraction()
{
    cout << "--- KIỂM TRA LỚP PHÂN SỐ (FRACTION) ---\n";
    try
    {
        Fraction frac1, frac2;
        cout << "[Nhập phân số 1]\n";
        cin >> frac1;
        cout << "[Nhập phân số 2]\n";
        cin >> frac2;

        cout << "\n1. CÁC PHÉP TOÁN SỐ HỌC (+, -, *, /):\n";
        Fraction sumFrac = frac1 + frac2;
        cout << "Tổng (frac1 + frac2): " << sumFrac << "\n";
        Fraction diffFrac = frac1 - frac2;
        cout << "Hiệu (frac1 - frac2): " << diffFrac << "\n";
        Fraction prodFrac = frac1 * frac2;
        cout << "Tích (frac1 * frac2): " << prodFrac << "\n";
        Fraction quotFrac = frac1 / frac2;
        cout << "Thương (frac1 / frac2): " << quotFrac << "\n";

        cout << "\n2. CÁC PHÉP SO SÁNH (==, !=, >, <, >=, <=):\n";
        cout << "frac1 == frac2 : " << (frac1 == frac2 ? "Đúng" : "Sai") << "\n";
        cout << "frac1 != frac2 : " << (frac1 != frac2 ? "Đúng" : "Sai") << "\n";
        cout << "frac1 > frac2  : " << (frac1 > frac2 ? "Đúng" : "Sai") << "\n";
        cout << "frac1 < frac2  : " << (frac1 < frac2 ? "Đúng" : "Sai") << "\n";
        cout << "frac1 >= frac2 : " << (frac1 >= frac2 ? "Đúng" : "Sai") << "\n";
        cout << "frac1 <= frac2 : " << (frac1 <= frac2 ? "Đúng" : "Sai") << "\n";

        cout << "\n3. CÁC TOÁN TỬ GÁN KẾT HỢP (+=, -=, *=, /=):\n";
        Fraction tempFrac = frac1;
        tempFrac += frac2;
        cout << "tempFrac += frac2 -> Kết quả: " << tempFrac << "\n";

        tempFrac = frac1;
        tempFrac -= frac2;
        cout << "tempFrac -= frac2 -> Kết quả: " << tempFrac << "\n";

        tempFrac = frac1;
        tempFrac *= frac2;
        cout << "tempFrac *= frac2 -> Kết quả: " << tempFrac << "\n";

        tempFrac = frac1;
        tempFrac /= frac2;
        cout << "tempFrac /= frac2 -> Kết quả: " << tempFrac << "\n";

        cout << "\n4. CÁC TOÁN TỬ TĂNG/GIẢM (++, --):\n";
        Fraction incDecFrac = frac1;
        cout << "Phân số gốc: " << incDecFrac << "\n";
        cout << "Tăng tiền tố (++incDecFrac): " << ++incDecFrac << "\n";
        cout << "Giảm tiền tố (--incDecFrac): " << --incDecFrac << "\n";

        Fraction postfixResult = incDecFrac++;
        cout << "Tăng hậu tố (incDecFrac++): Trả về " << postfixResult
             << " | Giá trị mới thực tế: " << incDecFrac << "\n";

        postfixResult = incDecFrac--;
        cout << "Giảm hậu tố (incDecFrac--): Trả về " << postfixResult
             << " | Giá trị mới thực tế: " << incDecFrac << "\n\n";
    }
    catch (const exception &e)
    {
        cerr << "Lỗi ở phần Phân số: " << e.what() << "\n";
    }
}

void testMyIntArray()
{
    cout << "--- KIỂM TRA LỚP MẢNG SỐ NGUYÊN (MYINTARRAY) ---\n";
    try
    {
        MyIntArray array1, array2;
        cout << "[Nhập mảng 1]\n";
        cin >> array1;
        cout << "[Nhập mảng 2]\n";
        cin >> array2;

        cout << "\nKẾT QUẢ:\n";
        cout << "Mảng 1: " << array1;
        cout << "Mảng 2: " << array2;

        MyIntArray sumArray = array1 + array2;
        cout << "Tổng (array1 + array2): " << sumArray;

        MyIntArray copiedArray;
        copiedArray = array1;
        cout << "Mảng bản sao (chép từ mảng 1): " << copiedArray;

        copiedArray++;
        cout << "Mảng bản sao sau khi tăng (copiedArray++): " << copiedArray;

        cout << "Mảng 1 gốc (phải giữ nguyên): " << array1;
    }
    catch (const exception &e)
    {
        cerr << "Lỗi ở phần Mảng số nguyên: " << e.what() << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "vi_VN.UTF-8");

    testFraction();
    testMyIntArray();

    return 0;
}