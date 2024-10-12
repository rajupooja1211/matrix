#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    double data[2][2];  // 2x2 Matrix representation

public:
    // Constructors
    Matrix() : data{{0, 0}, {0, 0}} {}
    Matrix(double a, double b, double c, double d) {
        data[0][0] = a; data[0][1] = b;
        data[1][0] = c; data[1][1] = d;
    }
    Matrix(const Matrix& other) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                data[i][j] = other.data[i][j];
    }

    // Destructor
    ~Matrix() {}

    // Operator overloads
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix transpose() const;

    // Friend declaration for the << operator overload
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

// Operator+ and Operator* definitions
Matrix Matrix::operator+(const Matrix& other) const {
    return Matrix(
        data[0][0] + other.data[0][0], data[0][1] + other.data[0][1],
        data[1][0] + other.data[1][0], data[1][1] + other.data[1][1]
    );
}

Matrix Matrix::operator*(const Matrix& other) const {
    return Matrix(
        data[0][0] * other.data[0][0] + data[0][1] * other.data[1][0],
        data[0][0] * other.data[0][1] + data[0][1] * other.data[1][1],
        data[1][0] * other.data[0][0] + data[1][1] * other.data[1][0],
        data[1][0] * other.data[0][1] + data[1][1] * other.data[1][1]
    );
}

Matrix Matrix::transpose() const {
    return Matrix(data[0][0], data[1][0], data[0][1], data[1][1]);
}

// ostream << operator overload
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << '[' << matrix.data[0][0] << ' ' << matrix.data[0][1] << "]\n"
       << '[' << matrix.data[1][0] << ' ' << matrix.data[1][1] << ']';
    return os;
}

#endif // MATRIX_H
