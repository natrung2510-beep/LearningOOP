#pragma once

class Point2D
{
private:
    double x;
    double y;

public:
    void inputPoint();
    void outputPoint();
    double calculateDistance(Point2D a);
    double getX();
    double getY();
};