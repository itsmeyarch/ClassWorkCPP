#include "Game.h"

#include <iostream>
#include <algorithm>
#include <cctype>
#include <random>
#include <stdexcept>
#include <vector>

Game::Game()
    : wordCase("words.txt", 0x5A),
    maxMistakes(6),
    mistakes(0),
    hintUsed(false) {
}

char Game::readLetter() const {
    std::string input;

    while (true) {
        std::cout << "Enter a letter or ? for hint: ";
        std::cin >> input;

        if (input == "?") {
            return '?';
        }

        if (input.size() == 1 &&
            std::isalpha(static_cast<unsigned char>(input[0])) &&
            static_cast<unsigned char>(input[0]) < 128) {

            return static_cast<char>(
                std::tolower(static_cast<unsigned char>(input[0])));
        }

        std::cout << "Please enter one English letter.\n";
    }
}

void Game::showWord() const {
    std::cout << "\nWord: ";

    for (char letter : secretWord) {
        if (guessedLetters.count(letter) > 0) {
            std::cout << letter << " ";
        }
        else {
            std::cout << "_ ";
        }
    }

    std::cout << "\n";
}

void Game::showHangman() const {
    std::cout << "\nMistakes: "
        << mistakes << "/" << maxMistakes << "\n";

    if (hintUsed) {
        std::cout << "Hint: already used\n";
    }
    else {
        std::cout << "Hint: available\n";
    }
}

bool Game::checkWin() const {
    for (char letter : secretWord) {
        if (guessedLetters.count(letter) == 0) {
            return false;
        }
    }

    return true;
}

void Game::chooseDifficulty() {
    std::string choice;

    std::cout << "\nChoose difficulty:\n";
    std::cout << "1. Easy - 10 mistakes\n";
    std::cout << "2. Normal - 6 mistakes\n";
    std::cout << "3. Hard - 4 mistakes\n";

    while (true) {
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == "1") {
            maxMistakes = 10;
            break;
        }
        else if (choice == "2") {
            maxMistakes = 6;
            break;
        }
        else if (choice == "3") {
            maxMistakes = 4;
            break;
        }
        else {
            std::cout << "Wrong choice. Try again.\n";
        }
    }
}

void Game::playGame() {
    std::string answer;

    while (true) {
        mistakes = 0;
        hintUsed = false;
        guessedLetters.clear();
        statistics.resetGame();

        chooseDifficulty();

        try {
            std::vector<std::string> words = wordCase.loadWords();

            std::random_device device;
            std::mt19937 generator(device());

            std::uniform_int_distribution<std::size_t> distribution(
                0, words.size() - 1);

            secretWord = words[distribution(generator)];

            std::transform(
                secretWord.begin(),
                secretWord.end(),
                secretWord.begin(),
                [](unsigned char c) {
                    return static_cast<char>(std::tolower(c));
                });

            statistics.setSecretWord(secretWord);

            std::cout << "\n=== HANGMAN ===\n";
            std::cout << "Guess the hidden English word.\n";
            std::cout << "You have " << maxMistakes
                << " mistakes available.\n";

            while (mistakes < maxMistakes && !checkWin()) {
                showWord();
                showHangman();

                char letter = readLetter();

                if (letter == '?') {
                    if (hintUsed) {
                        std::cout << "You have already used the hint.\n";
                        continue;
                    }

                    std::vector<char> availableLetters;

                    for (char symbol : secretWord) {
                        if (guessedLetters.count(symbol) == 0) {
                            availableLetters.push_back(symbol);
                        }
                    }

                    if (!availableLetters.empty()) {
                        std::uniform_int_distribution<std::size_t> hintDistribution(
                            0, availableLetters.size() - 1);

                        char hintLetter =
                            availableLetters[hintDistribution(generator)];

                        guessedLetters.insert(hintLetter);
                        hintUsed = true;
                        mistakes++;

                        std::cout << "Hint! The letter is: "
                            << hintLetter << "\n";
                    }

                    continue;
                }

                if (guessedLetters.count(letter) > 0) {
                    std::cout << "You have already entered this letter.\n";
                    continue;
                }

                guessedLetters.insert(letter);
                statistics.addAttempt(letter);

                if (secretWord.find(letter) == std::string::npos) {
                    mistakes++;
                    std::cout << "There is no such letter.\n";
                }
                else {
                    std::cout << "Correct!\n";
                }
            }

            bool won = checkWin();

            showWord();

            if (won) {
                std::cout << "\nYou won!\n";
            }
            else {
                std::cout << "\nYou lost!\n";
                std::cout << "The word was: " << secretWord << "\n";
            }

            statistics.print(won);
            statistics.save(won, "statistics.txt");
        }
        catch (const std::exception& error) {
            std::cerr << "Error: " << error.what() << "\n";
            break;
        }

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> answer;

        if (answer != "y" && answer != "Y") {
            break;
        }
    }
}

void Game::showMenu() const {
    std::cout << "\n=== HANGMAN ===\n";
    std::cout << "1. New game\n";
    std::cout << "2. Total statistics\n";
    std::cout << "3. Game history\n";
    std::cout << "4. Exit\n";
}

void Game::start() {
    std::string choice;

    while (true) {
        showMenu();

        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == "1") {
            playGame();
        }
        else if (choice == "2") {
            statistics.printTotal();
        }
        else if (choice == "3") {
            statistics.printHistory("statistics.txt");
        }
        else if (choice == "4") {
            std::cout << "Goodbye!\n";
            break;
        }
        else {
            std::cout << "Wrong choice. Try again.\n";
        }
    }
}
