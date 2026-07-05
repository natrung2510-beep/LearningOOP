#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

int main()
{
    cout << "1. TEST CONSTRUCTOR\n";
    cout << "-> Mac dinh:\n";
    Employee emp1;
    emp1.outputEmployee();

    cout << "\n-> 2 tham so (400 ngay):\n";
    Employee emp2("Tran Van B", 400);
    emp2.outputEmployee();

    cout << "\n-> 5 tham so (Co tinh truyen sai chuc danh):\n";
    Employee emp3("Le Thi C", 1500, "Nhan vien", "Nhan vien Le Thi C", 1.0f);
    emp3.outputEmployee();

    cout << "\n-> Sao chep tu emp2:\n";
    Employee emp4(emp2);
    emp4.outputEmployee();

    cout << "\n2. TEST SETTER & DONG BO LOGIC\n";
    cout << "-> Tang ngay lam viec cua emp1 len 800:\n";
    emp1.setWorkDays(800);
    emp1.outputEmployee();

    cout << "\n-> setFullName: Nhap nhieu khoang trang va lap chuc danh:\n";
    emp1.setFullName("   Quan   Ly   Truong phong   ");
    emp1.outputEmployee();

    cout << "\n-> setWorkName: Nhap sai logic chuc danh hien tai:\n";
    emp1.setWorkName("Giam doc Tran Van D");
    emp1.outputEmployee();

    cout << "\n3. TEST GETTER (Lay tung thuoc tinh cua emp1)\n";
    cout << "-> getFullName(): " << emp1.getFullName() << "\n";
    cout << "-> getWorkDays(): " << emp1.getWorkDays() << "\n";
    cout << "-> getJobTitle(): " << emp1.getJobTitle() << "\n";
    cout << "-> getWorkName(): " << emp1.getWorkName() << "\n";
    cout << "-> getSalaryCoefficient(): " << emp1.getSalaryCoefficient() << "\n";

    cout << "\n4. TEST INPUT\n";
    Employee emp5;
    cout << "-> Nhap thong tin nhan vien moi:\n";
    emp5.inputEmployee();
    cout << "\nKet qua luu tru:\n";
    emp5.outputEmployee();

    cout << "\nDone.\n";
    return 0;
}

/*
=========================================================================
PHÂN TÍCH THỨ TỰ GỌI CONSTRUCTORS VÀ DESTRUCTORS:
=========================================================================

1. Khởi tạo đối tượng a và b:
   - Gọi Constructor (2 tham số) để tạo đối tượng a (Họ tên: "Dat Thanh").
   - Gọi Copy Constructor để tạo đối tượng b từ a. Đối tượng b khởi tạo
     tên là "Nguyen Van A", sau đó gán đổi tên thành "Hai Dang".

2. Vòng lặp for chạy 5 lần (i = 0 đến 4):
   - Lần lặp i = 0:
     + Gọi Copy Constructor tạo đối tượng cục bộ 'clone' từ b.
     + Gán tên 'clone': "De tu thu 0 cua Truong phong Hai Dang".
     + Gọi Destructor hủy đối tượng 'clone' ngay khi kết thúc vòng lặp.
   - Lần lặp i = 1:
     + Gọi Copy Constructor tạo đối tượng 'clone' (tên: "De tu thu 1 cua Truong phong Hai Dang").
     + Gọi Destructor hủy đối tượng 'clone'.
   - Lần lặp i = 2:
     + Gọi Copy Constructor tạo đối tượng 'clone' (tên: "De tu thu 2 cua Truong phong Hai Dang").
     + Gọi Destructor hủy đối tượng 'clone'.
   - Lần lặp i = 3:
     + Gọi Copy Constructor tạo đối tượng 'clone' (tên: "De tu thu 3 cua Truong phong Hai Dang").
     + Gọi Destructor hủy đối tượng 'clone'.
   - Lần lặp i = 4:
     + Gọi Copy Constructor tạo đối tượng 'clone' (tên: "De tu thu 4 cua Truong phong Hai Dang").
     + Gọi Destructor hủy đối tượng 'clone'.

3. Kết thúc hàm main():
   - Các đối tượng bị hủy theo cơ chế LIFO (Vào sau ra trước):
     + Gọi Destructor hủy đối tượng b (Họ tên: "Hai Dang").
     + Gọi Destructor hủy đối tượng a (Họ tên: "Dat Thanh").
=========================================================================
*/