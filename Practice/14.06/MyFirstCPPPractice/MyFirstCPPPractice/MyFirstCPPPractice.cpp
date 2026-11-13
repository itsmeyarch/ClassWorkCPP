#include <iostream>

// Task 1

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

void task1() {
    double (*operations[4])(double, double) = {
        add,
        subtract,
        multiply,
        divide
    };

    char symbols[4] = { '+', '-', '*', '/' };

    double a, b;
    int choice;

    std::cout << "Enter first number: ";
    std::cin >> a;

    std::cout << "Enter second number: ";
    std::cin >> b;

    std::cout << "Choose operation:\n";

    for (int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". " << symbols[i] << "\n";
    }

    std::cin >> choice;

    if (choice >= 1 && choice <= 4 && !(choice == 4 && b == 0)) {
        std::cout << "Result: " << operations[choice - 1](a, b) << "\n";
    }
    else {
        std::cout << "Invalid choice or division by zero\n";
    }
}

// Task 2

void sumArrays(int* A, int* B, int* C, int size) {
    for (int i = 0; i < size; i++) {
        C[i] = A[i] + B[i];
    }
}

void task2() {
    int size;

    std::cout << "Enter array size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Invalid size\n";
        return;
    }

    int* A = new int[size];
    int* B = new int[size];
    int* C = new int[size];

    std::cout << "Enter elements of array A:\n";

    for (int i = 0; i < size; i++) {
        std::cin >> A[i];
    }

    std::cout << "Enter elements of array B:\n";

    for (int i = 0; i < size; i++) {
        std::cin >> B[i];
    }

    sumArrays(A, B, C, size);

    std::cout << "Result array C:\n";

    for (int i = 0; i < size; i++) {
        std::cout << C[i] << " ";
    }

    std::cout << "\n";

    delete[] A;
    delete[] B;
    delete[] C;
}

// Main

int main() {
    int choice;

    do {
        std::cout << "\n1. Calculator\n";
        std::cout << "2. Sum of two arrays\n";
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
        case 0:
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 0);
}