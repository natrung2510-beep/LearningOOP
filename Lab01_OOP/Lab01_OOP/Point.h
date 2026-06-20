#pragma once
#include <iostream>
using namespace std;
class Point2D
{
private:
    double x;
    double y;

public:
    Point2D(double x, double y) : x(x), y(y) {}
    Point2D() : Point2D(0, 0) {}
    // void inputPoint();
    // void outputPoint();
    friend istream &operator>>(istream &inDevice, Point2D &a);
    friend ostream &operator<<(ostream &outDevice, const Point2D &a);
    double calculateDistance(const Point2D &a) const;
    double getX() const;
    double getY() const;
};
