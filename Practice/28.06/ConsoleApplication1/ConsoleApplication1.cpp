
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


void compareFiles() {
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    if (!file1 || !file2) {
        cout << "Error opening files!\n";
        return;
    }

    string line1, line2;
    int lineNumber = 1;
    bool identical = true;

    while (true) {
        bool read1 = static_cast<bool>(getline(file1, line1));
        bool read2 = static_cast<bool>(getline(file2, line2));

        if (!read1 && !read2) {
            break;
        }

        if (!read1 || !read2 || line1 != line2) {
            identical = false;

            cout << "Difference in line " << lineNumber << ":\n";

            if (read1)
                cout << "File 1: " << line1 << endl;
            else
                cout << "File 1: No line\n";

            if (read2)
                cout << "File 2: " << line2 << endl;
            else
                cout << "File 2: No line\n";
        }

        lineNumber++;
    }

    if (identical) {
        cout << "Files are identical.\n";
    }

    file1.close();
    file2.close();
}


void fileStatistics() {
    ifstream input("input.txt");
    ofstream output("statistics.txt");

    if (!input || !output) {
        cout << "Error opening files!\n";
        return;
    }

    int characters = 0;
    int lines = 0;
    int vowels = 0;
    int consonants = 0;
    int digits = 0;

    string text;

    while (getline(input, text)) {
        lines++;

        for (unsigned char ch : text) {
            characters++;

            if (isdigit(ch)) {
                digits++;
            }

            char lower = tolower(ch);

            if (lower == 'a' || lower == 'e' ||
                lower == 'i' || lower == 'o' ||
                lower == 'u' || lower == 'y') {
                vowels++;
            }
            else if (isalpha(ch)) {
                consonants++;
            }
        }
    }

    output << "File Statistics\n";
    output << "Characters: " << characters << endl;
    output << "Lines: " << lines << endl;
    output << "Vowels: " << vowels << endl;
    output << "Consonants: " << consonants << endl;
    output << "Digits: " << digits << endl;

    cout << "Statistics saved to statistics.txt\n";

    input.close();
    output.close();
}


void caesarCipher() {
    ifstream input("input.txt");
    ofstream output("encrypted.txt");

    if (!input || !output) {
        cout << "Error opening files!\n";
        return;
    }

    int key;
    cout << "Enter encryption key: ";
    cin >> key;

    key = ((key % 26) + 26) % 26;

    char ch;

    while (input.get(ch)) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + key) % 26;
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + key) % 26;
        }

        output.put(ch);
    }

    cout << "Encrypted text saved to encrypted.txt\n";

    input.close();
    output.close();
}


int main() {
    int choice;

    do {
        cout << "===== FILE OPERATIONS MENU =====";
        cout << "1. Compare two files\n";
        cout << "2. Calculate file statistics\n";
        cout << "3. Encrypt file using Caesar cipher\n";
        cout << "4. Exit";
        cout << "Choose option: ";

        cin >> choice;

        switch (choice) {
        case 1:
            compareFiles();
            break;

        case 2:
            fileStatistics();
            break;

        case 3:
            caesarCipher();
            break;

        case 4:
            cout << "Program finished.\n";
            break;

        default:
            cout << "Invalid option!\n";
        }

    } while (choice != 4);

    return 0;
}
