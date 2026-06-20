#include <iostream>
#include "Rectangle.h"
#include <windows.h>
#include <string>
using namespace std;

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Rectangle2D R;
    R.inputRectangle();

    cout << "Hình chữ nhật của bạn:\n";
    R.outputRectangle();

    if (R.isValid())
    {
        cout << "\nHình chữ nhật của bạn hợp lệ!";

        cout << "Chu vi hình chữ nhật trên là:" << R.calculatePerimeter() << '\n';
        cout << "Diện tích hình chữ nhật trên là:" << R.calculateArea() << '\n';
    }
    else
        cout << "\n Hình chữ nhật của bạn không hợp lệ!";

    return 0;
}