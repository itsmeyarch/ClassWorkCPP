#include <iostream>
#include <string>

class Student
{
private:
    std::string name;
    int age;

public:
    Student()
    {
        name = "";
        age = 0;
    }

    Student(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void inputData()
    {
        std::cout << "Enter student name: ";
        std::getline(std::cin, name);

        std::cout << "Enter student age: ";
        std::cin >> age;
        std::cin.ignore();
    }

    void showData()
    {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
    }

    std::string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }
};

class Group
{
private:
    std::string groupName;
    Student* students;
    int count;

public:
    Group()
    {
        groupName = "Unknown";
        students = nullptr;
        count = 0;
    }

    Group(std::string name)
    {
        groupName = name;
        students = nullptr;
        count = 0;
    }

    ~Group()
    {
        delete[] students;
    }

    void addStudent()
    {
        Student* newStudents = new Student[count + 1];

        for (int i = 0; i < count; i++)
            newStudents[i] = students[i];

        newStudents[count].inputData();

        delete[] students;
        students = newStudents;
        count++;

        std::cout << "Student added\n";
    }

    void removeStudent()
    {
        if (count == 0)
        {
            std::cout << "Group is empty\n";
            return;
        }

        showStudents();

        int index;
        std::cout << "Enter student number to remove: ";
        std::cin >> index;

        if (index < 1 || index > count)
        {
            std::cout << "Invalid number\n";
            return;
        }

        Student* newStudents = nullptr;

        if (count > 1)
            newStudents = new Student[count - 1];

        int j = 0;

        for (int i = 0; i < count; i++)
        {
            if (i != index - 1)
            {
                newStudents[j] = students[i];
                j++;
            }
        }

        delete[] students;
        students = newStudents;
        count--;

        std::cout << "Student removed\n";
    }

    void showStudents()
    {
        std::cout << "\nGroup: " << groupName << "\n";

        if (count == 0)
        {
            std::cout << "No students\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            std::cout << "\nStudent " << i + 1 << ":\n";
            students[i].showData();
        }
    }

    void setGroupName(std::string name)
    {
        groupName = name;
    }

    std::string getGroupName()
    {
        return groupName;
    }

    int getCount()
    {
        return count;
    }
};

int main()
{
    Group* group = nullptr;
    int choice;

    do
    {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1. Create new group\n";
        std::cout << "2. Add student\n";
        std::cout << "3. Remove student\n";
        std::cout << "4. Show students\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";

        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
        {
            delete group;

            std::string name;
            std::cout << "Enter group name: ";
            std::getline(std::cin, name);

            group = new Group(name);

            std::cout << "Group created\n";
            break;
        }

        case 2:
            if (group != nullptr)
                group->addStudent();
            else
                std::cout << "Create a group first\n";
            break;

        case 3:
            if (group != nullptr)
                group->removeStudent();
            else
                std::cout << "Create a group first\n";
            break;

        case 4:
            if (group != nullptr)
                group->showStudents();
            else
                std::cout << "Create a group first\n";
            break;

        case 0:
            std::cout << "Exit\n";
            break;

        default:
            std::cout << "Wrong choice\n";
        }

    } while (choice != 0);

    delete group;
}