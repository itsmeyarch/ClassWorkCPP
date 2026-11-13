#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Task 1

void addToEnd(int**& matrix, int& rows, int cols, int* newRow) {
    int** temp = new int* [rows + 1];

    for (int i = 0; i < rows; i++) {
        temp[i] = matrix[i];
    }

    temp[rows] = new int[cols];

    for (int j = 0; j < cols; j++) {
        temp[rows][j] = newRow[j];
    }

    delete[] matrix;
    matrix = temp;
    rows++;
}

// Task 2

void addToBeginning(int**& matrix, int& rows, int cols, int* newRow) {
    int** temp = new int* [rows + 1];

    temp[0] = new int[cols];

    for (int j = 0; j < cols; j++) {
        temp[0][j] = newRow[j];
    }

    for (int i = 0; i < rows; i++) {
        temp[i + 1] = matrix[i];
    }

    delete[] matrix;
    matrix = temp;
    rows++;
}

// Task 3

void addAtPosition(int**& matrix, int& rows, int cols, int* newRow, int position) {
    if (position < 0 || position > rows) {
        std::cout << "Invalid position\n";
        return;
    }

    int** temp = new int* [rows + 1];

    for (int i = 0; i < position; i++) {
        temp[i] = matrix[i];
    }

    temp[position] = new int[cols];

    for (int j = 0; j < cols; j++) {
        temp[position][j] = newRow[j];
    }

    for (int i = position; i < rows; i++) {
        temp[i + 1] = matrix[i];
    }

    delete[] matrix;
    matrix = temp;
    rows++;
}

// Task 4

void task4() {
    int rows, cols;

    std::cout << "Enter rows and columns: ";
    std::cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cout << "Invalid size\n";
        return;
    }

    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    std::cout << "Original matrix:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    int newRows = 0;

    for (int i = 0; i < rows; i++) {
        bool hasZero = false;

        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }

        if (!hasZero) {
            matrix[newRows] = matrix[i];
            newRows++;
        }
        else {
            delete[] matrix[i];
        }
    }

    rows = newRows;

    std::cout << "Result matrix:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

// Task 5

void task5() {
    int rows, cols;

    std::cout << "Enter rows and columns: ";
    std::cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cout << "Invalid size\n";
        return;
    }

    int** A = new int* [rows];
    int** B = new int* [rows];
    int** C = new int* [rows];

    for (int i = 0; i < rows; i++) {
        A[i] = new int[cols];
        B[i] = new int[cols];
        C[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    std::cout << "Array A:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Array B:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << B[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Result array:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < rows; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;
}

// Task 6

int** multiplyMatrices(int** A, int** B, int m, int n, int k) {
    int** C = new int* [m];

    for (int i = 0; i < m; i++) {
        C[i] = new int[k];

        for (int j = 0; j < k; j++) {
            C[i][j] = 0;

            for (int x = 0; x < n; x++) {
                C[i][j] += A[i][x] * B[x][j];
            }
        }
    }

    return C;
}

void task6() {
    int m, n, k;

    std::cout << "Enter M, N and K: ";
    std::cin >> m >> n >> k;

    if (m <= 0 || n <= 0 || k <= 0) {
        std::cout << "Invalid size\n";
        return;
    }

    int** A = new int* [m];
    int** B = new int* [n];

    for (int i = 0; i < m; i++) {
        A[i] = new int[n];

        for (int j = 0; j < n; j++) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        B[i] = new int[k];

        for (int j = 0; j < k; j++) {
            std::cout << "B[" << i << "][" << j << "]: ";
            std::cin >> B[i][j];
        }
    }

    int** C = multiplyMatrices(A, B, m, n, k);

    std::cout << "Result matrix:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < m; i++) {
        delete[] A[i];
        delete[] C[i];
    }

    for (int i = 0; i < n; i++) {
        delete[] B[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;
}

// Task 7

void task7() {
    int size;

    std::cout << "Enter array size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Invalid size\n";
        return;
    }

    int* array = new int[size];

    std::cout << "Enter array elements:\n";

    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }

    std::cout << "Possible number of rows:\n";

    for (int cols = 1; cols <= size; cols++) {
        if (size % cols == 0) {
            std::cout << size / cols << " rows and " << cols << " columns\n";
        }
    }

    int rows, cols;

    std::cout << "Enter rows and columns: ";
    std::cin >> rows >> cols;

    if (rows <= 0 || cols <= 0 || rows * cols != size) {
        std::cout << "Invalid dimensions\n";
        delete[] array;
        return;
    }

    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            matrix[i][j] = array[i * cols + j];
        }
    }

    std::cout << "Result matrix:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    delete[] array;
}

// Task 8

void task8() {
    std::string names[5];

    for (int i = 0; i < 5; i++) {
        std::cout << "Enter surname " << i + 1 << ": ";
        std::cin >> names[i];
    }

    int longest = 0;

    for (int i = 1; i < 5; i++) {
        if (names[i].length() > names[longest].length()) {
            longest = i;
        }
    }

    std::cout << "Longest surname: " << names[longest] << "\n";
}

// Main

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int choice;

    do {
        std::cout << "\n1. Add row to the end\n";
        std::cout << "2. Add row to the beginning\n";
        std::cout << "3. Add row at position\n";
        std::cout << "4. Remove rows with zero elements\n";
        std::cout << "5. Sum two matrices\n";
        std::cout << "6. Multiply matrices\n";
        std::cout << "7. Convert one-dimensional array to matrix\n";
        std::cout << "8. Find longest surname\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose task: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
        case 2:
        case 3: {
            int rows, cols;

            std::cout << "Enter rows and columns: ";
            std::cin >> rows >> cols;

            if (rows <= 0 || cols <= 0) {
                std::cout << "Invalid size\n";
                break;
            }

            int** matrix = new int* [rows];

            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];

                for (int j = 0; j < cols; j++) {
                    std::cout << "Enter element: ";
                    std::cin >> matrix[i][j];
                }
            }

            int* newRow = new int[cols];

            std::cout << "Enter new row:\n";

            for (int j = 0; j < cols; j++) {
                std::cin >> newRow[j];
            }

            if (choice == 1) {
                addToEnd(matrix, rows, cols, newRow);
            }
            else if (choice == 2) {
                addToBeginning(matrix, rows, cols, newRow);
            }
            else {
                int position;

                std::cout << "Enter position (0 to " << rows << "): ";
                std::cin >> position;

                addAtPosition(matrix, rows, cols, newRow, position);
            }

            std::cout << "Result matrix:\n";

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << "\n";
            }

            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }

            delete[] matrix;
            delete[] newRow;
            break;
        }
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 0);
}