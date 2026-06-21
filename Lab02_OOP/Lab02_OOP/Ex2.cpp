#include <iostream>
#include <string>
#include "Class.h"
using namespace std;

int main()
{
    Class C;

    cout << "=== 1. READ DATA FROM FILE ===\n";
    C.inputClass_File();
    C.outputClass();

    cout << "\n=== 2. ADD NEW STUDENT ===\n";
    C.addStudent("Nguyen Anh Trung", "1234567899", 8.5);
    C.outputClass();

    cout << "\n=== 3. SORT BY AVERAGE POINT (DESCENDING) ===\n";
    C.sortStudent_DescendingAveragePoint();
    C.outputClass();

    cout << "\n=== 4. REMOVE STUDENT ===\n";
    C.removeStudent("Nguyen Anh Trung");
    C.outputClass();

    return 0;
}