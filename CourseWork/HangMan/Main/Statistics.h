#pragma once
#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include <vector>

class Statistics {
private:
    int attempts;
    int wins;
    int losses;

    std::string secretWord;
    std::vector<char> guessedLetters;

public:
    Statistics();

    void resetGame();
    void setSecretWord(const std::string& word);
    void addAttempt(char letter);

    void print(bool won) const;
    void save(bool won, const std::string& fileName);
    void printTotal() const;
    void printHistory(const std::string& fileName) const;
};

#endif
