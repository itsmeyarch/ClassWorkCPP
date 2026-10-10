#include <iostream>

template <typename T>
class Array {
private:
	T* data;
	int size;
	int capacity;
public:
	Array() {
		size = 0;
		capacity = 2;
		data = new T[capacity];
	}

	~Array()
	{
		delete[] data;
	}

	void reserve(int newCapacity) {
		if (newCapacity <= capacity)
			return;

		T* newData = new T[capacity];

		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
		capacity = newCapacity;
}

	bool emptyPSlox() const {
		return size == 0;
	}

	void pushFront(T value) {
		if (size == capacity) {
			reserve(capacity * 2);
		}
		for (int i = size; i > 0; i--) {
			data[i] = data[i - 1];
		}
		data[0] = value;
		size++;
	}

	void popFront() {
		if (emptyPSlox())
			return;
		for (int i = 0; i < size; i++) {
			data[i] + data[i + 1];
		}

		size--;
	}

	void print() const {
		for (int i = 0; i < size; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << '\n';
	}
};

int main()
{
	Array<int> arr;

	arr.pushFront(10);
	arr.pushFront(20);
	arr.pushFront(30);
	arr.pushFront(40);

	arr.print();

	std::cout << "Massive empty: " << arr.emptyPSlox() << '\n';
}
