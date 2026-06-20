#pragma once
#include "Point.h"
#include <iostream>
using namespace std;
class Rectangle2D
{

private:
    Point2D TL;
    Point2D TR;
    Point2D BL;
    Point2D BR;

public:
    // CONSTRUCTORS
    Rectangle2D(const Point2D &A, const Point2D &B, const Point2D &C, const Point2D &D) : TL(A), TR(B), BL(C), BR(D) {}
    Rectangle2D(double length, double width) : Rectangle2D({-abs(length) / 2, abs(width) / 2}, {abs(length) / 2, abs(width) / 2}, {-abs(length) / 2, -abs(width) / 2}, {abs(length) / 2, -abs(width) / 2}) {}
    Rectangle2D(double edge) : Rectangle2D(edge, edge) {}
    Rectangle2D() : Rectangle2D(1.0) {}
    // void inputRectangle();
    // void outputRectangle();
    bool isValid() const;
    double calculatePerimeter() const;
    double calculateArea() const;
    friend istream &operator>>(istream &inDevice, Rectangle2D &a);
    friend ostream &operator<<(ostream &outDevice, const Rectangle2D &a);

    // DESTRUCTORS
    ~Rectangle2D() {}
};