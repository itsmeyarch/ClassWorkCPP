#include "Game.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <random>
#include <stdexcept>

Game::Game()
    : WordCase("words.txt", 0x5A),
    maxMistakes(6),
    mistakes(0) {
}

char Game::readLetter() const {
    std::string input;

    while (true) {
        std::cout << "Enter one English letter: ";
        std::cin >> input;

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
            std::cout << letter << ' ';
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

    std::cout << "  +---+\n";
    std::cout << "  |   " << (mistakes >= 1 ? "O" : "") << "\n";

    std::cout << "  |  "
        << (mistakes >= 3 ? "/" : " ")
        << (mistakes >= 2 ? "|" : " ")
        << (mistakes >= 4 ? "\\" : " ") << "\n";

    std::cout << "  |  "
        << (mistakes >= 5 ? "/" : " ")
        << " "
        << (mistakes >= 6 ? "\\" : " ") << "\n";

    std::cout << "__|__\n";
}

void Game::start() {
    try {
        std::vector<std::string> words = WordCase.loadWords();

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
        statistics.start();

        std::cout << "=== HANGMAN ===\n";
        std::cout << "Guess the hidden English word.\n";
        std::cout << "You have " << maxMistakes
            << " mistakes available.\n";

        bool won = false;

        while (mistakes < maxMistakes) {
            showWord();
            showHangman();

            char letter = readLetter();

            if (guessedLetters.count(letter) > 0) {
                std::cout << "You have already entered this letter.\n";
                continue;
            }

            guessedLetters.insert(letter);
            statistics.addAttempt(letter);

            if (secretWord.find(letter) == std::string::npos) {
                ++mistakes;
                std::cout << "There is no such letter.\n";
            }
            else {
                std::cout << "Correct!\n";
            }

            won = true;

            for (char symbol : secretWord) {
                if (guessedLetters.count(symbol) == 0) {
                    won = false;
                    break;
                }
            }

            if (won) {
                break;
            }
        }

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

        std::cout << "\nStatistics saved to statistics.txt\n";
    }
    catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << "\n";
    }
}