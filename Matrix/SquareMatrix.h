#pragma once
#include <iostream>
#include "Matrix.h"

class SquareMatrix : public Matrix
{
public:
    SquareMatrix(int n);
    SquareMatrix(const SquareMatrix &other);

    bool isSymmetric() const noexcept;
    int sumDiag() const noexcept;
};