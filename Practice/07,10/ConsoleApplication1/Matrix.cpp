#include "Matrix.h"
#include <cstdlib>

Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    data = new int* [rows];

    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            data[i][j] = rand() % 100;
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }

    delete[] data;
}

Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;

    data = new int* [rows];

    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }

    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }

    delete[] data;

    rows = other.rows;
    cols = other.cols;

    data = new int* [rows];

    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    out << matrix.rows << " " << matrix.cols << "\n";

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            out << matrix.data[i][j] << " ";
        }

        out << "\n";
    }

    return out;
}

std::istream& operator>>(std::istream& in, Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            in >> matrix.data[i][j];
        }
    }

    return in;
}