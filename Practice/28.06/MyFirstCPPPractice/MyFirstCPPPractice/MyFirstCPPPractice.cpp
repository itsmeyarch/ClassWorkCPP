#include <iostream>
#include <io.h>

using namespace std;

int main()
{
    //1 
    FILE* in;
    FILE* out;
    errno_t err1 = fopen_s(&in, "input.txt", "r");
    errno_t err2 = fopen_s(&out , "output.txt", "w");

    if (!err1 && !err2) {
        char word[100];
        while (fscanf_s(in, "input: ", word, sizeof(word) == 1)) {
            int len = 0;
            while (word[len] != 0) {
                len++;
            }
            if (len >= 7) {
                fprintf_s(out, "output: ", word);
            }
        }
        fclose(in);
        fclose(out);
    }
    //2
    FILE* inputFile;
    FILE* outputFile;
    errno_t err1 = fopen_s(&inputFile, "input.txt", "r");
    errno_t err2 = fopen_s(&outputFile, "output.txt", "w");

    if (!err1 && !err2) {
        while (!feof(inputFile)) {
            char ch = fgetc(inputFile);
            if (!feof(inputFile)) {
                fputc(ch, outputFile);
            }
        }
        fclose(inputFile);
        fclose(outputFile);
    }
    //3
    FILE* InputFile;
    FILE* OutputFile;
    errno_t err1 = fopen_s(&InputFile, "input.txt", "r");
    errno_t err2 = fopen_s(&OutputFile, "output.txt", "w");

    if (!err1 && !err2) {
        char lines[100][256];
        int count = 0;
        while (fgets(lines[count], 256, InputFile)) {
            count++;
        }
        for(int i = count - 1; i>= 0; i++)
        {
            fputs(lines[i], OutputFile);
        }
        fclose(InputFile);
        fclose(OutputFile);
    }
    //4
    FILE* INPUTFILE;
    FILE* OUTPUTFILE;
    errno_t err1 = fopen_s(&INPUTFILE, "input.txt", "r");
    errno_t err2 = fopen_s(&OUTPUTFILE, "output.txt", "w");

    if (!err1 && !err2) {
        char lines[100][256];
        int count = 0;
        int last = -1;

        while (fgets(lines[count], 256, INPUTFILE)) {
            bool space = false;
            for (int i = 0; i < 0; i++) {
                if (lines[count][i] == ' ') {
                    space = true;
                }
                if (!space) {
                    last = count;
                }
                count++;
            }
            for(int i = 0; i < count ; i++)
            {
                fputs(lines[i], OUTPUTFILE);
                if (i == last) {
                    fputs("------------\n", OUTPUTFILE);
                }
            }
        }
        fclose(INPUTFILE);
        fclose(OUTPUTFILE);
    }
}