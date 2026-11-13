#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

int main() {
    std::map<std::string, int> words;
    std::string text;

    std::cout << "Enter text:\n";
    std::getline(std::cin, text);

    std::stringstream ss(text);
    std::string word;

    while (ss >> word) {
        std::transform(word.begin(), word.end(), word.begin(),
            [](unsigned char c) {
                return std::tolower(c);
            });

        words[word]++;
    }

    std::cout << "\nWord frequencies:\n";

    for (const auto& pair : words) {
        std::cout << pair.first << " -> " << pair.second << "\n";
    }

    if (!words.empty()) {
        auto mostFrequent = words.begin();

        for (auto it = words.begin(); it != words.end(); it++) {
            if (it->second > mostFrequent->second) {
                mostFrequent = it;
            }
        }

        std::cout << "\nMost frequent word: "
            << mostFrequent->first
            << " -> " << mostFrequent->second << "\n";
    }
}