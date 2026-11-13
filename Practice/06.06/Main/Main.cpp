#include <iostream>
#include <cstring>
#include <cctype>

// Task 1

void task1() {
    char str[500];

    std::cout << "Enter a string: ";
    std::cin.getline(str, 500);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            str[i] = '\t';
        }
    }

    std::cout << "Result: " << str << "\n";
}

// Task 2

void task2() {
    char str[500];

    std::cout << "Enter a string: ";
    std::cin.getline(str, 500);

    int letters = 0;
    int digits = 0;
    int other = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = static_cast<unsigned char>(str[i]);

        if (std::isalpha(ch)) {
            letters++;
        }
        else if (std::isdigit(ch)) {
            digits++;
        }
        else {
            other++;
        }
    }

    std::cout << "Letters: " << letters << "\n";
    std::cout << "Digits: " << digits << "\n";
    std::cout << "Other characters: " << other << "\n";
}

// Task 3

void task3() {
    char str[500];

    std::cout << "Enter a sentence: ";
    std::cin.getline(str, 500);

    int words = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!std::isspace(static_cast<unsigned char>(str[i]))) {
            if (!inWord) {
                words++;
                inWord = true;
            }
        }
        else {
            inWord = false;
        }
    }

    std::cout << "Number of words: " << words << "\n";
}

// Task 4

void task4() {
    char str[500];

    std::cout << "Enter a string: ";
    std::cin.getline(str, 500);

    int left = 0;
    int right = std::strlen(str) - 1;
    bool palindrome = true;

    while (left < right) {
        if (str[left] != str[right]) {
            palindrome = false;
            break;
        }

        left++;
        right--;
    }

    if (palindrome) {
        std::cout << "The string is a palindrome\n";
    }
    else {
        std::cout << "The string is not a palindrome\n";
    }
}

// Task 5

int mystrlen(const char* str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

char* mystrcpy(char* str1, const char* str2) {
    int i = 0;

    while (str2[i] != '\0') {
        str1[i] = str2[i];
        i++;
    }

    str1[i] = '\0';

    return str1;
}

char* mystrcat(char* str1, const char* str2) {
    int i = mystrlen(str1);
    int j = 0;

    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';

    return str1;
}

char* mystrchr(char* str, char s) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == s) {
            return &str[i];
        }
    }

    if (s == '\0') {
        return &str[mystrlen(str)];
    }

    return nullptr;
}

char* mystrstr(char* str1, char* str2) {
    if (str2[0] == '\0') {
        return str1;
    }

    for (int i = 0; str1[i] != '\0'; i++) {
        int j = 0;

        while (str1[i + j] != '\0' && str2[j] != '\0' &&
            str1[i + j] == str2[j]) {
            j++;
        }

        if (str2[j] == '\0') {
            return &str1[i];
        }
    }

    return nullptr;
}

void task5() {
    char str1[500];
    char str2[500];
    char copy[500];

    std::cout << "Enter first string: ";
    std::cin.getline(str1, 500);

    std::cout << "Enter second string: ";
    std::cin.getline(str2, 500);

    std::cout << "Length: " << mystrlen(str1) << "\n";

    mystrcpy(copy, str2);
    std::cout << "Copy: " << copy << "\n";

    char combined[1000];
    mystrcpy(combined, str1);
    mystrcat(combined, str2);
    std::cout << "Concatenation: " << combined << "\n";

    char symbol;
    std::cout << "Enter character to find: ";
    std::cin >> symbol;

    char* foundChar = mystrchr(str1, symbol);

    if (foundChar != nullptr) {
        std::cout << "Character found: " << foundChar << "\n";
    }
    else {
        std::cout << "Character not found\n";
    }

    std::cin.ignore(1000, '\n');

    char substring[500];
    std::cout << "Enter substring to find: ";
    std::cin.getline(substring, 500);

    char* foundString = mystrstr(str1, substring);

    if (foundString != nullptr) {
        std::cout << "Substring found: " << foundString << "\n";
    }
    else {
        std::cout << "Substring not found\n";
    }
}

// Main

int main() {
    int choice;

    do {
        std::cout << "\n1. Replace spaces with tabs\n";
        std::cout << "2. Count letters, digits and other characters\n";
        std::cout << "3. Count words\n";
        std::cout << "4. Check palindrome\n";
        std::cout << "5. String functions library\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose task: ";
        std::cin >> choice;
        std::cin.ignore(1000, '\n');

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
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 0);
}