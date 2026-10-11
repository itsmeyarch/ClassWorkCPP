#include <format>
#include <iostream>
#include <string>
#include <Windows.h>

std::wstring utf8_to_utf16(const std::string& utf8str) {
	if (utf8str.empty())
		L"";

	int size = MultiByteToWideChar(CP_UTF8, 0, utf8str.c_str(), -1, nullptr, 0);
	std::wstring result(size, 0);

	MultiByteToWideChar(CP_UTF8, 0, utf8str.c_str(), -1, &result[0], size);
	return result;
}

int main()
{
	std::string message = "Привіт! Це повідомлення українською мовою!";
	std::string title = "Успішна конвертація!";

	std::wstring wMessage = utf8_to_utf16(message);
	std::wstring wTitle = utf8_to_utf16(title);

	MessageBoxW(nullptr, wMessage.c_str(), wTitle.c_str(), MB_OK | MB_ICONINFORMATION);

	//std::string str = "Привіт😞";
	//std::cout << str.size() << '\n';
	//std::cout << str << '\n';

	//int age;
	//std::cin >> age;

	//std::string userName;

	////std::cin >> userName;
	//std::cin.ignore();
	//std::getline(std::cin, userName);

	//std::string result = std::format("User {} age {}", userName, age);

	//std::cout << result;

	//int num = 1234;
	//std::string numS = std::to_string(12);

	//std::string numS = "145.sajflksdjflka76";
	//int numI = std::stoi(numS);
	//double numD = std::stod(numS);

	//std::cout << numI << '\n';
	//std::cout << numD << '\n';

	//std::string str = "Hello, world!";

	//str.erase(3);
	//str.replace(7, 5, "P56");
	//str.insert(5, "JavaScript");
	//std::cout << str << '\n';

	//auto position = str.find("world");

	//if (position != std::string::npos) {
	// std::cout << position << '\n';
	//}
	//else {
	// std::cout << "world is not in str\n";
	//}

	//std::string world = str.substr(position, 5);

	//std::cout << world << '\n';
}