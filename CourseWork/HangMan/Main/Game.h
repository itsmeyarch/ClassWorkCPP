#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>
#include <set>
#include "WordCase.h"
#include "Statistics.h"

class Game {
private:
    WordCase WordCase;
    Statistics statistics;

    std::string secretWord;
    std::set<char> guessedLetters;

    int maxMistakes;
    int mistakes;

    char readLetter() const;
    void showWord() const;
    void showHangman() const;

public:
    Game();

    void start();
};

#endif