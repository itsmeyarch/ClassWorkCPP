#include <iostream>
#include <cmath>
#include <string>
#include <limits>

// Task 1

struct Point {
    double x;
    double y;
};

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return std::sqrt(dx * dx + dy * dy);
}

void task1() {
    Point a, b;

    std::cout << "Enter coordinates of the first point: ";
    std::cin >> a.x >> a.y;

    std::cout << "Enter coordinates of the second point: ";
    std::cin >> b.x >> b.y;

    std::cout << "Distance: " << distance(a, b) << "\n";
}

// Task 2

struct Fraction {
    int numerator;
    int denominator;
};

int gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

Fraction simplify(Fraction f) {
    if (f.denominator < 0) {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }

    int d = gcd(f.numerator, f.denominator);

    f.numerator /= d;
    f.denominator /= d;

    return f;
}

Fraction addFractions(Fraction a, Fraction b) {
    Fraction result;

    result.numerator = a.numerator * b.denominator +
        b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;

    return simplify(result);
}

Fraction subtractFractions(Fraction a, Fraction b) {
    Fraction result;

    result.numerator = a.numerator * b.denominator -
        b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;

    return simplify(result);
}

Fraction multiplyFractions(Fraction a, Fraction b) {
    Fraction result;

    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;

    return simplify(result);
}

Fraction divideFractions(Fraction a, Fraction b) {
    Fraction result;

    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;

    return simplify(result);
}

void printFraction(Fraction f) {
    f = simplify(f);

    int whole = f.numerator / f.denominator;
    int remainder = std::abs(f.numerator % f.denominator);

    if (remainder == 0) {
        std::cout << whole;
    }
    else if (whole != 0) {
        std::cout << whole << " " << remainder << "/" << f.denominator;
    }
    else {
        std::cout << f.numerator << "/" << f.denominator;
    }

    std::cout << "\n";
}

void task2() {
    Fraction a, b;

    std::cout << "Enter first fraction (numerator denominator): ";
    std::cin >> a.numerator >> a.denominator;

    std::cout << "Enter second fraction (numerator denominator): ";
    std::cin >> b.numerator >> b.denominator;

    if (a.denominator == 0 || b.denominator == 0) {
        std::cout << "Denominator cannot be zero\n";
        return;
    }

    a = simplify(a);
    b = simplify(b);

    std::cout << "Sum: ";
    printFraction(addFractions(a, b));

    std::cout << "Difference: ";
    printFraction(subtractFractions(a, b));

    std::cout << "Multiplication: ";
    printFraction(multiplyFractions(a, b));

    if (b.numerator != 0) {
        std::cout << "Division: ";
        printFraction(divideFractions(a, b));
    }
    else {
        std::cout << "Division by zero is impossible\n";
    }
}

// Task 3

struct WashingMachine {
    std::string brand;
    std::string color;
    double width;
    double length;
    double height;
    int power;
    int spinSpeed;
    int temperature;
};

void task3() {
    WashingMachine machine;

    std::cout << "Enter brand: ";
    std::cin >> machine.brand;

    std::cout << "Enter color: ";
    std::cin >> machine.color;

    std::cout << "Enter width: ";
    std::cin >> machine.width;

    std::cout << "Enter length: ";
    std::cin >> machine.length;

    std::cout << "Enter height: ";
    std::cin >> machine.height;

    std::cout << "Enter power: ";
    std::cin >> machine.power;

    std::cout << "Enter spin speed: ";
    std::cin >> machine.spinSpeed;

    std::cout << "Enter heating temperature: ";
    std::cin >> machine.temperature;

    std::cout << "\nWashing machine information:\n";
    std::cout << "Brand: " << machine.brand << "\n";
    std::cout << "Color: " << machine.color << "\n";
    std::cout << "Width: " << machine.width << "\n";
    std::cout << "Length: " << machine.length << "\n";
    std::cout << "Height: " << machine.height << "\n";
    std::cout << "Power: " << machine.power << " W\n";
    std::cout << "Spin speed: " << machine.spinSpeed << " rpm\n";
    std::cout << "Temperature: " << machine.temperature << " C\n";
}

// Task 4

struct Animal {
    std::string name;
    std::string species;
    std::string nickname;
};

void fillAnimal(Animal& animal) {
    std::cout << "Enter animal name: ";
    std::cin >> animal.name;

    std::cout << "Enter species: ";
    std::cin >> animal.species;

    std::cout << "Enter nickname: ";
    std::cin >> animal.nickname;
}

void printAnimal(const Animal& animal) {
    std::cout << "Name: " << animal.name << "\n";
    std::cout << "Species: " << animal.species << "\n";
    std::cout << "Nickname: " << animal.nickname << "\n";
}

void makeSound(Animal animal) {
    if (animal.species == "dog") {
        std::cout << animal.nickname << ": Woof!\n";
    }
    else if (animal.species == "cat") {
        std::cout << animal.nickname << ": Meow!\n";
    }
    else if (animal.species == "cow") {
        std::cout << animal.nickname << ": Moo!\n";
    }
    else if (animal.species == "duck") {
        std::cout << animal.nickname << ": Quack!\n";
    }
    else {
        std::cout << animal.nickname << " makes a sound\n";
    }
}

void task4() {
    Animal animal;

    fillAnimal(animal);
    printAnimal(animal);
    makeSound(animal);
}

// Task 5

union Number {
    int signedNumber;
    unsigned int unsignedNumber;
};

