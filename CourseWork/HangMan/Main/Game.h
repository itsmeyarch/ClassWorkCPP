#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>
#include <set>

#include "WordCase.h"
#include "Statistics.h"

class Game {
private:
    WordCase wordCase;
    Statistics statistics;

    std::string secretWord;
    std::set<char> guessedLetters;

    int maxMistakes;
    int mistakes;

    bool hintUsed;

    char readLetter() const;
    void showWord() const;
    void showHangman() const;
    bool checkWin() const;

    void chooseDifficulty();
    void playGame();
    void showMenu() const;

public:
    Game();

    void start();
};

#endif
