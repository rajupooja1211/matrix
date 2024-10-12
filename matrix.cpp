#include <iostream>
#include "matrix.h"

int main() {
    Matrix m1(1, 2, 3, 4);
    Matrix m2(5, 6, 7, 8);
    Matrix m3 = m1 + m2;
    Matrix m4 = m1 * m2;
    Matrix m5 = m1.transpose();

    std::cout << "Matrix m1:\n" << m1 << "\n\n";
    std::cout << "Matrix m2:\n" << m2 << "\n\n";
    std::cout << "Sum of m1 and m2:\n" << m3 << "\n\n";
    std::cout << "Product of m1 and m2:\n" << m4 << "\n\n";
    std::cout << "Transpose of m1:\n" << m5 << "\n";

    return 0;
}