void task5() {
    Number number;

    std::cout << "Enter an integer: ";
    std::cin >> number.signedNumber;

    std::cout << "Signed value: " << number.signedNumber << "\n";
    std::cout << "Unsigned value: " << number.unsignedNumber << "\n";

    std::cout << "Enter an unsigned integer: ";
    std::cin >> number.unsignedNumber;

    std::cout << "Unsigned value: " << number.unsignedNumber << "\n";
    std::cout << "Signed value: " << number.signedNumber << "\n";
}

// Task 6

struct Student {
    std::string surname;
    std::string name;
    std::string patronymic;

    unsigned int grade1 : 1;
    unsigned int grade2 : 1;
    unsigned int grade3 : 1;
    unsigned int grade4 : 1;
    unsigned int grade5 : 1;
    unsigned int grade6 : 1;
    unsigned int grade7 : 1;
    unsigned int grade8 : 1;
    unsigned int grade9 : 1;
    unsigned int grade10 : 1;
};

void setGrade(Student& student, int index, unsigned int value) {
    switch (index) {
    case 0: student.grade1 = value; break;
    case 1: student.grade2 = value; break;
    case 2: student.grade3 = value; break;
    case 3: student.grade4 = value; break;
    case 4: student.grade5 = value; break;
    case 5: student.grade6 = value; break;
    case 6: student.grade7 = value; break;
    case 7: student.grade8 = value; break;
    case 8: student.grade9 = value; break;
    case 9: student.grade10 = value; break;
    }
}

unsigned int getGrade(const Student& student, int index) {
    switch (index) {
    case 0: return student.grade1;
    case 1: return student.grade2;
    case 2: return student.grade3;
    case 3: return student.grade4;
    case 4: return student.grade5;
    case 5: return student.grade6;
    case 6: return student.grade7;
    case 7: return student.grade8;
    case 8: return student.grade9;
    case 9: return student.grade10;
    }

    return 0;
}

void fillStudent(Student& student) {
    std::cout << "Enter surname: ";
    std::cin >> student.surname;

    std::cout << "Enter name: ";
    std::cin >> student.name;

    std::cout << "Enter patronymic: ";
    std::cin >> student.patronymic;

    for (int i = 0; i < 10; i++) {
        setGrade(student, i, 0);
    }
}

void printStudent(const Student& student) {
    std::cout << student.surname << " "
        << student.name << " "
        << student.patronymic << "\n";

    int passed = 0;

    for (int i = 0; i < 10; i++) {
        unsigned int grade = getGrade(student, i);

        std::cout << "Subject " << i + 1 << ": "
            << (grade ? "Passed" : "Failed") << "\n";

        passed += grade;
    }

    std::cout << "Average grade: " << passed / 10.0 << "\n";
}

void printStudentList(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        std::cout << i + 1 << ". "
            << students[i].surname << " "
            << students[i].name << " "
            << students[i].patronymic << "\n";
    }
}

void task6() {
    Student student;
    fillStudent(student);

    std::cout << "\nStudent information:\n";
    printStudent(student);

    Student students[100];
    int count = 0;
    int choice;

    do {
        std::cout << "\n1. Add student\n";
        std::cout << "2. Set student grades\n";
        std::cout << "3. Show student list\n";
        std::cout << "4. Show grades of a student\n";
        std::cout << "5. Show students with failed subjects\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (count < 100) {
                fillStudent(students[count]);
                count++;
            }
            else {
                std::cout << "Student list is full\n";
            }
            break;

        case 2: {
            int index;

            if (count == 0) {
                std::cout << "No students\n";
                break;
            }

            printStudentList(students, count);

            std::cout << "Enter student number: ";
            std::cin >> index;

            if (index < 1 || index > count) {
                std::cout << "Invalid student number\n";
                break;
            }

            for (int i = 0; i < 10; i++) {
                int grade;

                std::cout << "Subject " << i + 1
                    << " (1 - passed, 0 - failed): ";
                std::cin >> grade;

                if (grade != 0 && grade != 1) {
                    grade = 0;
                }

                setGrade(students[index - 1], i, grade);
            }
            break;
        }

        case 3:
            printStudentList(students, count);
            break;

        case 4: {
            int index;

            if (count == 0) {
                std::cout << "No students\n";
                break;
            }

            printStudentList(students, count);

            std::cout << "Enter student number: ";
            std::cin >> index;

            if (index >= 1 && index <= count) {
                printStudent(students[index - 1]);
            }
            else {
                std::cout << "Invalid student number\n";
            }
            break;
        }

        case 5:
            for (int i = 0; i < count; i++) {
                bool hasFailed = false;

                for (int j = 0; j < 10; j++) {
                    if (getGrade(students[i], j) == 0) {
                        hasFailed = true;
                        break;
                    }
                }

                if (hasFailed) {
                    std::cout << students[i].surname << " "
                        << students[i].name << " "
                        << students[i].patronymic << "\n";
                }
            }
            break;

        case 0:
            break;

        default:
            std::cout << "Invalid choice\n";
        }

    } while (choice != 0);
}

// Main

int main() {
    int choice;

    do {
        std::cout << "\n1. Distance between points\n";
        std::cout << "2. Fraction operations\n";
        std::cout << "3. Washing machine\n";
        std::cout << "4. Animal\n";
        std::cout << "5. Union of integers\n";
        std::cout << "6. Students and grades\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose task: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 0);
}