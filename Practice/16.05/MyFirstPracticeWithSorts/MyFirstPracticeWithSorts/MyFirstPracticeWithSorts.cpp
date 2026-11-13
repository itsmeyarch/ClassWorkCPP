#include <iostream>
#include <list>
#include <algorithm>

// Task 1

void bubbleSort(std::list<int>& numbers) {
    if (numbers.empty()) {
        return;
    }

    bool swapped;

    do {
        swapped = false;

        for (auto it = numbers.begin(); it != std::prev(numbers.end()); ++it) {
            auto next = std::next(it);

            if (*it > *next) {
                std::swap(*it, *next);
                swapped = true;
            }
        }
    } while (swapped);
}

void selectionSort(std::list<int>& numbers) {
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        auto minIt = it;

        for (auto jt = std::next(it); jt != numbers.end(); ++jt) {
            if (*jt < *minIt) {
                minIt = jt;
            }
        }

        std::swap(*it, *minIt);
    }
}

void printList(const std::list<int>& numbers) {
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";
}

// Task 2

void studentProgress() {
    int grades[10];

    for (int i = 0; i < 10; i++) {
        std::cout << "Enter grade " << i + 1 << ": ";
        std::cin >> grades[i];
    }

    int choice;

    do {
        std::cout << "\n1. Show grades\n";
        std::cout << "2. Retake exam\n";
        std::cout << "3. Check scholarship\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < 10; i++) {
                std::cout << grades[i] << " ";
            }
            std::cout << "\n";
        }
        else if (choice == 2) {
            int index, newGrade;

            std::cout << "Enter grade number (1-10): ";
            std::cin >> index;

            if (index >= 1 && index <= 10) {
                std::cout << "Enter new grade: ";
                std::cin >> newGrade;
                grades[index - 1] = newGrade;
            }
            else {
                std::cout << "Invalid grade number!\n";
            }
        }
        else if (choice == 3) {
            double sum = 0;

            for (int i = 0; i < 10; i++) {
                sum += grades[i];
            }

            double average = sum / 10;

            std::cout << "Average grade: " << average << "\n";

            if (average >= 10.7) {
                std::cout << "Scholarship received!\n";
            }
            else {
                std::cout << "Scholarship not received.\n";
            }
        }

    } while (choice != 4);
}

// Task 3

void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }

    if (i < right) {
        quickSort(arr, i, right);
    }
}

// Task 4

void sortArrayParts() {
    int n;

    std::cout << "Enter array size: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid array size!\n";
        return;
    }

    int* arr = new int[n];
    double sum = 0;

    std::cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }

    double average = sum / n;

    int part;

    if (average > 0) {
        part = 2 * n / 3;
    }
    else {
        part = n / 3;
    }

    std::sort(arr, arr + part);
    std::reverse(arr + part, arr + n);

    std::cout << "Result: ";

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";

    delete[] arr;
}

int main() {
    int choice;

    do {
        std::cout << "\n1. Task 1 - Sorting list\n";
        std::cout << "2. Task 2 - Student progress\n";
        std::cout << "3. Task 3 - Quick Sort\n";
        std::cout << "4. Task 4 - Sort array parts\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose task: ";
        std::cin >> choice;

        if (choice == 1) {
            std::list<int> numbers;
            int n, value;

            std::cout << "Enter number of elements: ";
            std::cin >> n;

            for (int i = 0; i < n; i++) {
                std::cin >> value;
                numbers.push_back(value);
            }

            std::list<int> first = numbers;
            std::list<int> second = numbers;

            bubbleSort(first);
            selectionSort(second);

            std::cout << "Bubble Sort: ";
            printList(first);

            std::cout << "Selection Sort: ";
            printList(second);
        }
        else if (choice == 2) {
            studentProgress();
        }
        else if (choice == 3) {
            int n;

            std::cout << "Enter number of elements: ";
            std::cin >> n;

            if (n <= 0) {
                std::cout << "Invalid array size!\n";
                continue;
            }

            int* arr = new int[n];

            std::cout << "Enter elements:\n";

            for (int i = 0; i < n; i++) {
                std::cin >> arr[i];
            }

            quickSort(arr, 0, n - 1);

            std::cout << "Sorted array: ";

            for (int i = 0; i < n; i++) {
                std::cout << arr[i] << " ";
            }

            std::cout << "\n";

            delete[] arr;
        }
        else if (choice == 4) {
            sortArrayParts();
        }

    } while (choice != 5);
}