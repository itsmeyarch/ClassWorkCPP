#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int rows, cols;

    std::cout << "Enter rows: ";
    std::cin >> rows;

    std::cout << "Enter columns: ";
    std::cin >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cout << "Invalid matrix size\n";
        return 1;
    }

    Matrix matrix(rows, cols);

    std::cout << "\nRandom matrix:\n";
    std::cout << matrix;

    std::cout << "\nEnter matrix elements:\n";
    std::cin >> matrix;

    std::cout << "\nMatrix from console:\n";
    std::cout << matrix;

    std::ofstream outFile("matrix.txt");

    if (outFile.is_open()) {
        outFile << matrix;
        outFile.close();
        std::cout << "\nMatrix saved to file\n";
    }

    Matrix fileMatrix(rows, cols);

    std::ifstream inFile("matrix.txt");

    if (inFile.is_open()) {
        int fileRows, fileCols;
        inFile >> fileRows >> fileCols;

        if (fileRows == rows && fileCols == cols) {
            inFile >> fileMatrix;

            std::cout << "\nMatrix from file:\n";
            std::cout << fileMatrix;
        }

        inFile.close();
    }

}