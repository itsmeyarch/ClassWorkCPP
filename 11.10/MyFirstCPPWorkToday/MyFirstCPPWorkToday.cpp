#include <iostream>
#include <string>

int main()
{
    std::string str = "Hello, world!";

    std::cout << str << '\n';

    std::cout << str[2] << '\n';
    str[2] = 'o';
    std::cout << str << '\n';

    std::cout << str.at(3) << '\n';
    str.at(4) = '_';
    std::cout << str << '\n';

    //std::cout << str[15] << '\n';
    //std::cout << str.at(15) << '\n';

    std::string str2 = str + " Goodby!";
    std::cout << str2 << '\n';

    str += "I love C++";
    std::cout << str << '\n';

    str.append("and hate JavaScript!");
    std::cout << str << '\n';

    std::cout << str.size() << ' ' << str.length() << ' ' << str.capacity() << '\n';

    std::string emptyString = "";

    std::cout << (emptyString.empty() ? "string is empty" : "string is not empty") << '\n';

    // Search
    std::string str = "Hello, World";
    size_t pos = str.find("World");

    if (pos != std::string::npos)
        std::cout << "Found 'World'. Index: " << pos << '\n';
    else
        std::cout << "'World' not found\n";

    std::string subStr = str.substr(0, 5);
    std::cout << "Substring: " << subStr << '\n';


}