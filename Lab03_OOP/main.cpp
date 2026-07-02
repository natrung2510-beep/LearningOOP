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

    return 0;
}