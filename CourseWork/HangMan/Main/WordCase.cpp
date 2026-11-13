#include "WordCase.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

WordCase::WordCase(const std::string& name, unsigned char key)
    : fileName(name), xorKey(key) {
}

std::string WordCase::decrypt(const std::string& line) const {
    std::string result;

    for (std::size_t i = 0; i + 1 < line.size(); i += 2) {
        unsigned int value = 0;

        std::stringstream converter;
        converter << std::hex << line.substr(i, 2);
        converter >> value;

        result += static_cast<char>(value ^ xorKey);
    }

    return result;
}

std::vector<std::string> WordCase::loadWords() const {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open words.txt");
    }

    std::vector<std::string> words;
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty()) {
            words.push_back(decrypt(line));
        }
    }

    if (words.empty()) {
        throw std::runtime_error("Word list is empty");
    }

    return words;
}
