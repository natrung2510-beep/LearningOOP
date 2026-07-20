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

    if (other.rows == 0 || other.cols == 0)
    {
        if (this->data != nullptr)
        {
            for (int i = 0; i < this->rows; i++)
                delete[] this->data[i];
            delete[] this->data;
        }
        this->rows = 0;
        this->cols = 0;
        this->data = nullptr;
        return *this;
    }

    int **tempPtr = nullptr;
    int break_point = -1;
    try
    {
        tempPtr = new int *[other.rows];
        for (int i = 0; i < rows; i++)
        {
            break_point = i;
            tempPtr[i] = new int[other.cols];
            for (int j = 0; j < other.cols; j++)
                tempPtr[i][j] = other.data[i][j];
        }
    }
    catch (...)
    {
        for (int k = 0; k < break_point; k++)
            delete[] tempPtr[k];
        delete[] tempPtr;
        tempPtr = nullptr;
        throw;
    }
    if (this->data)
    {
        for (int i = 0; i < rows; i++)
            delete[] this->data[i];
        delete[] this->data;
    }

    this->rows = other.rows;
    this->cols = other.cols;
    this->data = tempPtr;

    return *this;
}
// Bản tối ưu
//  Matrix& Matrix::operator=(const Matrix& other){
//      if (this == &other)
//          return *this;

//     auto temp(other);
//     swap(this->rows, temp.rows);
//     swap(this->cols, temp.cols);
//     swap(this->data, temp.data);

//     return *this;
// }
// Matrix& Matrix::operator=(Matrix other){
//     if (this == &other)
//         return *this;

//     swap(this->rows, other.rows);
//     swap(this->cols, other.cols);
//     swap(this->data, other.data);

//     return *this;
// }
Matrix Matrix::operator+(const Matrix &other) const
{

    if (this->rows != other.rows || this->cols != other.cols)
        throw invalid_argument("Hai ma trận phải cùng kích thước mới có thể cộng!");

    Matrix res(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            res.data[i][j] = this->data[i][j] + other.data[i][j];

    return res;
}
Matrix Matrix::operator*(const Matrix &other) const
{
    if (this->cols != other.rows)
        throw invalid_argument("LỖI: Số cột của ma trận trước phải bằng số dòng của ma trận sau!");

    Matrix res(this->rows, other.cols);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < other.cols; j++)
            for (int k = 0; k < this->cols; k++)
                res.data[i][j] += this->data[i][k] * other.data[k][j];

    return res;
}
int &Matrix::operator()(int row_idx, int col_idx) noexcept
{
    return this->data[row_idx][col_idx];
}
int Matrix::operator()(int row_idx, int col_idx) const noexcept
{
    return this->data[row_idx][col_idx];
}
istream &operator>>(istream &in, Matrix &mat)
{
    int newRows;
    cout << "Mời nhập số dòng: ";
    in >> newRows;

    int newCols;
    cout << "\nMời nhập số cột: ";
    in >> newCols;

    Matrix tempMat(newRows, newCols);
    for (int i = 0; i < newRows; i++)
    {
        for (int j = 0; j < newCols; j++)
        {
            cout << "+, a" << i << j << " = ";
            in >> tempMat.data[i][j];
            cout << '\n';
        }
    }
    mat = tempMat;
    return in;
}
ostream &operator<<(ostream &out, const Matrix &mat)
{
    return out;
}

// DESTRUCTOR
Matrix::~Matrix() {}