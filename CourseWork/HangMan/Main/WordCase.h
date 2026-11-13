#pragma once
#ifndef WORDCASE_H
#define WORDCASE_H

#include <string>
#include <vector>

class WordCase {
private:
    std::string fileName;
    unsigned char xorKey;

    std::string decrypt(const std::string& line) const;

public:
    WordCase(const std::string& name, unsigned char key);

    std::vector<std::string> loadWords() const;
};

#endif
