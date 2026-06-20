#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"

using namespace std;

void Point2D::inputPoint()
{
    cout << "Mời nhập hoành độ x:";
    cin >> x;
    cout << "Mời nhập tung độ y:";
    cin >> y;
}
void Point2D::outputPoint()
{
    cout << "(" << x << ", " << y << ")" << '\n';
}
double Point2D::calculateDistance(Point2D a)
{
    double newX = abs(x - a.x);
    double newY = abs(y - a.y);

    return sqrt(newX * newX + newY * newY);
}
double Point2D::getX()
{
    return x;
}
double Point2D::getY()
{
    return y;
}
