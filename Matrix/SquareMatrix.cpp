#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "SquareMatrix.h"
#include <string>
#include <iomanip>

SquareMatrix::SquareMatrix(int n) : Matrix(n, n) {}
SquareMatrix::SquareMatrix(const SquareMatrix &other) {}

bool SquareMatrix::isSymmetric() const noexcept {}
int SquareMatrix::sumDiag() const noexcept {}