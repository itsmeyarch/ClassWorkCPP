#include <fstream>
#include <iostream>

int main()
{
    std::fstream f;

    f.open("test.txt", std::ios_base::app);

    f.write("hello, world", strlen("hello, world"));

    f.close();

    f.open("test.txt", std::ios_base::in);

    char buffer[255];
    f.read(buffer, 255);

    std::cout << buffer << '\n';
}