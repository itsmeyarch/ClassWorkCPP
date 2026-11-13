#include "Statistics.h"
#include <iostream>
#include <fstream>

Statistics::Statistics() : attempts(0) {
}

void Statistics::start() {
    startTime = std::chrono::steady_clock::now();
}

void Statistics::setSecretWord(const std::string& word) {
    secretWord = word;
}

void Statistics::addAttempt(char letter) {
    ++attempts;
    guessedLetters.push_back(letter);
}

void Statistics::print(bool won) const {
    auto endTime = std::chrono::steady_clock::now();

    auto seconds =
        std::chrono::duration_cast<std::chrono::seconds>(
            endTime - startTime).count();

    std::cout << "\n--- Game statistics ---\n";
    std::cout << "Result: " << (won ? "Win" : "Lose") << "\n";
    std::cout << "Time: " << seconds << " seconds\n";
    std::cout << "Attempts: " << attempts << "\n";
    std::cout << "Word: " << secretWord << "\n";
    std::cout << "Your letters: ";

    if (guessedLetters.empty()) {
        std::cout << "none";
    }

    for (char letter : guessedLetters) {
        std::cout << letter << ' ';
    }

    std::cout << "\n";
}

void Statistics::save(bool won, const std::string& fileName) const {
    auto endTime = std::chrono::steady_clock::now();

    auto seconds =
        std::chrono::duration_cast<std::chrono::seconds>(
            endTime - startTime).count();

    std::ofstream file(fileName, std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Cannot save statistics\n";
        return;
    }

    file << "-------------------------\n";
    file << "Result: " << (won ? "Win" : "Lose") << "\n";
    file << "Time: " << seconds << " seconds\n";
    file << "Attempts: " << attempts << "\n";
    file << "Word: " << secretWord << "\n";
    file << "Your letters: ";

    for (char letter : guessedLetters) {
        file << letter << ' ';
    }

    file << "\n";
}