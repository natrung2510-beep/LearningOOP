#include <iostream>
#include "Point.h"
#include <windows.h>
#include <string>
using namespace std;

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Point2D A;
    Point2D B;

    cout << "Mời nhập điểm A:";
    A.inputPoint();
    cout << "Mời nhập điểm B:";
    B.inputPoint();

    cout << "Khoảng cách giữa 2 điểm A và B là: " << A.calculateDistance(B);
    return 0;
}