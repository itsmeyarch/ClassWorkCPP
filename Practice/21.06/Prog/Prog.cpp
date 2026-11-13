#define INTEGER
// #define DOUBLE
// #define CHAR

#include "function.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));

    const int size = 10;
    int arr[size];

    FillArray(arr, size);

    std::cout << "Array:\n";
    ShowArray(arr, size);

    std::cout << "Minimum: " << FindMin(arr, size) << "\n";
    std::cout << "Maximum: " << FindMax(arr, size) << "\n";

    SortArray(arr, size);

    std::cout << "Sorted array:\n";
    ShowArray(arr, size);

    int index, value;

    std::cout << "Enter index to edit: ";
    std::cin >> index;

    std::cout << "Enter new value: ";
    std::cin >> value;

    EditArray(arr, size, index, value);

    std::cout << "Edited array:\n";
    ShowArray(arr, size);
}