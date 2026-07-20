#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Matrix.h"
#include <string>
using namespace std;

// Constructors
Matrix::Matrix(int rows, int cols, int default_value) : rows(rows), cols(cols), data(nullptr)
{
    string exceptionLog = "";
    if (rows < 0)
        exceptionLog += "Số hàng của ma trận phải lớn hơn hoặc bằng 0!";

    exceptionLog += (exceptionLog.empty()) ? "" : "\n";
    if (cols < 0)
        exceptionLog += "Số cột của ma trận phải lớn hơn hoặc bằng 0!";

    if (!exceptionLog.empty())
        throw invalid_argument(exceptionLog);
    int break_point = -1;
    try
    {
        this->data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            break_point = i;
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = default_value;
        }
    }
    catch (...)
    {
        for (int k = 0; k < break_point; k++)
            delete[] this->data[k];
        delete[] this->data;
        this->data = nullptr;
        throw;
    }
}
Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), data(nullptr)
{
    string exceptionLog = "";
    if (rows < 0)
        exceptionLog += "Số hàng của ma trận phải lớn hơn hoặc bằng 0!";

    exceptionLog += (exceptionLog.empty()) ? "" : "\n";

    if (cols < 0)
        exceptionLog += "Số cột của ma trận phải lớn hơn hoặc bằng 0!";

    if (!exceptionLog.empty())
        throw invalid_argument(exceptionLog);
    int break_point = -1;
    try
    {
        this->data = new int *[this->rows];
        for (int i = 0; i < this->rows; i++)
        {
            break_point = i;
            this->data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                this->data[i][j] = other.data[i][j];
        }
    }
    catch (...)
    {
        for (int k = 0; k < break_point; k++)
            delete[] this->data[k];
        delete[] this->data;
        this->data = nullptr;
        throw;
    }
}

// OPERATORs
// assignment
Matrix &Matrix::operator=(const Matrix &other)
{
    if (this == &other)
        return *this;

    this->rows = other.rows;
    this->cols = other.cols;
    delete[] this->data;
    this->data = nullptr;
    int break_point = -1;
    try
    {
        this->data = new int *[this->rows];
        for (int i = 0; i < rows; i++)
        {
            break_point = i;
            this->data[i] = new int[this->cols];
            for (int j = 0; j < this->cols; j++)
                this->data[i][j] = other.data[i][j];
        }
    }
    catch (...)
    {
        for (int k = 0; k < break_point; k++)
            delete[] this->data[k];
        delete[] this->data;
        this->data = nullptr;
        throw;
    }

    return *this;
}
Matrix Matrix::operator+(const Matrix &other) const {}
Matrix Matrix::operator*(const Matrix &other) const {}
int &Matrix::operator()(int row_idx, int col_idx) noexcept {}
int Matrix::operator()(int row_idx, int col_idx) const noexcept {}
istream &operator>>(istream &in, Matrix &mat) {}
ostream &operator<<(ostream &out, const Matrix &mat) {}

// DESTRUCTOR
Matrix::~Matrix() {}