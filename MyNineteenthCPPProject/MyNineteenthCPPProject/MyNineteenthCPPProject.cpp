#include <iostream>
#include <io.h>

using namespace std;

typedef double MY_DOUBLE;

int main()
{
    //cout << "<===================Beastmaster coding===================>\n";

    //struct _finddata_t info;
    //char path[255];
    //char mask[20]; //Умовний шаблок до пошуку файлів *.txt , text.*

    //cout << "Enter path: ";
    //cin >> path;
    //cin.ignore();

    //cout << "Enter mask: ";
    //cin.getline(mask, 20);
    //
    //strcat_s(path, mask);

    //auto handle = _findfirst(path, &info);
    //if (handle == -1) {
    //    cout << "Files not found\n";
    //}
    //else {
    //    do {
    //        cout << info.name << '\n';
    //    } while (_findnext(handle, &info) == 0);
    //    _findclose(handle);
    //}

    //FILE* textFile;
    /*errno_t err = fopen_s(&textFile, "beastmaster.bin", "r");

    if (!err) {
        char ch = fgetc(textFile);
        cout << ch << '\n';

        fpos_t pos;
        fgetpos(textFile, &pos);
        cout << pos << '\n';

        fseek(textFile, -1, SEEK_END);

        ch = fgetc(textFile);
        cout << ch << '\n';
        
        fclose(textFile);
    }*/


    /*errno_t err = fopen_s(&textFile, "test.txt", "r");
    if (!err) {
        while (!feof(textFile)) {
            cout << (char)fgetc(textFile);
        }
        fclose(textFile);
    }*/



    /*errno_t err = fopen_s(&textFile, "test.txt", "w");

    char textToWrite[] = "Hello world!";

    if (!err) {
        for (int i = 0; i < strlen(textToWrite); i++) {
            fputc(textToWrite[i], textFile);
        }
        fclose(textFile);
    }*/





    /*errno_t err = fopen_s(&textFile, "test.txt", "r");

    if (!err) {
        int i;
        double d;
        while (!feof(textFile)) {
            fscanf_s(textFile, "integer: %d\n", &i);
            fscanf_s(textFile, "double: %lf\n", &d);

            cout << i << ' ' << d << '\n';
        }
        fclose(textFile);
    }*/




    /*errno_t err = fopen_s(&textFile, "beeswarm.txt", "a");

    int i = 123;
    double d = 43.768;

    if (!err) {
        fprintf_s(textFile, "integer: %d\n", i);
        fprintf_s(textFile, "double: %2.f\n", d);

        fclose(textFile);
    }*/



    //MY_DOUBLE var = 90.7;
    
    //atoi(); ASCII TO INT
    //itoa(); INT TO ASCII

    /*FILE* f;

    errno_t err = fopen_s(&f, "beastmaster.bin", "wb");

    if (err) {
        cout << "Unable to open this file...\n";
    }
    else {
        cout << "File is open. Start writing...\n";
        char str[] = "Some text that will be written to file";
        fwrite(&str, sizeof(char) , strlen(str) , f);
        cout << "Writing was successful!\n";
        fclose(f); 
    }*/
}