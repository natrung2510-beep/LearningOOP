#pragma once
#include "Point.h"

class Rectangle2D
{

private:
    Point2D TL;
    Point2D TR;
    Point2D BL;
    Point2D BR;

public:
    void inputRectangle();
    void outputRectangle();
    bool isValid();
    double calculatePerimeter();
    double calculateArea();
};