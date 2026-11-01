#include <iostream>

char* convert(void* pointer) {
	return static_cast<char*>(pointer);
}

int main()
{
	char text[] = "Hello World";

	void* pointer = text;

	char* result = convert(pointer);

	std::cout << result << '\n';
}
