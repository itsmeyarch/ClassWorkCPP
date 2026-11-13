#pragma once
#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include <vector>
#include <chrono>

class Statistics {
private:
    std::chrono::steady_clock::time_point startTime;
    int attempts;
    std::string secretWord;
    std::vector<char> guessedLetters;

public:
    Statistics();

    void start();
    void setSecretWord(const std::string& word);
    void addAttempt(char letter);

    void print(bool won) const;
    void save(bool won, const std::string& fileName) const;
};

#endif