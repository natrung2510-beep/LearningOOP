#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Matrix.h"
using namespace std;

// Constructors
Matrix::Matrix(int rows, int cols, int default_value) : rows(rows), cols(cols)
{
    if (rows <= 0 || cols <= 0)
    {
        this->rows = 0;
        this->cols = 0;
        data = nullptr;
        return;
    }

    data = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            data[i][j] = default_value;
    }
}
Matrix::Matrix(const Matrix &other) {}

// OPERATORs
// assignment
Matrix &Matrix::operator=(const Matrix &other) {}
Matrix Matrix::operator+(const Matrix &other) const {}
Matrix Matrix::operator*(const Matrix &other) const {}
int &Matrix::operator()(int row_idx, int col_idx) noexcept {}
int Matrix::operator()(int row_idx, int col_idx) const noexcept {}
istream &operator>>(istream &in, Matrix &mat) {}
ostream &operator<<(ostream &out, const Matrix &mat) {}

// DESTRUCTOR
Matrix::~Matrix() {}