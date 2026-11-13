#pragma once
#include <iostream>

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols);
    ~Matrix();

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& in, Matrix& matrix);
};