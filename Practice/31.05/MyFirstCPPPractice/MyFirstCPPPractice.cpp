#include <iostream>

// Task 1

void task1() {
    int m, n;

    std::cout << "Enter size of array A: ";
    std::cin >> m;

    std::cout << "Enter size of array B: ";
    std::cin >> n;

    if (m <= 0 || n <= 0) {
        std::cout << "Invalid size\n";
        return;
    }

    int* A = new int[m];
    int* B = new int[n];
    int* C = new int[m + n];

    std::cout << "Enter elements of array A:\n";
    for (int i = 0; i < m; i++) {
        std::cin >> A[i];
    }

    std::cout << "Enter elements of array B:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }

    for (int i = 0; i < m; i++) {
        C[i] = A[i];
    }

    for (int i = 0; i < n; i++) {
        C[m + i] = B[i];
    }

    std::cout << "Result array:\n";
    for (int i = 0; i < m + n; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << "\n";

    delete[] A;
    delete[] B;
    delete[] C;
}

// Task 2

void task2() {
    int m, n;

    std::cout << "Enter size of array A: ";
    std::cin >> m;

    std::cout << "Enter size of array B: ";
    std::cin >> n;

    if (m <= 0 || n <= 0) {
        std::cout << "Invalid size\n";
        return;
    }

    int* A = new int[m];
    int* B = new int[n];
    int* C = new int[m < n ? m : n];

    std::cout << "Enter elements of array A:\n";
    for (int i = 0; i < m; i++) {
        std::cin >> A[i];
    }

    std::cout << "Enter elements of array B:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }

    int size = 0;

    for (int i = 0; i < m; i++) {
        bool found = false;

        for (int j = 0; j < n; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }

        if (found) {
            bool exists = false;

            for (int j = 0; j < size; j++) {
                if (C[j] == A[i]) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                C[size] = A[i];
                size++;
            }
        }
    }

    std::cout << "Common elements:\n";
    for (int i = 0; i < size; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << "\n";

    delete[] A;
    delete[] B;
    delete[] C;
}

// Task 3

void task3() {
    int m;

    std::cout << "Enter size of array: ";
    std::cin >> m;

    if (m <= 0) {
        std::cout << "Invalid size\n";
        return;
    }

    int* A = new int[m];

    std::cout << "Enter array elements:\n";
    for (int i = 0; i < m; i++) {
        std::cin >> A[i];
    }

    int choice;

    std::cout << "1. Remove even numbers\n";
    std::cout << "2. Remove odd numbers\n";
    std::cout << "Choose: ";
    std::cin >> choice;

    if (choice != 1 && choice != 2) {
        std::cout << "Invalid choice\n";
        delete[] A;
        return;
    }

    int size = 0;

    for (int i = 0; i < m; i++) {
        if (choice == 1 && A[i] % 2 != 0) {
            A[size] = A[i];
            size++;
        }

        if (choice == 2 && A[i] % 2 == 0) {
            A[size] = A[i];
            size++;
        }
    }

    int* B = new int[size];

    for (int i = 0; i < size; i++) {
        B[i] = A[i];
    }

    std::cout << "Result array:\n";
    for (int i = 0; i < size; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << "\n";

    delete[] A;
    delete[] B;
}

// Main

int main() {
    int choice;

    do {
        std::cout << "\n1. Combine two arrays\n";
        std::cout << "2. Find common elements\n";
        std::cout << "3. Remove even or odd numbers\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose task: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 0);
}