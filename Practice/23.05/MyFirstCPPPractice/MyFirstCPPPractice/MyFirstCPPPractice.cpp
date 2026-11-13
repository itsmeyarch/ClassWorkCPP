#include <iostream>
#include <cstdlib>
#include <ctime>

// Task 1

double power(double number, int degree) {
    if (degree == 0) {
        return 1;
    }

    if (degree < 0) {
        return 1.0 / power(number, -degree);
    }

    return number * power(number, degree - 1);
}

// Task 2

void printStars(int n) {
    if (n <= 0) {
        return;
    }

    std::cout << "*";
    printStars(n - 1);
}

// Task 3

int sumRange(int a, int b) {
    if (a > b) {
        return 0;
    }

    if (a == b) {
        return a;
    }

    return a + sumRange(a + 1, b);
}

// Task 4

int findMinSequence(int arr[], int index, int currentSum, int minSum, int minPosition) {
    if (index == 100) {
        return minPosition;
    }

    currentSum += arr[index];

    if (index >= 9) {
        if (currentSum < minSum) {
            minSum = currentSum;
            minPosition = index - 9;
        }

        currentSum -= arr[index - 9];
    }

    return findMinSequence(arr, index + 1, currentSum, minSum, minPosition);
}

int findMinSequence(int arr[]) {
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }

    return findMinSequence(arr, 0, 0, 2147483647, 0);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int choice;

    do {
        std::cout << "\n1. Power of a number\n";
        std::cout << "2. Print stars\n";
        std::cout << "3. Sum of range\n";
        std::cout << "4. Minimum sequence of 10 numbers\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose task: ";
        std::cin >> choice;

        // Task 1

        if (choice == 1) {
            double number;
            int degree;

            std::cout << "Enter number: ";
            std::cin >> number;

            std::cout << "Enter degree: ";
            std::cin >> degree;

            if (number == 0 && degree < 0) {
                std::cout << "Invalid operation!\n";
            }
            else {
                std::cout << "Result: " << power(number, degree) << "\n";
            }
        }

        // Task 2

        else if (choice == 2) {
            int n;

            std::cout << "Enter number of stars: ";
            std::cin >> n;

            printStars(n);
            std::cout << "\n";
        }

        // Task 3

        else if (choice == 3) {
            int a, b;

            std::cout << "Enter a: ";
            std::cin >> a;

            std::cout << "Enter b: ";
            std::cin >> b;

            if (a > b) {
                std::swap(a, b);
            }

            std::cout << "Sum: " << sumRange(a, b) << "\n";
        }

        // Task 4

        else if (choice == 4) {
            int arr[100];

            std::cout << "Array:\n";

            for (int i = 0; i < 100; i++) {
                arr[i] = rand() % 101 - 50;
                std::cout << arr[i] << " ";

                if ((i + 1) % 10 == 0) {
                    std::cout << "\n";
                }
            }

            int position = findMinSequence(arr);
            int minSum = 0;

            for (int i = position; i < position + 10; i++) {
                minSum += arr[i];
            }

            std::cout << "Starting position: " << position + 1 << "\n";
            std::cout << "Minimum sum: " << minSum << "\n";

            std::cout << "Sequence: ";

            for (int i = position; i < position + 10; i++) {
                std::cout << arr[i] << " ";
            }

            std::cout << "\n";
        }

    } while (choice != 5);
}