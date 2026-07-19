#pragma once
#include <iostream>

class Matrix
{
protected:
    int rows;
    int cols;
    int **data;

public:
    // Constructors
    Matrix(int rows = 0, int cols = 0, int default_value = 0);
    Matrix(const Matrix &other);

    // OPERATORs
    // assignment
    Matrix &operator=(const Matrix &other);
    Matrix operator+(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;
    int &operator()(int row_idx, int col_idx) noexcept;
    int operator()(int row_idx, int col_idx) const noexcept;
    friend std::istream &operator>>(std::istream &in, Matrix &mat);
    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);

    // DESTRUCTOR
    ~Matrix();
};