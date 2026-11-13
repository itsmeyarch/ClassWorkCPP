#include "function.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void FillArrayInt(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}

void ShowArrayInt(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int FindMinInt(int arr[], int size)
{
    int min = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];

    return min;
}

int FindMaxInt(int arr[], int size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void SortArrayInt(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void EditArrayInt(int arr[], int size, int index, int value)
{
    if (index >= 0 && index < size)
        arr[index] = value;
}

void FillArrayDouble(double arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = (rand() % 1000) / 10.0;
}

void ShowArrayDouble(double arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

double FindMinDouble(double arr[], int size)
{
    double min = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];

    return min;
}

double FindMaxDouble(double arr[], int size)
{
    double max = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void SortArrayDouble(double arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void EditArrayDouble(double arr[], int size, int index, double value)
{
    if (index >= 0 && index < size)
        arr[index] = value;
}

void FillArrayChar(char arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = 'A' + rand() % 26;
}

void ShowArrayChar(char arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

char FindMinChar(char arr[], int size)
{
    char min = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];

    return min;
}

char FindMaxChar(char arr[], int size)
{
    char max = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void SortArrayChar(char arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void EditArrayChar(char arr[], int size, int index, char value)
{
    if (index >= 0 && index < size)
        arr[index] = value;
}