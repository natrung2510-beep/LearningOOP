#pragma once
#include <iostream>
class Point2D
{
private:
    double x;
    double y;

public:
    Point2D(double x, double y) : x(x), y(y) {}
    Point2D() : Point2D(0, 0) {}
    void inputPoint();
    void outputPoint();
    friend istream &operator>>(istream &inDevice, Point2D &a);
    friend ostream &operator<<(ostream &outDevice, const Point2D &a);
    double calculateDistance(Point2D a);
    double getX();
    double getY();
};
