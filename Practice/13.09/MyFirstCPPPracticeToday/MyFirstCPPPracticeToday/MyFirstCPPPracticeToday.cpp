
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <utility>

class Subscriber {
private:
    char* name;
    std::string homePhone;
    std::string workPhone;
    std::string mobilePhone;
    std::string additionalInfo;

public:
    Subscriber() : name(new char[1]), homePhone(""), workPhone(""),
        mobilePhone(""), additionalInfo("") {
        name[0] = '\0';
    }

    Subscriber(std::string n, std::string home, std::string work,
        std::string mobile, std::string info)
        : homePhone(home), workPhone(work),
        mobilePhone(mobile), additionalInfo(info) {
        name = new char[n.length() + 1];
        strcpy(name, n.c_str());
    }

    Subscriber(const Subscriber& other)
        : homePhone(other.homePhone), workPhone(other.workPhone),
        mobilePhone(other.mobilePhone), additionalInfo(other.additionalInfo) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    Subscriber& operator=(const Subscriber& other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            homePhone = other.homePhone;
            workPhone = other.workPhone;
            mobilePhone = other.mobilePhone;
            additionalInfo = other.additionalInfo;
        }
        return *this;
    }

    Subscriber(Subscriber&& other) noexcept
        : name(other.name),
        homePhone(std::move(other.homePhone)),
        workPhone(std::move(other.workPhone)),
        mobilePhone(std::move(other.mobilePhone)),
        additionalInfo(std::move(other.additionalInfo)) {
        other.name = nullptr;
    }

    Subscriber& operator=(Subscriber&& other) noexcept {
        if (this != &other) {
            delete[] name;
            name = other.name;
            other.name = nullptr;
            homePhone = std::move(other.homePhone);
            workPhone = std::move(other.workPhone);
            mobilePhone = std::move(other.mobilePhone);
            additionalInfo = std::move(other.additionalInfo);
        }
        return *this;
    }

    ~Subscriber() {
        delete[] name;
    }

    inline std::string getName() const {
        return name ? name : "";
    }

    inline void show() const {
        std::cout << "\nName: " << getName() << "\n";
        std::cout << "Home phone: " << homePhone << "\n";
        std::cout << "Work phone: " << workPhone << "\n";
        std::cout << "Mobile phone: " << mobilePhone << "\n";
        std::cout << "Additional information: " << additionalInfo << "\n";
    }

    void save(std::ofstream& file) const {
        file << std::quoted(getName()) << "\n"
            << std::quoted(homePhone) << "\n"
            << std::quoted(workPhone) << "\n"
            << std::quoted(mobilePhone) << "\n"
            << std::quoted(additionalInfo) << "\n";
    }

    void load(std::ifstream& file) {
        std::string n;

        file >> std::quoted(n)
            >> std::quoted(homePhone)
            >> std::quoted(workPhone)
            >> std::quoted(mobilePhone)
            >> std::quoted(additionalInfo);

        if (file) {
            delete[] name;
            name = new char[n.length() + 1];
            strcpy(name, n.c_str());
        }
    }
};

class PhoneBook {
private:
    std::vector<Subscriber> subscribers;

public:
    PhoneBook() : subscribers{} {}

    void addSubscriber() {
        std::string name, home, work, mobile, info;

        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        std::cout << "Home phone: ";
        std::getline(std::cin, home);

        std::cout << "Work phone: ";
        std::getline(std::cin, work);

        std::cout << "Mobile phone: ";
        std::getline(std::cin, mobile);

        std::cout << "Additional information: ";
        std::getline(std::cin, info);

        subscribers.emplace_back(name, home, work, mobile, info);

        std::cout << "Subscriber added!\n";
    }

    void deleteSubscriber() {
        std::string name;

        std::cout << "Enter name to delete: ";
        std::getline(std::cin, name);

        for (int i = 0; i < subscribers.size(); i++) {
            if (subscribers[i].getName() == name) {
                subscribers.erase(subscribers.begin() + i);
                std::cout << "Subscriber deleted!\n";
                return;
            }
        }

        std::cout << "Subscriber not found!\n";
    }

    void searchSubscriber() const {
        std::string name;
        bool found = false;

        std::cout << "Enter name to search: ";
        std::getline(std::cin, name);

        for (const auto& subscriber : subscribers) {
            if (subscriber.getName().find(name) != std::string::npos) {
                subscriber.show();
                found = true;
            }
        }

        if (!found) {
            std::cout << "Subscriber not found!\n";
        }
    }

    void showAll() const {
        if (subscribers.empty()) {
            std::cout << "Phone book is empty!\n";
            return;
        }

        for (const auto& subscriber : subscribers) {
            subscriber.show();
        }
    }

    void saveToFile() const {
        std::ofstream file("phonebook.txt");

        if (!file.is_open()) {
            std::cout << "Error opening file!\n";
            return;
        }

        for (const auto& subscriber : subscribers) {
            subscriber.save(file);
        }

        file.close();

        std::cout << "Data saved to file!\n";
    }

    void loadFromFile() {
        std::ifstream file("phonebook.txt");

        if (!file.is_open()) {
            std::cout << "Error opening file!\n";
            return;
        }

        subscribers.clear();

        while (file.peek() != EOF) {
            Subscriber subscriber;
            subscriber.load(file);

            if (file) {
                subscribers.push_back(std::move(subscriber));
            }
        }

        file.close();

        std::cout << "Data loaded from file!\n";
    }
};

int main() {
    PhoneBook book;
    int choice;

    do {
        std::cout << "\n===== PHONE BOOK =====\n";
        std::cout << "1. Add subscriber\n";
        std::cout << "2. Delete subscriber\n";
        std::cout << "3. Search subscriber\n";
        std::cout << "4. Show all subscribers\n";
        std::cout << "5. Save to file\n";
        std::cout << "6. Load from file\n";
        std::cout << "0. Exit\n";
        std::cout << "Your choice: ";

        std::cin >> choice;
        std::cin.ignore(10000, '\n');

        switch (choice) {
        case 1:
            book.addSubscriber();
            break;

        case 2:
            book.deleteSubscriber();
            break;

        case 3:
            book.searchSubscriber();
            break;

        case 4:
            book.showAll();
            break;

        case 5:
            book.saveToFile();
            break;

        case 6:
            book.loadFromFile();
            break;

        case 0:
            std::cout << "Program finished!\n";
            break;

        default:
            std::cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}
