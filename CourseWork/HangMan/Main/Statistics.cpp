#include "Statistics.h"

#include <iostream>
#include <fstream>

Statistics::Statistics() : attempts(0), wins(0), losses(0) {
    std::ifstream file("total.txt");

    if (file.is_open()) {
        file >> wins >> losses;
    }
}

void Statistics::resetGame() {
    attempts = 0;
    secretWord.clear();
    guessedLetters.clear();
}

void Statistics::setSecretWord(const std::string& word) {
    secretWord = word;
}

void Statistics::addAttempt(char letter) {
    attempts++;
    guessedLetters.push_back(letter);
}

void Statistics::print(bool won) const {
    std::cout << "\n--- Game statistics ---\n";
    std::cout << "Result: " << (won ? "Win" : "Lose") << "\n";
    std::cout << "Attempts: " << attempts << "\n";
    std::cout << "Word: " << secretWord << "\n";

    std::cout << "Your letters: ";

    for (char letter : guessedLetters) {
        std::cout << letter << " ";
    }

    std::cout << "\n";
}

void Statistics::save(bool won, const std::string& fileName) {
    std::ofstream file(fileName, std::ios::app);

    if (file.is_open()) {
        file << "-------------------------\n";
        file << "Result: " << (won ? "Win" : "Lose") << "\n";
        file << "Attempts: " << attempts << "\n";
        file << "Word: " << secretWord << "\n";
        file << "Your letters: ";

        for (char letter : guessedLetters) {
            file << letter << " ";
        }

        file << "\n";
    }
    else {
        std::cerr << "Cannot save statistics\n";
    }

    if (won) {
        wins++;
    }
    else {
        losses++;
    }

    std::ofstream totalFile("total.txt");

    if (totalFile.is_open()) {
        totalFile << wins << "\n";
        totalFile << losses << "\n";
    }
}


void Statistics::printTotal() const {
    std::cout << "\n--- TOTAL STATISTICS ---\n";
    std::cout << "Games played: " << wins + losses << "\n";
    std::cout << "Wins: " << wins << "\n";
    std::cout << "Losses: " << losses << "\n";
}


void Statistics::printHistory(const std::string& fileName) const {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "\nNo game history available.\n";
        return;
    }

    std::cout << "\n--- GAME HISTORY ---\n";

    std::string line;
    bool hasHistory = false;

    while (std::getline(file, line)) {
        std::cout << line << "\n";
        hasHistory = true;
    }

    if (!hasHistory) {
        std::cout << "No previous games.\n";
    }
}
