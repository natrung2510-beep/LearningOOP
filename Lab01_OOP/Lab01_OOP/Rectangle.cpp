#include <iostream>
#include <string>
#include <cmath>
#include "Rectangle.h"
using namespace std;

void Rectangle2D::inputRectangle()
{
    cout << "Mời nhập đỉnh trái-trên (A):\n";
    TL.inputPoint();

    cout << "Mời nhập đỉnh phải-trên (B):\n";
    TR.inputPoint();

    cout << "Mời nhập đỉnh trái-dưới (C):\n"; // Hoặc trái-dưới tùy theo thứ tự bạn muốn nhập
    BL.inputPoint();

    cout << "Mời nhập đỉnh phải-dưới (D):\n";
    BR.inputPoint();
}

void Rectangle2D::outputRectangle()
{
    cout << "Đỉnh trái-trên A: ";
    TL.outputPoint();

    cout << "Đỉnh phải-trên B: ";
    TR.outputPoint();

    cout << "Đỉnh trái-dưới C: ";
    BL.outputPoint();

    cout << "Đỉnh phải-dưới D: ";
    BR.outputPoint();
}
bool isRightAngle(Point2D A, Point2D B, Point2D C)
{
    double BA_x = A.getX() - B.getX();
    double BA_y = A.getY() - B.getY();

    double BC_x = C.getX() - B.getX();
    double BC_y = C.getY() - B.getY();

    double dotProduct = (BA_x * BC_x) + (BA_y * BC_y);

    return abs(dotProduct) < 1e-6;
}

bool Rectangle2D::isValid()
{
    bool TL_angle = isRightAngle(BL, TL, TR);
    bool TR_angle = isRightAngle(TL, TR, BR);
    bool BL_angle = isRightAngle(TL, BL, BR);

    return TL_angle && TR_angle && BL_angle;
}

double Rectangle2D::calculatePerimeter()
{
    return 2 * (TL.calculateDistance(TR) + TL.calculateDistance(BL));
}

double Rectangle2D::calculateArea()
{
    return TL.calculateDistance(TR) * TL.calculateDistance(BL);
}