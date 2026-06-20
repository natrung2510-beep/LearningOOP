#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"

using namespace std;

// void Point2D::inputPoint()
// {
//     cout << "Mời nhập hoành độ x:";
//     cin >> x;
//     cout << "Mời nhập tung độ y:";
//     cin >> y;
// }
// void Point2D::outputPoint()
// {
//     cout << "(" << x << ", " << y << ")" << '\n';
// }
double Point2D::calculateDistance(const Point2D &a) const
{
    double newX = x - a.x;
    double newY = y - a.y;

    return sqrt(newX * newX + newY * newY);
}
double Point2D::getX() const
{
    return x;
}
double Point2D::getY() const
{
    return y;
}
istream &operator>>(istream &inDevice, Point2D &a)
{
    inDevice >> a.x >> a.y;
    inDevice.ignore();
    return inDevice;
}
ostream &operator<<(ostream &outDevice, const Point2D &a)
{
    outDevice << "(" << a.x << ", " << a.y << ")" << '\n';
    return outDevice;
}
