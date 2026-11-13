#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    size_t length;

public:
    String() : str(new char[1] {'\0'}), length(0) {}

    String(const char* s) {
        if (s) {
            length = std::strlen(s);
            str = new char[length + 1];
            std::strcpy(str, s);
        }
        else {
            length = 0;
            str = new char[1] {'\0'};
        }
    }

    String(const String& other) : length(other.length) {
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    String(String&& other) noexcept : str(other.str), length(other.length) {
        other.str = nullptr;
        other.length = 0;
    }

    ~String() {
        delete[] str;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] str;
            str = other.str;
            length = other.length;
            other.str = nullptr;
            other.length = 0;
        }
        return *this;
    }

    size_t size() const {
        return length;
    }

    const char* c_str() const {
        return str ? str : "";
    }

    void print() const {
        if (str) {
            std::cout << str << "\n";
        }
    }
};

enum class ItemClass {
    Weapon,
    Potion,
    Food,
    None
};

class Item {
private:
    String name;
    ItemClass itemClass;

public:
    Item() : name(""), itemClass(ItemClass::None) {}

    Item(const String& n, ItemClass ic) : name(n), itemClass(ic) {}

    Item(const char* n, ItemClass ic) : name(n), itemClass(ic) {}

    const String& getName() const {
        return name;
    }

    ItemClass getItemClass() const {
        return itemClass;
    }

    void print() const {
        std::cout << "Назва: " << name.c_str() << ", Клас: ";
        switch (itemClass) {
        case ItemClass::Weapon: std::cout << "Weapon"; break;
        case ItemClass::Potion: std::cout << "Potion"; break;
        case ItemClass::Food: std::cout << "Food"; break;
        case ItemClass::None: std::cout << "None"; break;
        }
        std::cout << "\n";
    }
};

class Inventory {
private:
    int size;
    Item* items;

public:
    Inventory(int s) : size(s) {
        if (size > 0) {
            items = new Item[size];
        }
        else {
            size = 0;
            items = nullptr;
        }
    }

    Inventory(const Inventory& other) : size(other.size) {
        if (size > 0 && other.items) {
            items = new Item[size];
            for (int i = 0; i < size; ++i) {
                items[i] = other.items[i];
            }
        }
        else {
            size = 0;
            items = nullptr;
        }
    }

    ~Inventory() {
        delete[] items;
    }

    Inventory& operator=(const Inventory& other) {
        if (this != &other) {
            delete[] items;
            size = other.size;
            if (size > 0 && other.items) {
                items = new Item[size];
                for (int i = 0; i < size; ++i) {
                    items[i] = other.items[i];
                }
            }
            else {
                size = 0;
                items = nullptr;
            }
        }
        return *this;
    }

    void setItem(int index, const Item& item) {
        if (index >= 0 && index < size) {
            items[index] = item;
        }
    }

    void print() const {
        std::cout << "Інвентар (розмір: " << size << "):\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "  [" << i << "] ";
            items[i].print();
        }
    }
};

int main() {
    Inventory inv(3);

    inv.setItem(0, Item("Меч", ItemClass::Weapon));
    inv.setItem(1, Item("Зілля лікування", ItemClass::Potion));
    inv.setItem(2, Item("Яблуко", ItemClass::Food));

    inv.print();

    std::cout << "\n--- Перевірка конструктора копіювання Inventory ---\n";
    Inventory invCopy = inv;
    invCopy.setItem(0, Item("Кинджал", ItemClass::Weapon));

    std::cout << "Оригінал:\n";
    inv.print();

    std::cout << "\nКопія:\n";
    invCopy.print();
}