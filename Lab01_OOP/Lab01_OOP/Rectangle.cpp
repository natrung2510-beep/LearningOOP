#include <iostream>
#include <string>
#include <cmath>
#include "Rectangle.h"
using namespace std;

// void Rectangle2D::inputRectangle()
// {
//     cout << "Mời nhập đỉnh trái-trên (A):\n";
//     TL.inputPoint();

//     cout << "Mời nhập đỉnh phải-trên (B):\n";
//     TR.inputPoint();

//     cout << "Mời nhập đỉnh trái-dưới (C):\n"; // Hoặc trái-dưới tùy theo thứ tự bạn muốn nhập
//     BL.inputPoint();

//     cout << "Mời nhập đỉnh phải-dưới (D):\n";
//     BR.inputPoint();
// }

// void Rectangle2D::outputRectangle()
// {
//     cout << "Đỉnh trái-trên A: ";
//     TL.outputPoint();

//     cout << "Đỉnh phải-trên B: ";
//     TR.outputPoint();

//     cout << "Đỉnh trái-dưới C: ";
//     BL.outputPoint();

//     cout << "Đỉnh phải-dưới D: ";
//     BR.outputPoint();
// }
static bool isRightAngle(const Point2D &A, const Point2D &B, const Point2D &C)
{
    double BA_x = A.getX() - B.getX();
    double BA_y = A.getY() - B.getY();

    double BC_x = C.getX() - B.getX();
    double BC_y = C.getY() - B.getY();

    double dotProduct = (BA_x * BC_x) + (BA_y * BC_y);

    return abs(dotProduct) <= 1e-6;
}

bool Rectangle2D::isValid() const
{
    if (TL == TR || TL == BL)
        return false;
    bool TL_angle = isRightAngle(BL, TL, TR);
    bool TR_angle = isRightAngle(TL, TR, BR);
    bool BL_angle = isRightAngle(TL, BL, BR);

    return TL_angle && TR_angle && BL_angle;
}

double Rectangle2D::calculatePerimeter() const
{
    return 2 * (TL.calculateDistance(TR) + TL.calculateDistance(BL));
}

double Rectangle2D::calculateArea() const
{
    return TL.calculateDistance(TR) * TL.calculateDistance(BL);
}
istream &operator>>(istream &inDevice, Rectangle2D &R)
{
    inDevice >> R.TL >> R.TR >> R.BL >> R.BR;
    inDevice.ignore();
    return inDevice;
}
ostream &operator<<(ostream &outDevice, const Rectangle2D &R)
{
    outDevice << "Đỉnh trái-trên A: " << R.TL;

    outDevice << "Đỉnh phải-trên B: " << R.TR;

    outDevice << "Đỉnh trái-dưới C: " << R.BL;

    outDevice << "Đỉnh phải-dưới D: " << R.BR;
    return outDevice;
}